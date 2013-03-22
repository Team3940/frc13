#ifndef RESETCLIMBERPOSITION_H
#define RESETCLIMBERPOSITION_H

#include "AutoCommand.h"
#include "../systems/Climber.h"
#include "WPILib.h"

class ResetClimberPositon : public AutoCommand
{
  public:
    ResetClimberPositon(Climber *climber);

    virtual ~ResetClimberPositon();

    virtual void Reset();

    virtual std::string ToString();

    virtual bool Run();

  private:
    Climber *climber; ///< Used to control the Shooter subsystem
};

#endif
