#include "AutoOperator.h"

AutoOperator::AutoOperator() : controller(2)
{
}

bool AutoOperator::Test()
{
  return controller.GetButton(1);
}

void AutoOperator::Operate(Climber *climber)
{
  climber->SetConveyorThrottle(0);
  climber->SetHingeThrottle(0.00);
  
  if (controller.GetButton(1)) {
    climber->SetConveyorThrottle(-0.25);
    climber->SetHingeThrottle(-0.25);
  } else {
    climber->SetHingeThrottle(controller.GetLeftY());
    climber->SetConveyorThrottle(controller.GetRightY());
  }
}
