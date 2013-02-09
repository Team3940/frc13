#ifndef GAMEPADF310_H
#define GAMEPADF310_H

#include "WPILib.h"

class GamepadF310
{
  public:
    GamepadF310(int port);
    float GetLeftX();
    float GetLeftY();
    float GetRightX();
    float GetRightY();

  private:
    DriverStation *ds;
    int port;
};

#endif
