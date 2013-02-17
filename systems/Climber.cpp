#include "Climber.h"
#include "Talon.h"

Climber::Climber() :
  conveyor(PWM_CONVEYOR),
  hinge(PWM_HINGE),
  conveyorEncoder(DIO_ENCODER_CONVEYOR_A, DIO_ENCODER_CONVEYOR_B),
  hingeEncoder(DIO_ENCODER_HINGE_A, DIO_ENCODER_HINGE_B),
  hingeRatio((1.0 / 71.0) * (14.0 / 12.0))
{
}

void Climber::Update()
{
  conveyor.Set(conveyorThrottle);
  hinge.Set(hingeThrottle);
}

void Climber::SetConveyorThrottle(float conveyorThrottle)
{
  this->conveyorThrottle = conveyorThrottle;
}

void Climber::SetHingeThrottle(float hingeThrottle)
{
  this->hingeThrottle = hingeThrottle;
}

float Climber::GetConveyorPosition()
{
  return conveyorEncoder.GetDistance();
}

float Climber::GetConveyorRate()
{
  return conveyorEncoder.GetRate();
}

float Climber::GetHingeAngle()
{
  return hingeEncoder.GetDistance() * hingeRatio;
}

float Climber::GetHingeRate()
{
  return hingeEncoder.GetRate() * hingeRatio;
}
