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
    
    /**
     * Gets the conveyor travel.
     * @returns the conveyor travel in inches.
     */
    float GetConveyorPosition();

    /**
     * Gets the conveyor travel rate.
     * @returns the conveyor travel in inches/sec.
     */
    float GetConveyorRate();

    /**
     * Gets the hinge angle.
     * @returns the hinge angle in degrees.
     */
    float GetHingeAngle();

    /**
     * Gets the hinge angle travel rate.
     * @returns the hinge angle rate of change in degrees/sec.
     */
    float GetHingeRate();

    bool GetHingeRef();
    void Reset();

  private:
    Talon conveyor;
    Talon hinge;
    Encoder conveyorEncoder;
    Encoder hingeEncoder;
    DigitalInput hingeReferenceSwitch;

    float conveyorThrottle;
    float hingeThrottle;
    const float hingeRatio;
    const float conveyorRatio;
};

#endif
