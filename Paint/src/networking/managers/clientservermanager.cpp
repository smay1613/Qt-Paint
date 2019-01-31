#include "clientservermanager.h"
#include "src/networking/packages/basicpackage.h"
#include "connectionmanageradaptor.h"

ClientServerManager::ClientServerManager()
    : m_pSocket {nullptr}
{
}

ClientServerManager &ClientServerManager::instance()
{
    static ClientServerManager instance;
    return instance;
}

void ClientServerManager::setSocket(QTcpSocket* socket)
{
    if (socket != m_pSocket && socket) {
         m_historyWorker.removeClient(m_pSocket);
         m_pSocket = socket;
         m_historyWorker.addClient(socket);
    }
}

void ClientServerManager::track(DrawHistory& history)
{
    m_historyWorker.track(history);
}

void ClientServerManager::handlePackage(const IPackage &package)
{
    switch (package.type()) {
        case networking::PType::ACTIVE_COMMAND: {
            handleActiveCommandPackage(package);
            break;
        }
        case networking::PType::HISTORY_HASH_UPDATE:
        case networking::PType::COMMAND_HASHES_REQUEST:
        case networking::PType::COMMAND_HASHES_RESPONSE:
        case networking::PType::COMMANDS_REQUEST:
        case networking::PType::COMMANDS_RESPONSE: {
            m_historyWorker.handleHistoryAction(package);
            if (package.type() == networking::PType::COMMANDS_RESPONSE) {
                emit commandsRecieved();
            }
            break;
        }
        default: {
            qDebug() << "Invalid package recieved!";
        }
    }
}

void ClientServerManager::onActiveCommandChanged(const DrawCommandMemento& command)
{
    if (m_pSocket && m_pSocket->state() == QAbstractSocket::ConnectedState) { // QNativeSocketEngine::write() must be called only in QAbstractSocket::ConnectedState
        sendActiveCommand(command);
    }
}

void ClientServerManager::onSynchronizationRequested()
{
    m_historyWorker.startSynchronization(m_pSocket);
}

void ClientServerManager::sendActiveCommand(const DrawCommandMemento& commandMemento)
{
    BasicPackage package {QVariant::fromValue (commandMemento),
                              networking::PType::ACTIVE_COMMAND};

    if (m_pSocket) {
        m_pSocket->write(package.rawData());
    }
}

void ClientServerManager::handleActiveCommandPackage(const IPackage& package)
{
    emit activeCommandRecieved(package.data().value<DrawCommandMemento>());
}
