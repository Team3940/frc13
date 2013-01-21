#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
#include "../connections.h"

class Drivetrain
{
  public:
    Drivetrain();
    void Update();
    void Drivetrain::SetThrottles(float leftThrottle, float rightThrottle);

  private:
    SpeedController *leftFrontDrive;
    SpeedController *rightFrontDrive;
    SpeedController *leftRearDrive;
    SpeedController *rightRearDrive;

    float leftThrottle;
    float rightThrottle;
};

#endif
