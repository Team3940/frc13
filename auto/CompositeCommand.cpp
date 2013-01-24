#include "CompositeCommand.h"
#include <sstream>
#include <stdarg.h>

CompositeCommand::CompositeCommand(AutoCommand *cmd, ...)
{
  va_list args;
  va_start(args, cmd);

  while (cmd != NULL) {
    commands.push_back(cmd);
    cmd = va_arg(args, AutoCommand *);
  }
  va_end(args);
}

CompositeCommand::~CompositeCommand()
{
  for (std::vector<AutoCommand *>::const_iterator it = commands.begin();
       it < commands.end();
       ++it) {
    delete *it;
  }
}

void CompositeCommand::Reset()
{
  for (std::vector<AutoCommand *>::iterator iterator = commands.begin();
       iterator != commands.end();
       ++iterator) {
    (*iterator)->Reset();
  }
}

std::string CompositeCommand::ToString()
{
  std::ostringstream ss;
  ss << commands.size() << " commands:" << std::endl;
  for (unsigned int i = 0; i < commands.size(); i++) {
    ss << "  " << commands[i]->ToString() << std::endl;
  }
  return ss.str();
}
