#include "Climber.h"
#include "Talon.h"

Climber::Climber() :
  conveyor(PWM_CONVEYOR),
  hinge(PWM_HINGE),
  conveyorEncoder(DIO_ENCODER_CONVEYOR_A, DIO_ENCODER_CONVEYOR_B),
  hingeEncoder(DIO_ENCODER_HINGE_A, DIO_ENCODER_HINGE_B),
  hingeRatio(0.032356),
  conveyorRatio(23.875 / 35677)
{
  // start encoders...
  conveyorEncoder.Start();
  hingeEncoder.Start();
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
  return conveyorEncoder.GetRaw() * conveyorRatio;
}

float Climber::GetConveyorRate()
{
  return conveyorEncoder.GetRate() * conveyorRatio;
}

float Climber::GetHingeAngle()
{
  return hingeEncoder.GetRaw() * hingeRatio;
}

float Climber::GetHingeRate()
{
  return hingeEncoder.GetRate() * hingeRatio;
}
