#ifndef HUMANOPERATOR_H
#define HUMANOPERATOR_H

#include "WPILib.h"
#include "../systems/Climber.h"
#include "../systems/Shooter.h"
#include "../util/GamepadF310.h"

class HumanOperator
{
  public:
    HumanOperator();
    void Operate(Climber *climber, Shooter *shooter);

  private:
    GamepadF310 controller;
    bool lastTrigger;
    bool lastShooterEnable;
};

#endif
