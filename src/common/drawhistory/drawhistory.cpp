#include "drawhistory.h"

DrawHistory::DrawHistory()
        : m_currentAction(m_history.begin())
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
    if (!isEmpty() && !isOnTop()) {
        // clearing old branch
        m_history.erase(std::next(m_currentAction), m_history.end());
    }

    m_history.emplace_back(std::move(command));
    ++m_currentAction;
}

std::list<std::unique_ptr<ICommand>>::iterator DrawHistory::begin()
{
    return m_history.begin();
}

std::list<std::unique_ptr<ICommand>>::iterator DrawHistory::end()
{
    return m_history.end();
}

void DrawHistory::clear()
{
    m_history.clear();
}

bool DrawHistory::isEmpty() const
{
    return m_history.empty();
}

bool DrawHistory::isOnTop() const
{
    return m_currentAction == std::prev(m_history.end());
}

bool DrawHistory::isOnStart() const
{
    return m_currentAction == m_history.begin();
}
