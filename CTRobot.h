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
#include "controllers/AutoOperator.h"
#include "controllers/HumanOperator.h"

class CTRobot : public SimpleRobot
{
  private:
    GoalFinder *goalFinder;
    WebServer *webServer;

    // subsystems
    Drivetrain *drivetrain;
    Climber *climber;
    Shooter *shooter;

    // controllers
    HumanDriver *driver;
    HumanOperator *oper;

    AutoCommand *baseCmd;

    DriverStationLCD *lcd;

    void UpdateSubsystems();
    void UpdateDashboard();

  public:
    CTRobot();
    ~CTRobot();
    void Autonomous();
    void Disabled();
    void OperatorControl();
    void RobotInit();
};

#endif
