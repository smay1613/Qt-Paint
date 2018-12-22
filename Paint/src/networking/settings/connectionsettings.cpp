#include "connectionsettings.h"
#include "../managers/connectionmanageradaptor.h"

ConnectionSettings& ConnectionSettings::instance()
{
    static ConnectionSettings instance;
    return instance;
}

void ConnectionSettings::initSettings(const ConnectionArgumentsParser &parser)
{
    m_connectionMode = parser.modeArgument() == "master" ? networking::ConnectionMode::Master
                                                         : networking::ConnectionMode::Slave;
    emit connectionModeChanged();

    m_hostAddress = QHostAddress {parser.hostArgument()};
    emit hostAddressChanged();

    m_port = {static_cast<quint16>(parser.portArgument().toUInt())};
    emit portChanged();

    // TODO: ConnectionManagerAdaptor should live in another thread,
    // but now it will be initialized after settings.
    connectSignals();
}

networking::ConnectionMode ConnectionSettings::connectionMode() const
{
    return m_connectionMode;
}

QHostAddress ConnectionSettings::hostAddress() const
{
    return m_hostAddress;
}

QString ConnectionSettings::hostAddressAdapted() const
{
    return m_hostAddress.toString();
}

quint16 ConnectionSettings::port() const
{
    return m_port;
}

QString ConnectionSettings::lastError() const
{
    return m_lastError;
}

void ConnectionSettings::onNetworkError(QString error)
{
    if (error != m_lastError) {
        m_lastError = error;
        emit lastErrorChanged();
    }
}

void ConnectionSettings::onConnectionChanged(QString state)
{
    if (state != m_connectionState) {
        m_connectionState = state;
        emit connectionStateChanged();
    }
}

void ConnectionSettings::connectSignals()
{
    auto& connectionManager = ConnectionManagerAdaptor::instance();
    connect(&connectionManager, &ConnectionManagerAdaptor::connectionError,
                this, &ConnectionSettings::onNetworkError);
    connect(&connectionManager, &ConnectionManagerAdaptor::connectionStateChanged,
                this, &ConnectionSettings::onConnectionChanged);
    connect(&connectionManager, &ConnectionManagerAdaptor::reconnectionTimerStarted,
                this, &ConnectionSettings::reconnectionStarted);
}

void ConnectionSettings::setConnectionMode(const networking::ConnectionMode &connectionMode)
{
    if (m_connectionMode != connectionMode) {
        m_connectionMode = connectionMode;
        emit connectionModeChanged();
    }
}

QString ConnectionSettings::connectionState() const
{
    return m_connectionState;
}

int ConnectionSettings::reconnectionTime() const
{
    return ConnectionManagerAdaptor::ReconnectionTime;
}
