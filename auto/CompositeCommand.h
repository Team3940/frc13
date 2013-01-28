#ifndef COMPOSITECOMMAND_H
#define COMPOSITECOMMAND_H

#include "AutoCommand.h"
#include <vector>

/**
 * A CompositeCommand represents a command made up of multiple
 * other commands.
 * 
 * The commands could be executed in order, at the same time,
 * or through some other pattern.  These patterns are implemented in
 * the children of this class (e.g. SequentialCommand and ConcurrentCommand).
 */
class CompositeCommand : public AutoCommand
{
  public:
    virtual ~CompositeCommand();

    virtual void Reset();

    virtual std::string ToString();

    virtual bool Run() = 0;

    /**
     * Adds a command to be executed as a part of this composite command.
     */    
    CompositeCommand& operator << (AutoCommand *cmd);

  protected:
    CompositeCommand();

    std::vector<AutoCommand *> commands; ///< Stores the encapsulated commands.
};

#endif
