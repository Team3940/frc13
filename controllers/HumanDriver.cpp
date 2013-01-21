#include "HumanDriver.h"

HumanDriver::HumanDriver()
{
  leftStick = new Attack3Joystick(1);
  rightStick = new Attack3Joystick(3);
}

HumanDriver::~HumanDriver()
{
  delete leftStick;
  delete rightStick;
}

void HumanDriver::Drive(Drivetrain *drivetrain)
{
  drivetrain->SetThrottles(leftStick->GetY(), rightStick->GetY());
}
