#ifndef CLIENTSERVERMANAGER_H
#define CLIENTSERVERMANAGER_H
#include <QTcpSocket>
#include "src/networking/hashers/historyhash.h"
#include "src/common/drawhistory/drawhistory.h"
#include "src/common/commands/drawcommandmemento.h"
#include "src/networking/packages/ipackage.h"

class ClientServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientServerManager(QTcpSocket& socket);

    void setHistory(DrawHistory *history);

    void handlePackage(const IPackage& package);

signals:
    void activeCommandRecieved(DrawCommandMemento command);

public slots:
    void onActiveCommandChanged(const DrawCommandMemento &command);

private:    
    void sendActiveCommand(const DrawCommandMemento& commandMemento);
    void handleActiveCommandPackage(const IPackage& package);

    HistoryHash m_historyHash;
    QTcpSocket& m_rSocket;
};

#endif // CLIENTSERVERMANAGER_H
