#include "CTRobot.h"
#include "web/HttpVisionHandler.h"

CTRobot::CTRobot()
{
  // initialize systems
  drivetrain = new Drivetrain();
  climber = new Climber();

  // initialize controllers
  driver = new HumanDriver();
  oper = new HumanOperator();

  //goalFinder = new GoalFinder("10.39.40.11");
  //goalFinder->Start();

  webServer = new WebServer();

  //HttpVisionHandler *visionHandler = new HttpVisionHandler(goalFinder);
  //webServer->SetRequestHandler("/camera", visionHandler);

  SequentialCommand *seqCmd = new SequentialCommand();
  *seqCmd << new DriveCommand(drivetrain, 4, 0.21, 0.21)
          << new DelayCommand(1)
          << new DriveCommand(drivetrain, 5, -0.22, -0.22)
          << new DelayCommand(1)
          << new DriveCommand(drivetrain, 5, -0.23, -0.23)
          << new DelayCommand(1)
          << new DriveCommand(drivetrain, 5, -0.24, -0.24)
          << new DelayCommand(1)
          << new DriveCommand(drivetrain, 5, -0.25, -0.25)
          << new DelayCommand(1)
          << new DriveCommand(drivetrain, 5, -0.26, -0.26);
  baseCmd = seqCmd;
  std::cout << baseCmd->ToString() << std::endl;
}

CTRobot::~CTRobot()
{
  delete drivetrain;
  delete climber;
  delete driver;
  delete goalFinder;
  delete webServer;
  delete baseCmd;
}

void CTRobot::UpdateSubsystems()
{
  drivetrain->Update();
  climber->Update();
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
    oper->Operate(climber);
    UpdateSubsystems();

    Wait(0.005);
  }
}

void CTRobot::RobotInit()
{
  // do nothing
}

START_ROBOT_CLASS(CTRobot);
