#include "HumanOperator.h"

HumanOperator::HumanOperator() : controller(2)
{
  lastTrigger = false;
  lastShooterEnable = false;
}

void HumanOperator::Operate(Climber *climber, Shooter *shooter)
{
  bool trigger = controller.GetButton(1);
  bool deployShooter = controller.GetButton(2);
  bool stowShooter = controller.GetButton(3);
  bool currentShooterEnable = controller.GetButton(4);
  bool currentFollowerEnable = controller.GetButton(6);

  // reset encoders
  if (controller.GetButton(5)) {
    climber->Reset();
  }

  // climber
  climber->SetHingeThrottle(controller.GetLeftY());
  climber->SetConveyorThrottle(controller.GetRightY());

  // shooter deployment
  if (stowShooter) {
    shooter->StowShooter();
  } else if (deployShooter) {
    shooter->DeployShooter();
  }

  // shooter...shooting
  if (currentShooterEnable && !lastShooterEnable) {
    shooter->ToggleShooterEnable();
  }

  // frisbee follower (compression)
  if (currentFollowerEnable && !lastFollowerEnable) {
    shooter->ToggleFollowerEnable();
  }

  if (trigger) {
    shooter->Shoot();
  }

  lastShooterEnable = currentShooterEnable;
  lastFollowerEnable = currentFollowerEnable;
}
