#ifndef HUMANDRIVER_H
#define HUMANDRIVER_H

#include "WPILib.h"
#include "../systems/Drivetrain.h"
#include "../util/Attack3Joystick.h"

class HumanDriver
{
  public:
    HumanDriver();
    void Drive(Drivetrain *drivetrain);

  private:
    Attack3Joystick leftStick;
    Attack3Joystick rightStick;
};

#endif
