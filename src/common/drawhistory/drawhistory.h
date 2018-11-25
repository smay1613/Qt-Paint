#ifndef DRAWHISTORY_H
#define DRAWHISTORY_H
#include "history.h"
#include "../commands/drawcommand.h"

class DrawHistory : public IHistory
{
public:
    DrawHistory();

    void undo() override;
    void redo() override;
    void add(std::unique_ptr<ICommand> command) override;

    std::list<std::unique_ptr<ICommand>>::iterator begin();
    std::list<std::unique_ptr<ICommand>>::iterator end();

    void clear() override;
    bool isEmpty() const override;

    bool isOnTop() const;
    bool isOnStart() const;
private:
    std::list<std::unique_ptr<ICommand>> m_history;
    std::list<std::unique_ptr<ICommand>>::iterator m_currentAction;
};

#endif // DRAWHISTORY_H
