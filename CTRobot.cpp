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
  autoOperator = new AutoOperator(climber);

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
/*
  // auto climb
  SequentialCommand *seqCmd = new SequentialCommand();
  *seqCmd << new ClimbCommand(autoOperator, 96, 18.74)
          << new ClimbCommand(autoOperator, 96, 31.9)
          << new ClimbCommand(autoOperator, 183, 36.75)
          << new ClimbCommand(autoOperator, 253, 38.5)
          << new ClimbCommand(autoOperator, 255, 39.25)
          << new ClimbCommand(autoOperator, 218, 42)
          << new DelayCommand(10);
  baseCmd = seqCmd;
*/
  
  // auto shoot
  
  SequentialCommand *seqCmd = new SequentialCommand();
  *seqCmd << new ResetClimberPositon(climber)
          << new ClimbCommand(autoOperator, 106.375, 12 + 18.74)  // change second number for shooter angle, from 90 degree start
          << new DeployShooterCommand(shooter)
          << new DelayCommand(60);
  baseCmd = seqCmd;

  //std::cout << baseCmd->ToString() << std::endl;
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
  lcd->PrintfLine(DriverStationLCD::kUser_Line1, "Angle:  %f", climber->GetHingeAngle());
  lcd->PrintfLine(DriverStationLCD::kUser_Line2, "Conveyor:  %f", climber->GetConveyorPosition());

  switch (shooter->GetCommandedDeployState()) {
    case STOWED:    lcd->PrintfLine(DriverStationLCD::kUser_Line3, "Stowing shooter");
                    break;
    case DEPLOYED:  lcd->PrintfLine(DriverStationLCD::kUser_Line3, "Deploying shooter");
                    break;
    case TRANSIT:   lcd->PrintfLine(DriverStationLCD::kUser_Line3, "");
                    break;
    default:        lcd->PrintfLine(DriverStationLCD::kUser_Line3, "");
                    break;
  }

  switch (shooter->GetActualDeployState()) {
    case STOWED:    lcd->PrintfLine(DriverStationLCD::kUser_Line4, "Shooter Stowed");
                    break;
    case DEPLOYED:  lcd->PrintfLine(DriverStationLCD::kUser_Line4, "Shooter Deployed");
                    break;
    case TRANSIT:   lcd->PrintfLine(DriverStationLCD::kUser_Line4, "Shooter Transit");
                    break;
    default:        lcd->PrintfLine(DriverStationLCD::kUser_Line4, "Shooter Unknown");
                    break;
  }

  if (shooter->GetShooterEnable()) {
    lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Shooter On");
  } else {
    lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Shooter Off");
  }

  lcd->UpdateLCD();
}

void CTRobot::Autonomous()
{
  baseCmd->Reset();
  while (IsAutonomous()) {
    baseCmd->Run();
    autoOperator->Operate();
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
