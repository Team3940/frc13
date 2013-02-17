#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"
#include "../connections.h"

enum ShooterDeployState
{
  DEPLOYED, STOWED, TRANSIT
};

class Shooter
{
  public:
    Shooter();
    void Update();
    ShooterDeployState GetActualDeployState();
    void StowShooter();
    void DeployShooter();

  private:
    Talon shooter;
    Talon frisbeeAdvance;
    Talon deploy;
    Encoder shooterEncoder;
    DigitalInput deploySwitch;
    DigitalInput stowSwitch;

    ShooterDeployState commandedDeployState;
};

#endif
