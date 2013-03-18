#ifndef DEPLOYSHOOTERCOMMAND_H
#define DEPLOYSHOOTERCOMMAND_H

#include "AutoCommand.h"
#include "../systems/Shooter.h"
#include "WPILib.h"

class DeployShooterCommand : public AutoCommand
{
  public:

    DeployShooterCommand(Shooter *shooter);

    virtual ~DeployShooterCommand();

    virtual void Reset();

    virtual std::string ToString();

    virtual bool Run();

  private:
    Shooter *shooter; ///< Used to control the Shooter subsystem
};

#endif
