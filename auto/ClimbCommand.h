#ifndef CLIMBCOMMAND_H
#define CLIMBCOMMAND_H

#include "../auto/AutoCommand.h"
#include "../controllers/AutoOperator.h"
#include "../systems/Climber.h"
#include "WPILib.h"

/**
 * A simple command to drive the robot for a fixed amount of time.
 * Currently, this is simple dead reckoning - run the motors at a
 * certain power for a certain amount of time.
 */
class ClimbCommand : public AutoCommand
{
  public:

    /**
     * Constructs a new ClimbCommand.
     *
     * @param autoCtrl
     * @param hingeAngle hinge angle in degrees
     * @param conveyorDistance conveyor position in inches
     */
    ClimbCommand(AutoOperator *autoCtrl, float hingeAngle, float conveyorDistance);

    virtual ~ClimbCommand();

    virtual void Reset();

    virtual std::string ToString();

    virtual bool Run();

  private:
    AutoOperator *autoCtrl; ///< Used to control the Climber subsystem
    float hingeAngle;
    float conveyorDistance;
};

#endif
