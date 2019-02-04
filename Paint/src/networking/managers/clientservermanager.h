#ifndef CLIENTSERVERMANAGER_H
#define CLIENTSERVERMANAGER_H
#include <QTcpSocket>
#include "src/networking/workers/historyworker.h"
#include "src/common/drawhistory/drawhistory.h"
#include "src/common/commands/drawcommandmemento.h"
#include "src/networking/packages/ipackage.h"

/*!
 * \brief This class handles all packages related to the history and active command.
 * \details It handles by ourself only the ACTIVE_COMMAND package, and all history-related
 * it delegates to the HistoryWorker object.
 * Also it is responsible for sending active command updates.
 */

class ClientServerManager : public QObject
{
    Q_OBJECT
public:
    static ClientServerManager& instance();

    //! Socket is provided by ConnectionManagerAdaptor.
    void setSocket(QTcpSocket* socket);
    void track(DrawHistory& history);

    void handlePackage(const IPackage& package);

signals:
    void activeCommandRecieved(DrawCommandMemento command);
    void commandsRecieved();

public slots:
    void onActiveCommandChanged(const DrawCommandMemento &command);
    void onSynchronizationRequested();

private:
    ClientServerManager();
    void sendActiveCommand(const DrawCommandMemento& commandMemento);
    void handleActiveCommandPackage(const IPackage& package);

    HistoryWorker m_historyWorker;
    QTcpSocket* m_pSocket;
};

#endif // CLIENTSERVERMANAGER_H
