#ifndef DRAWHISTORY_H
#define DRAWHISTORY_H
#include "history.h"
#include <unordered_map>
#include <utility>
#include <QPen>
#include "../commands/drawcommand.h"

class DrawHistory : public QObject, public IHistory
{
    Q_OBJECT
public:
    DrawHistory();

    void undo() override;
    void redo() override;

    void add(std::unique_ptr<ICommand> command) override;

    std::list<std::unique_ptr<ICommand>>::iterator begin() noexcept override;
    std::list<std::unique_ptr<ICommand>>::iterator end() noexcept override;
    std::list<std::unique_ptr<ICommand>>::iterator top() noexcept override;

    std::list<std::unique_ptr<ICommand>>::const_iterator begin() const noexcept override;
    std::list<std::unique_ptr<ICommand>>::const_iterator end() const noexcept override;

    size_t size() const override;
    void clear() override;
    bool isEmpty() const override;

    bool isOnTop() const;
    bool isOnStart() const;

signals:
    void historyChanged();

private:
    std::list<std::unique_ptr<ICommand>> m_commandHistory;

    std::list<std::unique_ptr<ICommand>>::iterator m_currentAction;
};

#endif // DRAWHISTORY_H
