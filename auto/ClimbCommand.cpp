#include "ClimbCommand.h"
#include <sstream>
#include <cmath>

ClimbCommand::ClimbCommand(Climber *climber, float hingeAngle, float conveyorDistance)
{
  this->climber = climber;
  this->hingeAngle = hingeAngle;
  this->conveyorDistance = conveyorDistance;
  //timer = new Timer();
  //time = seconds;
}

ClimbCommand::~ClimbCommand()
{
  //delete timer;
}

void ClimbCommand::Reset()
{
  //timer->Stop();
  //timer->Reset();
}

std::string ClimbCommand::ToString()
{
  //ostringstream ss;
  //ss << "DriveCommand:  " << leftThrottle << "/";
  //ss << rightThrottle << " for " << time << " sec";
  //return ss.str();
  return "";
}

bool ClimbCommand::Run()
{
  climber->SetHingeThrottle(0);
  climber->SetConveyorThrottle(0);

  if (fabs(climber->GetConveyorPosition() - conveyorDistance) < 0.125) {
    return true;
  }

  if (climber->GetConveyorPosition() < conveyorDistance) {
    climber->SetConveyorThrottle(-0.25);
  } else if (climber->GetConveyorPosition() > conveyorDistance) {
    climber->SetConveyorThrottle(0.25);
  } else {
    return true;
  }
  return false;
}
