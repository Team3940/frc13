#ifndef CLIMBER_H
#define CLIMBER_H

#include "WPILib.h"
#include "../connections.h"

class Climber
{
  public:
    Climber();
    void Update();
    void SetConveyorThrottle(float conveyorThrottle);
    void SetHingeThrottle(float hingeThrottle);
    
    float GetConveyorPosition();
    float GetConveyorRate();
    float GetHingeAngle();
    float GetHingeRate();

  private:
    Talon conveyor;
    Talon hinge;
    Encoder conveyorEncoder;
    Encoder hingeEncoder;

    float conveyorThrottle;
    float hingeThrottle;
    const float hingeRatio;
};

#endif
