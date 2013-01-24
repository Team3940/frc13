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

  baseCmd = new SequentialCommand(new DriveCommand(drivetrain, 4, 0.21, 0.21), new DelayCommand(10), new DriveCommand(drivetrain, 5, -0.22, -0.22), NULL);
  std::cout << baseCmd->ToString() << std::endl;
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
  baseCmd->Reset();
  while (IsAutonomous()) {
    baseCmd->Run();
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
