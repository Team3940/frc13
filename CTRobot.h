#ifndef CTROBOT_H
#define CTROBOT_H

#include "WPILib.h"
#include "connections.h"
#include "web/WebServer.h"
#include "vision/GoalFinder.h"
#include "systems/Drivetrain.h"
#include "controllers/HumanDriver.h"

class CTRobot : public SimpleRobot
{
  private:
    GoalFinder *goalFinder;
    WebServer *webServer;

    // subsystems
    Drivetrain *drivetrain;

    // controllers
    HumanDriver *driver;

    void UpdateSubsystems();

  public:
    CTRobot();
    ~CTRobot();
    void Autonomous();
    void Disabled();
    void OperatorControl();
    void RobotInit();
};

#endif
