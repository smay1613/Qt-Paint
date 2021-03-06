#include "connectionmanageradaptor.h"
#include <QTimer>
#include "../packages/basicpackage.h"
#include "clientservermanager.h"

ConnectionManagerAdaptor::ConnectionManagerAdaptor()
    : m_rConnectionSettings {ConnectionSettings::instance()}
{
    connectSocketSignals();
    connectToPaintServer();
    initClientServer();
}

ConnectionManagerAdaptor& ConnectionManagerAdaptor::instance()
{
    static ConnectionManagerAdaptor instance;
    return instance;
}

void ConnectionManagerAdaptor::onSocketError(QAbstractSocket::SocketError socketError)
{
    const auto error = networking::utils::UtilTools::socketEnumTostring(socketError);
    qCritical() << "Socket error happened: " << error;

    // Each time socket error was recieved, we try to connect to server again.
    // If connection was failed, we'll get in this slot again.
    QTimer::singleShot(ReconnectionTime, this,
                            &ConnectionManagerAdaptor::connectToPaintServer);

    emit reconnectionTimerStarted();
    emit connectionError(error);
}

void ConnectionManagerAdaptor::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "Socket state changed: " << socketState;
    QString state;

    switch (socketState) {
        case QAbstractSocket::SocketState::BoundState:
        case QAbstractSocket::SocketState::ConnectedState: {
            state = "connected";
            break;
        }
        case QAbstractSocket::SocketState::ClosingState:
        case QAbstractSocket::SocketState::UnconnectedState: {
            state = "disconnected";
            break;
        }
        default: {
            state = "connecting";
        }
    }

    emit connectionStateChanged(state);
}

void ConnectionManagerAdaptor::onDataRecieved()
{
    QDataStream in {&m_socket};
    in.setVersion(QDataStream::Qt_5_9);

    forever {
        in.startTransaction();

        BasicPackage inputPackage;
        in >> inputPackage;

        if (!in.commitTransaction()) {
            break;
        }

        handleServerResponse(inputPackage);
    }
}

void ConnectionManagerAdaptor::onConnected()
{
    sendIntroducingPackage();
}

void ConnectionManagerAdaptor::connectToPaintServer()
{
    qDebug() << "Connecting to server...";

    m_socket.connectToHost(m_rConnectionSettings.hostAddress(),
                           m_rConnectionSettings.port());
}

void ConnectionManagerAdaptor::connectSocketSignals()
{
    connect(&m_socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
                this, &ConnectionManagerAdaptor::onSocketError);
    connect(&m_socket, &QAbstractSocket::stateChanged,
                this, &ConnectionManagerAdaptor::onSocketStateChanged);
    connect(&m_socket, &QAbstractSocket::connected,
                this, &ConnectionManagerAdaptor::onConnected);
    connect(&m_socket, &QAbstractSocket::readyRead,
                this, &ConnectionManagerAdaptor::onDataRecieved);

}

void ConnectionManagerAdaptor::initClientServer()
{
    auto& clientServer {ClientServerManager::instance()};
    clientServer.setSocket(&m_socket);

    connect(this, &ConnectionManagerAdaptor::synchronizationRequested,
                &clientServer, &ClientServerManager::onSynchronizationRequested);
}

void ConnectionManagerAdaptor::sendIntroducingPackage()
{
    QVariant data {m_rConnectionSettings.connectionMode()};

    BasicPackage package {data, networking::PType::INTRODUCING_INFO_REQUEST};

    m_socket.write(package.rawData());
}

void ConnectionManagerAdaptor::handleServerResponse(const IPackage &response)
{
    switch (response.type()) {
        case networking::PType::INTRODUCING_INFO_RESPONSE: {
            handleIntroducingResponse(response);
            break;
        }
        default: {
            ClientServerManager::instance().handlePackage(response);
        }
    }
}

void ConnectionManagerAdaptor::handleIntroducingResponse(const IPackage &response)
{
    auto status = response.data().toInt();

    if (status == networking::Status::Failure) {
        m_rConnectionSettings.setConnectionMode(networking::ConnectionMode::Slave);
        qWarning() << "Introducing failed! Setting to slave...";
    }

    if (m_rConnectionSettings.connectionMode() == networking::ConnectionMode::Master) {
        emit synchronizationRequested();
    }
}
