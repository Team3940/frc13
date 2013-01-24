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

  protected:
    /**
     * Constructs a new SequentialCommand made up of one or more
     * AutoCommand objects.  Be sure to terminate the variable argument
     * list with NULL.
     */
    CompositeCommand(AutoCommand *dummy, ...);

    std::vector<AutoCommand *> commands; ///< Stores the encapsulated commands.
};

#endif
