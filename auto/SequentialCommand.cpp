#include "SequentialCommand.h"
#include "AutoCommand.h"
#include <sstream>

SequentialCommand::SequentialCommand(AutoCommand *cmd, ...) : CompositeCommand(cmd)
{
}

SequentialCommand::~SequentialCommand()
{
}

void SequentialCommand::Reset()
{
  CompositeCommand::Reset();
  commandIndex = 0;
}

std::string SequentialCommand::ToString()
{
  std::ostringstream ss;
  ss << "SequentialCommand with " << CompositeCommand::ToString();
  return ss.str();
}

bool SequentialCommand::Run()
{
  if (commandIndex >= (int) commands.size()) {
    return true;
  }
  
  if (commands[commandIndex]->Run()) {
    commandIndex++;
    if (commandIndex == (int) commands.size()) {
      return true;
    }
  }
  return false;
}
