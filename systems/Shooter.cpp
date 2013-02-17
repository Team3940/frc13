#include "Shooter.h"

Shooter::Shooter() :
  shooter(PWM_SHOOTER), frisbeeAdvance(PWM_SHOOTER_FRISBEE_ADVANCE),
      deploy(PWM_SHOOTER_DEPLOY),
      shooterEncoder(DIO_ENCODER_SHOOTER_A, DIO_ENCODER_SHOOTER_B),
      deploySwitch(DIO_SWITCH_SHOOTER_DEPLOY),
      stowSwitch(DIO_SWITCH_SHOOTER_STOW)
{
  commandedDeployState = TRANSIT;
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

void Shooter::StowShooter()
{
  commandedDeployState = STOWED;
}

void Shooter::DeployShooter()
{
  commandedDeployState = DEPLOYED;
}

void Shooter::Update()
{
  shooter.Set(0);

  // shooter deploy
  if (commandedDeployState != GetActualDeployState()) {
    switch (commandedDeployState) {
      case STOWED:
        deploy.Set(1);
      case DEPLOYED:
        deploy.Set(-1);
      default:
        deploy.Set(0);
    }
  }
}
