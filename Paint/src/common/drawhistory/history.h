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

    //! Changes the current position in stack if possible
    virtual void undo() = 0;
    //! Changes the current position in stack if possible
    virtual void redo() = 0;
    //! \warning Transfers ownership of command!
    virtual void add(std::unique_ptr<ICommand> command) = 0;
    virtual void pop() = 0;

    virtual std::list<std::unique_ptr<ICommand>>::iterator begin() noexcept = 0;
    //! \returns Iterator to the current position in stack
    virtual std::list<std::unique_ptr<ICommand>>::iterator end() noexcept = 0;
    //! \returns Iterator to the real end of the commands stack
    virtual std::list<std::unique_ptr<ICommand>>::iterator top() noexcept = 0;

    virtual std::list<std::unique_ptr<ICommand>>::const_iterator begin() const noexcept = 0;
    virtual std::list<std::unique_ptr<ICommand>>::const_iterator end() const noexcept = 0;

    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;
    //! \returns Full size of container (not limited by current position)
    virtual size_t size() const = 0;
};

#endif // HISTORY_H
