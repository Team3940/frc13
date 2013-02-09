#ifndef HUMANOPERATOR_H
#define HUMANOPERATOR_H

#include "WPILib.h"
#include "../systems/Climber.h"
#include "../util/GamepadF310.h"

class HumanOperator
{
  public:
    HumanOperator();
    void Operate(Climber *climber);

  private:
    GamepadF310 controller;
};

#endif
