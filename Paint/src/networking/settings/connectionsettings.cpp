#include "connectionsettings.h"

ConnectionSettings& ConnectionSettings::instance()
{
    static ConnectionSettings instance;
    return instance;
}

void ConnectionSettings::initSettings(const ConnectionArgumentsParser &parser)
{
    m_connectionMode = parser.modeArgument() == "master" ? networking::ConnectionMode::Server
                                                         : networking::ConnectionMode::Client;
    emit connectionModeChanged();

    m_hostAddress = QHostAddress {parser.hostArgument()};
    emit hostAddressChanged();

    m_port = {static_cast<quint16>(parser.portArgument().toUInt())};
    emit portChanged();
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
