#include "Shooter.h"

Shooter::Shooter() :
      shooter(PWM_SHOOTER),
      frisbeeAdvance(PWM_SHOOTER_FRISBEE_ADVANCE),
      deploy(PWM_SHOOTER_DEPLOY),
      frisbeeFollower(PWM_FRISBEE_FOLLOWER),
      shooterEncoder(DIO_ENCODER_SHOOTER_A, DIO_ENCODER_SHOOTER_B),
      deploySwitch(DIO_SWITCH_SHOOTER_DEPLOY),
      stowSwitch(DIO_SWITCH_SHOOTER_STOW),
      frisbeeAdvanceReference(DIO_SHOOTER_FRISBEE_ADVANCE_REF)
{
  lastFrisbeeAdvance = frisbeeAdvanceReference.Get();
  commandedDeployState = TRANSIT;
  shoot = false;
  enable = false;
  follower = true;
}

ShooterDeployState Shooter::GetCommandedDeployState()
{
  return commandedDeployState;
}

ShooterDeployState Shooter::GetActualDeployState()
{
  if (deploySwitch.Get()) {
    return DEPLOYED;
  } else if (stowSwitch.Get()) {
    return STOWED;
  } else {
    return TRANSIT;
  }
}

void Shooter::Shoot()
{
  shoot = true;
}

void Shooter::StowShooter()
{
  commandedDeployState = STOWED;
}

void Shooter::DeployShooter()
{
  commandedDeployState = DEPLOYED;
}

void Shooter::ToggleShooterEnable()
{
  enable = !enable;
}

void Shooter::ToggleFollowerEnable()
{
  follower = !follower;
}

void Shooter::SetShooterEnable(bool enable)
{
  this->enable = enable;
}

bool Shooter::GetShooterEnable()
{
  return enable;
}

void Shooter::Update()
{
  bool currentFrisbeeAdvance = frisbeeAdvanceReference.Get();

  shooter.Set(enable ? -1 : 0);

  // frisbee advance
  if (lastFrisbeeAdvance && !currentFrisbeeAdvance) {
    shoot = false;
  }
  if (shoot) {
      frisbeeAdvance.Set(-1);
  } else {
    frisbeeAdvance.Set(0);
  }

  // shooter deployment
  if (commandedDeployState != GetActualDeployState()) {
    switch (commandedDeployState) {
      case STOWED:
        deploy.Set(-1);
        break;
      case DEPLOYED:
        deploy.Set(1);
        break;
      default:
        deploy.Set(0);
        break;
    }
  } else {
    deploy.Set(0);
  }

  // frisbee follower
  frisbeeFollower.Set(follower ? -1 : 1);

  lastFrisbeeAdvance = currentFrisbeeAdvance;
}
