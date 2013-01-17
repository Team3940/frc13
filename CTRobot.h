#ifndef CTROBOT_H
#define CTROBOT_H

#include "WPILib.h"
#include "connections.h"
#include "web/WebServer.h"
#include "vision/GoalFinder.h"

class CTRobot : public SimpleRobot
{
  private:
    GoalFinder *goalFinder;
    WebServer *webServer;
    DriverStation *ds;

    Talon *leftFrontDrive;
    Talon *rightFrontDrive;
    Talon *leftRearDrive;
    Talon *rightRearDrive;

  public:
    CTRobot();
    void Autonomous();
    void OperatorControl();
};

#endif
