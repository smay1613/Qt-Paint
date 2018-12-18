#ifndef HISTORY_H
#define HISTORY_H
#include "../commands/command.h"
#include <memory>
#include <list>
#include <iterator>

class IHistory
{
public:
    IHistory() = default;
    virtual ~IHistory() {}

    virtual void undo() = 0;
    virtual void redo() = 0;
    virtual void add(std::unique_ptr<ICommand> command) = 0;

    virtual std::list<std::unique_ptr<ICommand>>::iterator begin() noexcept = 0;
    virtual std::list<std::unique_ptr<ICommand>>::iterator end() noexcept = 0;
    virtual std::list<std::unique_ptr<ICommand>>::iterator top() noexcept = 0;

    virtual std::list<std::unique_ptr<ICommand>>::const_iterator begin() const noexcept = 0;
    virtual std::list<std::unique_ptr<ICommand>>::const_iterator end() const noexcept = 0;

    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;
    virtual size_t size() const = 0;
};

#endif // HISTORY_H
