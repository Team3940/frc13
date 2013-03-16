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
    ShooterDeployState GetCommandedDeployState();
    ShooterDeployState GetActualDeployState();
    void Shoot();
    void StowShooter();
    void DeployShooter();
    void ToggleShooterEnable();
    void ToggleFollowerEnable();

  private:
    Talon shooter;
    Talon frisbeeAdvance;
    Talon deploy;
    Servo frisbeeFollower;
    Encoder shooterEncoder;
    DigitalInput deploySwitch;
    DigitalInput stowSwitch;
    DigitalInput frisbeeAdvanceReference;

    ShooterDeployState commandedDeployState;
    bool lastFrisbeeAdvance;
    bool shoot;
    bool follower;
    bool enable;
};

#endif
