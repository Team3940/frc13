#ifndef AUTOOPERATOR_H
#define AUTOOPERATOR_H

#include "WPILib.h"
#include "../systems/Climber.h"
#include "../util/GamepadF310.h"

class AutoOperator
{
  public:
    AutoOperator(Climber *climber);
    void Operate();

    void SetDesiredHingeAngle(float angle);
    void SetDesiredConveyorDistance(float distance);

    bool AutoOperator::AtDesiredPosition();
    bool AutoOperator::AtDesiredHingeAngle();
    bool AutoOperator::AtDesiredConveyorDistance();

  private:
    Climber *climber;
    GamepadF310 controller;
    float desiredHingeAngle;
    float desiredConveyor;
};

#endif
