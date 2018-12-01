#ifndef DRAWHISTORY_H
#define DRAWHISTORY_H
#include "history.h"
#include <unordered_map>
#include <utility>
#include <QPen>
#include "../commands/drawcommand.h"

class DrawHistory : public IHistory
{
public:
    using CommandPenPair = std::pair<std::unique_ptr<ICommand>, const QPen>;

    DrawHistory();

    void undo() override;
    void redo() override;

    void add(std::unique_ptr<ICommand> command) override;
    void add(std::unique_ptr<ICommand> command, const QPen& brush);

    std::list<CommandPenPair>::iterator begin();
    std::list<CommandPenPair>::iterator end();
    std::list<CommandPenPair>::iterator top();

    void clear() override;
    bool isEmpty() const override;

    bool isOnTop() const;
    bool isOnStart() const;

private:
    std::list<CommandPenPair> m_commandHistory;

    std::list<CommandPenPair>::iterator m_currentAction;
};

#endif // DRAWHISTORY_H
