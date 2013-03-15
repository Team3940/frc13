#include "CTRobot.h"
#include "web/HttpVisionHandler.h"

CTRobot::CTRobot()
{
  // initialize systems
  drivetrain = new Drivetrain();
  climber = new Climber();
  shooter = new Shooter();

  // initialize controllers
  driver = new HumanDriver();
  oper = new HumanOperator();

  //goalFinder = new GoalFinder("10.39.40.11");
  //goalFinder->Start();

  webServer = new WebServer();

  lcd = DriverStationLCD::GetInstance();

  //HttpVisionHandler *visionHandler = new HttpVisionHandler(goalFinder);
  //webServer->SetRequestHandler("/camera", visionHandler);
  
  /*
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
  */
  baseCmd = new DelayCommand(15);
  std::cout << baseCmd->ToString() << std::endl;
}

CTRobot::~CTRobot()
{
  delete drivetrain;
  delete climber;
  delete shooter;
  delete driver;
  delete goalFinder;
  delete webServer;
  delete baseCmd;
}

void CTRobot::UpdateSubsystems()
{
  drivetrain->Update();
  climber->Update();
  shooter->Update();
}

void CTRobot::UpdateDashboard()
{
  lcd->PrintfLine(DriverStationLCD::kUser_Line1, "Test data");
  lcd->PrintfLine(DriverStationLCD::kUser_Line2, "Angle:  %f", climber->GetHingeAngle());
  lcd->PrintfLine(DriverStationLCD::kUser_Line3, "Conveyor:  %f", climber->GetConveyorPosition());

  switch (shooter->GetCommandedDeployState()) {
    case STOWED:    lcd->PrintfLine(DriverStationLCD::kUser_Line4, "Shooter Command:  Stowed");
                    break;
    case DEPLOYED:  lcd->PrintfLine(DriverStationLCD::kUser_Line4, "Shooter Command:  Deployed");
                    break;
    case TRANSIT:   lcd->PrintfLine(DriverStationLCD::kUser_Line4, "Shooter Command:  Transit");
                    break;
    default:        lcd->PrintfLine(DriverStationLCD::kUser_Line4, "Shooter Command:  Unknown");
                    break;
  }

  switch (shooter->GetActualDeployState()) {
    case STOWED:    lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Shooter Position:  Stowed");
                    break;
    case DEPLOYED:  lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Shooter Position:  Deployed");
                    break;
    case TRANSIT:   lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Shooter Position:  Transit");
                    break;
    default:        lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Shooter Position:  Unknown");
                    break;
  }

  lcd->UpdateLCD();
}

void CTRobot::Autonomous()
{
  baseCmd->Reset();
  while (IsAutonomous()) {
    baseCmd->Run();
    UpdateSubsystems();
    UpdateDashboard();
    Wait(0.005);
  }
}

void CTRobot::Disabled()
{
  while (IsDisabled()) {
    UpdateDashboard();
    Wait(0.010);
  }
}

void CTRobot::OperatorControl()
{
  while (IsOperatorControl())
  {
    driver->Drive(drivetrain);
    oper->Operate(climber, shooter);
    UpdateSubsystems();
    UpdateDashboard();

    Wait(0.005);
  }
}

void CTRobot::RobotInit()
{
  // do nothing
}

START_ROBOT_CLASS(CTRobot);
