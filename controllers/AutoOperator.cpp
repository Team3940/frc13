#include "AutoOperator.h"

AutoOperator::AutoOperator()
{
}

void AutoOperator::Operate(Climber *climber)
{
  climber->SetConveyorThrottle(0);
  climber->SetHingeThrottle(0);
}
