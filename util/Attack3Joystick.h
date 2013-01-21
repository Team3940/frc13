#ifndef ATTACK3JOYSTICK_H
#define ATTACK3JOYSTICK_H

#include "WPILib.h"

class Attack3Joystick
{
  public:
    Attack3Joystick(int port);
    float GetY();

  private:
    DriverStation *ds;
    int port;
};

#endif
