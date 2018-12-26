#ifndef CLIENTSERVERMANAGER_H
#define CLIENTSERVERMANAGER_H
#include "src/networking/hashers/historyhash.h"
#include "src/common/drawhistory/drawhistory.h"
#include "src/common/commands/drawcommandmemento.h"
#include <QTcpSocket>

class ClientServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientServerManager(QTcpSocket& socket);

    void setHistory(DrawHistory *history);

public slots:
    void onActiveCommandChanged(DrawCommandMemento command);

private:    
    void sendActiveCommand(const DrawCommandMemento &commandMemento);

    HistoryHash m_historyHash;
    QTcpSocket& m_rSocket;
};

#endif // CLIENTSERVERMANAGER_H
