#ifndef SEQUENTIALCOMMAND_H
#define SEQUENTIALCOMMAND_H

#include <vector>
#include "CompositeCommand.h"

/**
 * A SequentialCommand executes a group of AutoCommands in order.

 * Each command is executed in sequence; i.e. the second command won't be
 * executed until the first command has completed.
 */
class SequentialCommand : public CompositeCommand
{
  public:
    /**
     * Constructs a new SequentialCommand made up of one or more
     * AutoCommand objects.  Be sure to terminate the variable argument
     * list with NULL.
     */
    SequentialCommand(AutoCommand *dummy, ...);

    virtual ~SequentialCommand();

    virtual void Reset();

    virtual std::string ToString();

    virtual bool Run();

  private:
    int commandIndex;  ///< Holds the index of the next command for execution.
};

#endif
