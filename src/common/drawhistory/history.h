#ifndef HISTORY_H
#define HISTORY_H
#include "../commands/command.h"
#include <memory>
#include <iterator>

class IHistory
{
public:
    IHistory();
    virtual ~IHistory() {}

    virtual void undo() = 0;
    virtual void redo() = 0;
    virtual void add(std::unique_ptr<ICommand> command) = 0;

    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;
};

#endif // HISTORY_H
