#include "AutoOperator.h"
#include <cmath>

AutoOperator::AutoOperator(Climber *climber) : controller(2)
{
  this->climber = climber;
  desiredConveyor = 0;
  desiredHingeAngle = 73;
}

void AutoOperator::SetDesiredHingeAngle(float angle)
{
  desiredHingeAngle = angle;
}

void AutoOperator::SetDesiredConveyorDistance(float distance)
{
  desiredConveyor = distance;
}

bool AutoOperator::AtDesiredPosition()
{
  return AtDesiredHingeAngle() && AtDesiredConveyorDistance();
}

bool AutoOperator::AtDesiredHingeAngle()
{
  return fabs(climber->GetHingeAngle() - desiredHingeAngle) < 2.5;
}

bool AutoOperator::AtDesiredConveyorDistance()
{
  return fabs(climber->GetConveyorPosition() - desiredConveyor) < 0.125;
}

void AutoOperator::Operate()
{
  climber->SetHingeThrottle(0);
  climber->SetConveyorThrottle(0);

  // set conveyor throttles
  if (!AtDesiredConveyorDistance()) {
    if (climber->GetConveyorPosition() < desiredConveyor) {
      climber->SetConveyorThrottle(-0.80);
    } else if (climber->GetConveyorPosition() > desiredConveyor) {
      climber->SetConveyorThrottle(0.80);
    }
  }

  // set hinge throttles
  if (!AtDesiredHingeAngle()) {
    if (climber->GetHingeAngle() < desiredHingeAngle) {
      climber->SetHingeThrottle(0.80);
    } else if (climber->GetHingeAngle() > desiredHingeAngle) {
      climber->SetHingeThrottle(-0.80);
    }
  }
}
