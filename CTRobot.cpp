#include "CTRobot.h"
#include "web/HttpVisionHandler.h"

CTRobot::CTRobot()
{
  ds = DriverStation::GetInstance();

  leftFrontDrive = new Talon(PWM_DRIVE_LEFT_FRONT);
  rightFrontDrive = new Talon(PWM_DRIVE_RIGHT_FRONT);
  leftRearDrive = new Talon(PWM_DRIVE_LEFT_REAR);
  rightRearDrive = new Talon(PWM_DRIVE_RIGHT_REAR);

  goalFinder = new GoalFinder("10.39.40.11");
  goalFinder->Start();

  webServer = new WebServer();

  HttpVisionHandler *visionHandler = new HttpVisionHandler(goalFinder);
  webServer->SetRequestHandler("/camera", visionHandler);
}

void CTRobot::Autonomous()
{
  // do nothing for now...
}

void CTRobot::OperatorControl()
{
  while (IsOperatorControl())
  {
    leftFrontDrive->Set(ds->GetStickAxis(1, 2) * -1);
    rightFrontDrive->Set(ds->GetStickAxis(1, 4));
    leftRearDrive->Set(ds->GetStickAxis(1, 2) * -1);
    rightRearDrive->Set(ds->GetStickAxis(1, 4));
    Wait(0.005);
  }
}

START_ROBOT_CLASS(CTRobot);
