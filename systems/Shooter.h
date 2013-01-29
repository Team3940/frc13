#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"
#include "../connections.h"

class Shooter
{
  public:
    Shooter();
    void Update();

  private:
    Talon shooter;
};

#endif
