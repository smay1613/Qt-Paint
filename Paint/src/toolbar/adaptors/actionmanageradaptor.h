#ifndef ACTIONMANAGERADAPTOR_H
#define ACTIONMANAGERADAPTOR_H
#include <QObject>
#include "src/common/drawhistory/drawhistory.h"

class ActionManagerAdaptor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool undoAvailable READ undoAvailable NOTIFY undoAvailabilityChanged)
    Q_PROPERTY(bool redoAvailable READ redoAvailable NOTIFY redoAvailabilityChanged)
public:
    static ActionManagerAdaptor& instance();

    Q_INVOKABLE void undo();
    Q_INVOKABLE void redo();
    Q_INVOKABLE void clear();
    Q_INVOKABLE bool save(QString path);

    void trackHistory(DrawHistory* history);

    bool undoAvailable() const;
    bool redoAvailable() const;

private slots:
    void updateHistoryAvailability();

signals:
    void undoRequested();
    void redoRequested();
    void clearRequested();

    void undoAvailabilityChanged();
    void redoAvailabilityChanged();

private:
    ActionManagerAdaptor();

    void setUndoAvailable(bool undoAvailable);
    void setRedoAvailable(bool redoAvailable);

    bool m_undoAvailable;
    bool m_redoAvailable;

    DrawHistory* m_pHistory;
};

#endif // ACTIONMANAGERADAPTOR_H
