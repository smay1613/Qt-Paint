#include "paintserver.h"
#include <exception>

PaintServer::PaintServer(QHostAddress address, quint16 port)
    : m_server {this},
      m_listenAddress {address},
      m_listenPort {port}
{
    if (!m_server.listen(m_listenAddress, m_listenPort)) {
        qCritical() << "Cannot initialize server!";
        qCritical() << "Server not started.";
    }
    connectSignals();
}

void PaintServer::onNewConnection()
{
    // TODO: Some connection logic
}

void PaintServer::connectSignals()
{
    connect(&m_server, &QTcpServer::newConnection,
                this, &PaintServer::onNewConnection);
}
