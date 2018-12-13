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
    DrawHistory();

    void undo() override;
    void redo() override;

    void add(std::unique_ptr<ICommand> command) override;

    std::list<std::unique_ptr<ICommand>>::iterator begin() noexcept override;
    std::list<std::unique_ptr<ICommand>>::iterator end() noexcept override;
    std::list<std::unique_ptr<ICommand>>::iterator top() noexcept override;

    void clear() override;
    bool isEmpty() const override;

    bool isOnTop() const;
    bool isOnStart() const;

    uint64_t hash() const;
    std::vector<uint64_t> commandsHashes() const;

private:
    std::list<std::unique_ptr<ICommand>> m_commandHistory;

    std::list<std::unique_ptr<ICommand>>::iterator m_currentAction;

    void updateHash();

    uint64_t m_totalHash;
    std::vector<uint64_t> m_commandsHashes;
};

#endif // DRAWHISTORY_H
