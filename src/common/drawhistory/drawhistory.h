#ifndef DRAWHISTORY_H
#define DRAWHISTORY_H
#include "history.h"
#include <unordered_map>
#include <utility>
#include <QBrush>
#include "../commands/drawcommand.h"

class DrawHistory : public IHistory
{
public:
    using CommandBrushPair = std::pair<std::unique_ptr<ICommand>, const QBrush>;

    DrawHistory();

    void undo() override;
    void redo() override;

    void add(std::unique_ptr<ICommand> command) override;
    void add(std::unique_ptr<ICommand> command, const QBrush& brush);

    std::list<CommandBrushPair>::iterator begin();
    std::list<CommandBrushPair>::iterator end();

    void clear() override;
    bool isEmpty() const override;

    bool isOnTop() const;
    bool isOnStart() const;

private:
    std::list<CommandBrushPair> m_commandHistory;

    std::list<CommandBrushPair>::iterator m_currentAction;
};

#endif // DRAWHISTORY_H
