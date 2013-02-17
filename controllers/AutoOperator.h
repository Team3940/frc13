#ifndef AUTOOPERATOR_H
#define AUTOOPERATOR_H

#include "WPILib.h"
#include "../systems/Climber.h"
#include "../util/GamepadF310.h"

class AutoOperator
{
  public:
    AutoOperator();
    void Operate(Climber *climber);
};

#endif
