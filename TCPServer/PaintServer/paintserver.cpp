#include "paintserver.h"
#include <QTcpSocket>
#include "packages/basicpackage.h"

PaintServer::PaintServer(const QHostAddress &address, quint16 port)
    : m_masterSocket {nullptr},
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
    qDebug() << "New connection!";
    auto* clientConnection = m_server.nextPendingConnection();
    connectSocketSignals(clientConnection);
}

void PaintServer::onReadyRead()
{
    auto* senderObject = sender();
    QTcpSocket* socket;
    if (!senderObject || !(socket = qobject_cast<QTcpSocket*>(senderObject))) {
        return;
    }

    QDataStream in;

    in.setDevice(socket);

    in.startTransaction();

    // TODO: something about package handling, maybe pipe
    BasicPackage data;
    in >> data;

    if (!in.commitTransaction()) {
        return;
    }
}

void PaintServer::connectSignals()
{
    connect(&m_server, &QTcpServer::newConnection,
                this, &PaintServer::onNewConnection);
}

void PaintServer::connectSocketSignals(QTcpSocket *socket)
{
    connect(socket, &QAbstractSocket::disconnected,
                socket, &QObject::deleteLater);
    connect(socket, &QAbstractSocket::readyRead,
                this, &PaintServer::onReadyRead);
}
