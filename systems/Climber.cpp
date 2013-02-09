#include "Climber.h"
#include "Talon.h"

Climber::Climber() :
  conveyor(PWM_CONVEYOR),
  hinge(PWM_HINGE)
{
}

void Climber::Update()
{
  conveyor.Set(conveyorThrottle);
  hinge.Set(hingeThrottle);
}

void Climber::SetThrottles(float conveyorThrottle, float hingeThrottle)
{
  this->conveyorThrottle = conveyorThrottle;
  this->hingeThrottle = hingeThrottle;
}
