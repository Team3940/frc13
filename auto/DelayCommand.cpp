#include "DelayCommand.h"
#include <sstream>

DelayCommand::DelayCommand(float seconds)
{
  timer = new Timer();
  time = seconds;
}

DelayCommand::~DelayCommand()
{
  delete timer;
}

void DelayCommand::Reset()
{
  timer->Stop();
  timer->Reset();
}

std::string DelayCommand::ToString()
{
  ostringstream ss;
  ss << "DelayCommand:  " << time << " sec delay";
  return ss.str();
}

bool DelayCommand::Run()
{
  timer->Start();
  if (timer->Get() > time) {
    return true;
  } else {
    return false;
  }
}
