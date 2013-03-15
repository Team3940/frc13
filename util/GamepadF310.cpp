#include "GamepadF310.h"

GamepadF310::GamepadF310(int port)
{
  ds = DriverStation::GetInstance();
  this->port = port;
}

float GamepadF310::GetLeftX()
{
  return ds->GetStickAxis(port, 1);
}

float GamepadF310::GetLeftY()
{
  return ds->GetStickAxis(port, 2) * -1;
}

float GamepadF310::GetRightX()
{
  return ds->GetStickAxis(port, 3);
}

float GamepadF310::GetRightY()
{
  return ds->GetStickAxis(port, 4) * -1;
}

bool GamepadF310::GetButton(int button)
{
  return (0x1 << (button - 1)) & ds->GetStickButtons(port);
}
