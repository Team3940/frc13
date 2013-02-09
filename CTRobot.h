#ifndef CTROBOT_H
#define CTROBOT_H

#include "WPILib.h"
#include "connections.h"
#include "auto/auto.h"
#include "web/WebServer.h"
#include "vision/GoalFinder.h"
#include "systems/Drivetrain.h"
#include "systems/Climber.h"
#include "controllers/HumanDriver.h"
#include "controllers/HumanOperator.h"

class CTRobot : public SimpleRobot
{
  private:
    GoalFinder *goalFinder;
    WebServer *webServer;

    // subsystems
    Drivetrain *drivetrain;
    Climber *climber;

    // controllers
    HumanDriver *driver;
    HumanOperator *oper;

    AutoCommand *baseCmd;

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
