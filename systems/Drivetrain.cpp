#include "Drivetrain.h"
#include "Talon.h"

Drivetrain::Drivetrain() :
  leftFrontDrive(PWM_DRIVE_LEFT_FRONT),
  rightFrontDrive(PWM_DRIVE_RIGHT_FRONT),
  leftRearDrive(PWM_DRIVE_LEFT_REAR),
  rightRearDrive(PWM_DRIVE_RIGHT_REAR)
{
}

void Drivetrain::Update()
{
  // multiply the right values by -1, since they are mounted "backwards".
  leftFrontDrive.Set(leftThrottle);
  rightFrontDrive.Set(rightThrottle * -1);
  leftRearDrive.Set(leftThrottle);
  rightRearDrive.Set(rightThrottle * -1);
}

void Drivetrain::SetThrottles(float leftThrottle, float rightThrottle)
{
  this->leftThrottle = leftThrottle;
  this->rightThrottle = rightThrottle;
}
