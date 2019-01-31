#ifndef CLIENTSERVERMANAGER_H
#define CLIENTSERVERMANAGER_H
#include <QTcpSocket>
#include "src/networking/workers/historyworker.h"
#include "src/common/drawhistory/drawhistory.h"
#include "src/common/commands/drawcommandmemento.h"
#include "src/networking/packages/ipackage.h"

class ClientServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientServerManager(QTcpSocket& socket);

    void track(DrawHistory& history);

    void handlePackage(const IPackage& package);
signals:
    void activeCommandRecieved(DrawCommandMemento command);
    void commandsRecieved();

public slots:
    void onActiveCommandChanged(const DrawCommandMemento &command);
    void onSynchronizationRequested();

private:    
    void sendActiveCommand(const DrawCommandMemento& commandMemento);
    void handleActiveCommandPackage(const IPackage& package);

    HistoryWorker m_historyWorker;
    QTcpSocket& m_rSocket;
};

#endif // CLIENTSERVERMANAGER_H
