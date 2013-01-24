#ifndef DELAYCOMMAND_H
#define DELAYCOMMAND_H

#include "AutoCommand.h"
#include "WPILib.h"

/**
 * Delays execution for a fixed period of time.
 */
class DelayCommand : public AutoCommand
{
  public:
    /**
     * Constructs a new DelayCommand with a fixed delay time.
     *
     * @param seconds the number of seconds to delay
     */
    DelayCommand(float seconds);

    virtual ~DelayCommand();

    virtual void Reset();

    virtual std::string ToString();

    virtual bool Run();

  private:
    Timer *timer; ///< Used to determine if the delay time has elapsed
    float time; ///< Amount of time to delay in seconds
};

#endif
