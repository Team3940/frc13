#ifndef CLIMBER_H
#define CLIMBER_H

#include "WPILib.h"
#include "../connections.h"

class Climber
{
  public:
    Climber();
    void Update();
    void SetThrottles(float conveyorThrottle, float hingeThrottle);

  private:
    Talon conveyor;
    Talon hinge;

    float conveyorThrottle;
    float hingeThrottle;
};

#endif