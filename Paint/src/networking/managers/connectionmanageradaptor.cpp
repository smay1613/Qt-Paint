#include "connectionmanageradaptor.h"
#include <QTimer>

ConnectionManagerAdaptor::ConnectionManagerAdaptor()
    : m_rConnectionSettings {ConnectionSettings::instance()}
{
    connectSocketSignals();
    connectToPaintServer();
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
        case QAbstractSocket::SocketState::ConnectedState:
        case QAbstractSocket::SocketState::BoundState: {
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
}
