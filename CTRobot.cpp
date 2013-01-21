#include "CTRobot.h"
#include "web/HttpVisionHandler.h"

CTRobot::CTRobot()
{
  // initialize systems
  drivetrain = new Drivetrain();

  // initialize controllers
  driver = new HumanDriver();

  goalFinder = new GoalFinder("10.39.40.11");
  goalFinder->Start();

  webServer = new WebServer();

  HttpVisionHandler *visionHandler = new HttpVisionHandler(goalFinder);
  webServer->SetRequestHandler("/camera", visionHandler);
}

CTRobot::~CTRobot()
{
  delete drivetrain;
  delete driver;
  delete goalFinder;
  delete webServer;
}

void CTRobot::UpdateSubsystems()
{
  drivetrain->Update();
}

void CTRobot::Autonomous()
{
  while (IsAutonomous()) {
    UpdateSubsystems();
    Wait(0.005);
  }
}

void CTRobot::Disabled()
{
  // do nothing
}

void CTRobot::OperatorControl()
{
  while (IsOperatorControl())
  {
    driver->Drive(drivetrain);

    UpdateSubsystems();

    Wait(0.005);
  }
}

void CTRobot::RobotInit()
{
  // do nothing
}

START_ROBOT_CLASS(CTRobot);
