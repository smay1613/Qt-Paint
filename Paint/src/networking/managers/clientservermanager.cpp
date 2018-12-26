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

void ClientServerManager::onActiveCommandChanged(DrawCommandMemento command)
{
    sendActiveCommand(command);
}

void ClientServerManager::sendActiveCommand(const DrawCommandMemento& commandMemento)
{
    BasicPackage package {QVariant::fromValue (commandMemento),
                              networking::PType::ACTIVE_COMMAND};

    m_rSocket.write(package.rawData());
}
