#include "paintserver.h"
#include <QTcpSocket>
#include "packages/basicpackage.h"
#include "networkingtypes.h"

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

void PaintServer::handlePackage(const IPackage &package, QTcpSocket *socket)
{
    if (!socket) {
        qWarning() << "Unable to handle null socket's package!";
        return;
    }

    qDebug() << "Recieved package with type " << package.type();

    switch (package.type()) {
        case networking::PType::INTRODUCING: {
            handleIntroducingPackage(package, socket);
            break;
        }
        default: {
            qWarning() << "Invalid package recieved!";
        }
    }
}

void PaintServer::handleIntroducingPackage(const IPackage &package, QTcpSocket *socket)
{
    auto clientType = package.data().toInt();
    if (static_cast<networking::ConnectionMode>(clientType) == networking::ConnectionMode::Master) {
        if (m_masterSocket) {
            qDebug() << "Socket added to the clients list, because there is another active master";
            m_clientSockets.emplace_back(socket); // we already have master socket, so adding to clients
        } else {
            qDebug() << "Socket becomes master.";
            m_masterSocket = socket;
        }
    } else {
        qDebug() << "Socket added to the clients list";
        m_clientSockets.emplace_back(socket);
    }
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
    QTcpSocket* socket {qobject_cast<QTcpSocket*>(senderObject)};

    if (!socket) {
        return;
    }

    QDataStream in {socket};
    in.startTransaction();

    BasicPackage inputPackage;
    in >> inputPackage;

    if (!in.commitTransaction())
        return;

    handlePackage(inputPackage, socket);
}

void PaintServer::onClientDisconnected()
{
    auto* senderObject = sender();
    QTcpSocket* socket {qobject_cast<QTcpSocket*>(senderObject)};

    if (!socket) {
        return;
    }

    if (socket == m_masterSocket) {
        socket->deleteLater();
        m_masterSocket = nullptr;
        qDebug() << "Master disconnected!";
    } else {
        std::remove(m_clientSockets.begin(), m_clientSockets.end(), socket);
        socket->deleteLater();
        qDebug() << "Slave disconnected!";
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
                this, &PaintServer::onClientDisconnected);
    connect(socket, &QAbstractSocket::readyRead,
                this, &PaintServer::onReadyRead);
}
