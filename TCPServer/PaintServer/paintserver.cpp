#include "paintserver.h"
#include <QTcpSocket>
#include "networkingtypes.h"
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
    m_masterHistoryWorker.track(m_localHistory);
    m_clientHistoryWorker.track(m_localHistory);
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
        case networking::PType::INTRODUCING_INFO_REQUEST: {
            handleIntroducingPackage(package, socket);
            break;
        }
        case networking::PType::ACTIVE_COMMAND: {
            if (socket == m_masterSocket) { // only the master can send active command!
                handleActiveCommandPackage(package);
            }
            break;
        }
        case networking::PType::HISTORY_HASH_UPDATE:
        case networking::PType::COMMAND_HASHES_REQUEST:
        case networking::PType::COMMAND_HASHES_RESPONSE:
        case networking::PType::COMMANDS_REQUEST:
        case networking::PType::COMMANDS_RESPONSE: {
            if (socket == m_masterSocket) {
                qDebug() << "<master history action>";
                m_masterHistoryWorker.handleHistoryAction(package);
                if (package.type() == networking::PType::COMMANDS_RESPONSE) {
                    m_clientHistoryWorker.update();
                }
            } else {
                qDebug() << "<slave history action>";
                m_clientHistoryWorker.handleHistoryAction(package);
            }
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
    auto result {networking::Status::Success};

    if (clientType == networking::ConnectionMode::Master) {
        if (m_masterSocket) {
            qDebug() << "Socket added to the clients list, because there is another active master";

            addClient(socket); // we already have master socket, so adding to clients
            result = networking::Status::Failure;
        } else {
            qDebug() << "Socket becomes master.";
            setMaster(socket);
        }
    } else {
        qDebug() << "Socket added to the clients list";
        addClient(socket);
    }

    BasicPackage introducingSuccessPackage {{result}, networking::PType::INTRODUCING_INFO_RESPONSE};
    socket->write(introducingSuccessPackage.rawData());
}

void PaintServer::handleActiveCommandPackage(const IPackage &package)
{
    const auto& rawData = package.rawData();
    // resend active command package to all clients
    for (auto client : m_clientSockets) {
        client->write(rawData);
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
    in.setVersion(QDataStream::Qt_5_9);

    forever {
        in.startTransaction();

        BasicPackage inputPackage {networking::PType::INVALID,
                                    QIODevice::OpenModeFlag::ReadWrite}; // for using as for reading,
                                                                         // as for resending
        in >> inputPackage;

        if (!in.commitTransaction()) {
            break;
        }

        handlePackage(inputPackage, socket);
    }
}

void PaintServer::onClientDisconnected()
{
    auto* senderObject = sender();
    QTcpSocket* socket {qobject_cast<QTcpSocket*>(senderObject)};

    if (!socket) {
        return;
    }

    if (socket == m_masterSocket) {
        m_masterHistoryWorker.removeClient(m_masterSocket);
        socket->deleteLater();
        m_masterSocket = nullptr;
        qDebug() << "Master disconnected!";
    } else {
        m_clientHistoryWorker.removeClient(socket);
        m_clientSockets.erase(std::remove(m_clientSockets.begin(), m_clientSockets.end(), socket));
        socket->deleteLater();
        qDebug() << "Slave disconnected!";
    }
}

void PaintServer::addClient(QTcpSocket *socket)
{
    if (socket) {
        m_clientSockets.emplace_back(socket);
        m_clientHistoryWorker.addClient(socket);
        if (!m_localHistory.isEmpty()) {
            m_clientHistoryWorker.startSynchronization(socket);
        }
    }
}

void PaintServer::setMaster(QTcpSocket *socket)
{
    if (socket) {
        m_masterSocket = socket;
        m_masterHistoryWorker.addClient(m_masterSocket);
        if (!m_localHistory.isEmpty()) {
            m_masterHistoryWorker.startSynchronization(m_masterSocket);
        }
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
