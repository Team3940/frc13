#include "HumanOperator.h"

HumanOperator::HumanOperator() : controller(2)
{
}

void HumanOperator::Operate(Climber *climber)
{
  climber->SetThrottles(controller.GetLeftY(), controller.GetRightY());
}
