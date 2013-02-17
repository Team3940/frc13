#include "HumanOperator.h"

HumanOperator::HumanOperator() : controller(2)
{
}

void HumanOperator::Operate(Climber *climber)
{
  climber->SetHingeThrottle(controller.GetLeftY());
  climber->SetConveyorThrottle(controller.GetRightY());
}
