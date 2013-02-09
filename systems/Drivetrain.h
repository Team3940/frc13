#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
#include "../connections.h"

class Drivetrain
{
  public:
    Drivetrain();
    void Update();
    void SetThrottles(float leftThrottle, float rightThrottle);

  private:
    Talon leftFrontDrive;
    Talon rightFrontDrive;
    Talon leftRearDrive;
    Talon rightRearDrive;

    float leftThrottle;
    float rightThrottle;
};

#endif
