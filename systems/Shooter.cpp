#include "Shooter.h"

Shooter::Shooter() : shooter(PWM_SHOOTER)
{
}

void Shooter::Update()
{
  shooter.Set(0);
}
