#ifndef CLIENTSERVERMANAGER_H
#define CLIENTSERVERMANAGER_H
#include "src/networking/hashers/historyhash.h"
#include "src/common/drawhistory/drawhistory.h"
#include <QTcpSocket>

class ClientServerManager
{
public:
    explicit ClientServerManager(QTcpSocket& socket);

    void setHistory(DrawHistory *history);

public slots:
    void onActiveCommandChanged(const DrawCommand& command);

private:
    HistoryHash m_historyHash;
    QTcpSocket& m_rSocket;
};

#endif // CLIENTSERVERMANAGER_H
