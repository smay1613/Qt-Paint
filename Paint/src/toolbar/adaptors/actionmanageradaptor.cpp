#include "actionmanageradaptor.h"
#include <QDebug>

ActionManagerAdaptor::ActionManagerAdaptor()
        : m_undoAvailable(false),
          m_redoAvailable(false)
{

}

bool ActionManagerAdaptor::redoAvailable() const
{
    return m_redoAvailable;
}

void ActionManagerAdaptor::setRedoAvailable(bool redoAvailable)
{
    m_redoAvailable = redoAvailable;
    emit redoAvailabilityChanged();
}

bool ActionManagerAdaptor::undoAvailable() const
{
    return m_undoAvailable;
}

void ActionManagerAdaptor::setUndoAvailable(bool undoAvailable)
{
    m_undoAvailable = undoAvailable;
    emit undoAvailabilityChanged();
}

ActionManagerAdaptor &ActionManagerAdaptor::instance()
{
    static ActionManagerAdaptor instance;
    return instance;
}

void ActionManagerAdaptor::undo()
{
    if (m_undoAvailable) {
        undoRequested();
    } else {
        qWarning() << "Undo is not available!";
    }
}

void ActionManagerAdaptor::redo()
{
    if (m_redoAvailable) {
        redoRequested();
    } else {
        qWarning() << "Redo is not available!";
    }
}

void ActionManagerAdaptor::clear()
{
    clearRequested();
}

