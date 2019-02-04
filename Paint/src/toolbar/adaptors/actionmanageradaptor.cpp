#include "actionmanageradaptor.h"
#include "src/common/helpers/imagesaver.h"
#include <QDebug>

ActionManagerAdaptor::ActionManagerAdaptor()
        : m_undoAvailable {false},
          m_redoAvailable {false},
          m_pHistory {nullptr}
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
    if (m_undoAvailable && m_pHistory) {
        m_pHistory->undo();
    } else {
        qWarning() << "Undo is not available!";
    }
}

void ActionManagerAdaptor::redo()
{
    if (m_redoAvailable && m_pHistory) {
        m_pHistory->redo();
    } else {
        qWarning() << "Redo is not available!";
    }
}

void ActionManagerAdaptor::clear()
{
    if (m_pHistory) {
        m_pHistory->clear();
    }
}

bool ActionManagerAdaptor::save(const QString& path)
{
    return m_pHistory ? ImageSaver::save(*m_pHistory, path) : false;
}

void ActionManagerAdaptor::trackHistory(DrawHistory* history)
{
    if (history) {
        m_pHistory = history;
        connect(m_pHistory, &DrawHistory::historyChanged,
                    this, &ActionManagerAdaptor::updateHistoryAvailability);
    }
}

void ActionManagerAdaptor::updateHistoryAvailability()
{
    setUndoAvailable(!m_pHistory->isEmpty() && !m_pHistory->isOnStart());
    setRedoAvailable(!m_pHistory->isEmpty() && !m_pHistory->isOnTop());
}

