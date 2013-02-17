#include "Climber.h"
#include "Talon.h"

Climber::Climber() :
  conveyor(PWM_CONVEYOR),
  hinge(PWM_HINGE),
  conveyorEncoder(DIO_ENCODER_CONVEYOR_A, DIO_ENCODER_CONVEYOR_B),
  hingeEncoder(DIO_ENCODER_HINGE_A, DIO_ENCODER_HINGE_B)
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

// hinge encoder is 14:12 speed...
