#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H

#include "AutoCommand.h"
#include "../systems/Drivetrain.h"
#include "WPILib.h"

/**
 * A simple command to drive the robot for a fixed amount of time.
 * Currently, this is simple dead reckoning - run the motors at a
 * certain power for a certain amount of time.
 */
class DriveCommand : public AutoCommand
{
  public:

    /**
     * Constructs a new DriveCommand.
     *
     * @param drivetrain A drivetrain object to send commands to
     * @param seconds Number of seconds to drive
     * @param leftThrottle amount of left tank drive to apply (-1 to 1)
     * @param rightThrottle amount of right tank drive to apply (-1 to 1)
     */
    DriveCommand(Drivetrain *drivetrain, float seconds, float leftThrottle, float rightThrottle);

    virtual ~DriveCommand();

    virtual void Reset();

    virtual std::string ToString();

    virtual bool Run();

  private:
    Drivetrain *drivetrain; ///< Used to control the Drivetrain subsystem
    Timer *timer; ///< Used to determine if the delay time has elapsed
    float time; ///< Amount of time to drive in seconds
    float leftThrottle; ///< Amount of leftThrottle to apply (-1 to 1)
    float rightThrottle; ///< Amount of rightThrottle to apply (-1 to 1)
};

#endif
