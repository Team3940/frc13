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
      * Constructs a new SequentialCommand with no commands.  Add commands
      * to execute sequentially with the << operator.
      */
    SequentialCommand();

    virtual ~SequentialCommand();

    virtual void Reset();

    virtual std::string ToString();

    virtual bool Run();

  private:
    int commandIndex;  ///< Holds the index of the next command for execution.
};

#endif
