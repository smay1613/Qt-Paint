#include "drawhistory.h"

DrawHistory::DrawHistory()
        : m_currentAction(m_commandHistory.begin())
{

}

void DrawHistory::undo()
{
    if (!isEmpty() && !isOnStart()) {
        --m_currentAction;
    }
}

void DrawHistory::redo()
{
    if (!isEmpty() && !isOnTop()) {
        ++m_currentAction;
    }
}

void DrawHistory::add(std::unique_ptr<ICommand> command)
{
    this->add(std::move(command), QPen {});
}

void DrawHistory::add(std::unique_ptr<ICommand> command, const QPen &brush)
{
    if (!isEmpty() && !isOnTop()) {
        // clearing old branch
        m_commandHistory.erase(std::next(m_currentAction), m_commandHistory.end());
    }

    m_commandHistory.emplace_back(std::make_pair(std::move(command), brush));
    ++m_currentAction;
}

std::list<DrawHistory::CommandPenPair>::iterator DrawHistory::begin()
{
    return m_commandHistory.begin();
}

std::list<DrawHistory::CommandPenPair>::iterator DrawHistory::end()
{
    return m_commandHistory.end();
}

void DrawHistory::clear()
{
    m_commandHistory.clear();
}

bool DrawHistory::isEmpty() const
{
    return m_commandHistory.empty();
}

bool DrawHistory::isOnTop() const
{
    return m_currentAction == std::prev(m_commandHistory.end());
}

bool DrawHistory::isOnStart() const
{
    return m_currentAction == m_commandHistory.begin();
}
