#include "ResetClimberPositon.h"
#include <sstream>

ResetClimberPositon::ResetClimberPositon(Climber *climber)
{
  this->climber = climber;
}

ResetClimberPositon::~ResetClimberPositon()
{
}

void ResetClimberPositon::Reset()
{
}

std::string ResetClimberPositon::ToString()
{
  return "Reset shooter position";
}

bool ResetClimberPositon::Run()
{
  climber->Reset();
  return true;
}
