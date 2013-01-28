#include "CompositeCommand.h"
#include <sstream>
#include <stdarg.h>

CompositeCommand::CompositeCommand()
{
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

CompositeCommand& CompositeCommand::operator << (AutoCommand *cmd)
{
  commands.push_back(cmd);
  return *this;
}
