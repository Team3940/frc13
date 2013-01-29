#include "HumanDriver.h"

HumanDriver::HumanDriver() : leftStick(1), rightStick(3)
{
}

void HumanDriver::Drive(Drivetrain *drivetrain)
{
  drivetrain->SetThrottles(leftStick.GetY(), rightStick.GetY());
}
