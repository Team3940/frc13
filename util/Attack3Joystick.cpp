#include "Attack3Joystick.h"

Attack3Joystick::Attack3Joystick(int port)
{
  ds = DriverStation::GetInstance();
  this->port = port;
}

float Attack3Joystick::GetY()
{
  return ds->GetStickAxis(port, 2) * -1;
}
