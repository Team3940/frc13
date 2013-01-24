#include "DriveCommand.h"
#include <sstream>

DriveCommand::DriveCommand(Drivetrain *drivetrain, float seconds, float leftThrottle, float rightThrottle)
{
  this->drivetrain = drivetrain;
  this->leftThrottle = leftThrottle;
  this->rightThrottle = rightThrottle;
  timer = new Timer();
  time = seconds;
}

DriveCommand::~DriveCommand()
{
  delete timer;
}

void DriveCommand::Reset()
{
  timer->Stop();
  timer->Reset();
}

std::string DriveCommand::ToString()
{
  ostringstream ss;
  ss << "DriveCommand:  " << leftThrottle << "/";
  ss << rightThrottle << " for " << time << " sec";
  return ss.str();
}

bool DriveCommand::Run()
{
  timer->Start();
  if (timer->Get() > time) {
    drivetrain->SetThrottles(0, 0);
    return true;
  } else {
    drivetrain->SetThrottles(leftThrottle, rightThrottle);
    return false;
  }
}
