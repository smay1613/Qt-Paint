#include "clientservermanager.h"

ClientServerManager::ClientServerManager(QTcpSocket &socket)
    : m_rSocket {socket}
{
}

void ClientServerManager::setHistory(DrawHistory* history)
{
    m_historyHash.trackHistory(history);
}
