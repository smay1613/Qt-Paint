#include "drawhistory.h"
#include <QDebug>

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
    if (!isEmpty() && !isOnTop()) {
        // clearing old branch
        m_commandHistory.erase(std::next(m_currentAction), m_commandHistory.end());
    }

    m_commandHistory.emplace_back(std::move(command));
    m_currentAction = std::prev(m_commandHistory.end());
}

std::list<std::unique_ptr<ICommand>>::iterator DrawHistory::begin() noexcept
{
    return m_commandHistory.begin();
}

std::list<std::unique_ptr<ICommand>>::iterator DrawHistory::end() noexcept
{
    return std::next(m_currentAction);
}

std::list<std::unique_ptr<ICommand>>::iterator DrawHistory::top() noexcept
{
    return m_commandHistory.end();
}

void DrawHistory::clear()
{
    m_commandHistory.clear();
    m_currentAction = m_commandHistory.begin();
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
    return m_currentAction == std::prev(m_commandHistory.begin());
}
