#include "clientservermanager.h"
#include "src/networking/packages/basicpackage.h"

ClientServerManager::ClientServerManager(QTcpSocket &socket)
    : m_rSocket {socket}
{
}

void ClientServerManager::setHistory(DrawHistory* history)
{
    m_historyHash.trackHistory(history);
}

void ClientServerManager::handlePackage(const IPackage &package)
{
    switch (package.type()) {
        case networking::PType::ACTIVE_COMMAND: {
            handleActiveCommandPackage(package);
            break;
        }
        default: {
            qDebug() << "Invalid package recieved!";
        }
    }
}

void ClientServerManager::onActiveCommandChanged(const DrawCommandMemento& command)
{
    if (m_rSocket.state() == QAbstractSocket::ConnectedState) { // QNativeSocketEngine::write() must be called only in QAbstractSocket::ConnectedState
        sendActiveCommand(command);
    }
}

void ClientServerManager::sendActiveCommand(const DrawCommandMemento& commandMemento)
{
    BasicPackage package {QVariant::fromValue (commandMemento),
                              networking::PType::ACTIVE_COMMAND};

    m_rSocket.write(package.rawData());
}

void ClientServerManager::handleActiveCommandPackage(const IPackage& package)
{
    emit activeCommandRecieved(package.data().value<DrawCommandMemento>());
}
