#ifndef AUTOCOMMAND_H
#define AUTOCOMMAND_H

#include <string>
#include "WPILib.h"

/**
 * An AutoCommand is the most basic class for representing an automated
 * robot action.
 *
 * AutoCommands don't necesarily have to be run in autonomous mode -
 * they can also be used during teleoperated mode for driver assistance.
 */
class AutoCommand
{
  public:
    virtual ~AutoCommand() = 0;

    /**
     * Resets the command; putting it in a state as if it hasn't
     * been executed yet.
     */
    virtual void Reset() = 0;

    /**
     * Executes the command.
     *
     * @returns true if the command is complete, false otherwise
     */
    virtual bool Run() = 0;

    /**
     * Generates a description of the command.
     *
     * @returns human-readable string describing the command
     */
    virtual std::string ToString() = 0;

  protected:
    AutoCommand();
};

#endif
