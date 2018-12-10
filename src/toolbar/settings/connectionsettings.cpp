#include "connectionsettings.h"

ConnectionSettings::ConnectionSettings(const ConnectionArgumentsParser &parser)
    : m_connectionMode {parser.modeArgument() == "master" ? ConnectionMode::Server
                                                          : ConnectionMode::Client},
      m_hostAddress {parser.hostArgument()},
      m_port {static_cast<quint16>(parser.portArgument().toUInt())}
{
}
