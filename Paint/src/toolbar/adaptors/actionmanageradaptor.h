#ifndef ACTIONMANAGERADAPTOR_H
#define ACTIONMANAGERADAPTOR_H
#include <QObject>

class ActionManagerAdaptor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool undoAvailable READ undoAvailable WRITE setUndoAvailable NOTIFY undoAvailabilityChanged)
    Q_PROPERTY(bool redoAvailable READ redoAvailable WRITE setRedoAvailable NOTIFY redoAvailabilityChanged)
public:
    static ActionManagerAdaptor& instance();

    Q_INVOKABLE void undo();
    Q_INVOKABLE void redo();
    Q_INVOKABLE void clear();

    bool undoAvailable() const;
    void setUndoAvailable(bool undoAvailable);

    bool redoAvailable() const;
    void setRedoAvailable(bool redoAvailable);

signals:
    void undoRequested();
    void redoRequested();
    void clearRequested();

    void undoAvailabilityChanged();
    void redoAvailabilityChanged();

private:
    ActionManagerAdaptor();

    bool m_undoAvailable;
    bool m_redoAvailable;
};

#endif // ACTIONMANAGERADAPTOR_H
