#include "connectionargumentsparser.h"
#include <QDebug>

ConnectionArgumentsParser::ConnectionArgumentsParser(const QCoreApplication &app)
{
    m_parser.setApplicationDescription("Network paint application");

    m_parser.addHelpOption();
    m_parser.addOptions({{"server-host", "Server IP address or a hostname.", "host", "127.0.0.1"},
                         {"server-port", "Server port", "port", "8060"},
                         {"mode", "Paint can work with two modes - slave and master. "
                                  "Master will stream it's painted image to all clients", "mode", "slave"}
                        });

    m_parser.process(app);

    m_hostArgument = m_parser.value("server-host");
    m_portArgument = m_parser.value("server-port");
    m_modeArgument = m_parser.value("mode");

    if (!(m_modeArgument == "slave" || m_modeArgument == "master")) {
        qWarning() << "Incorrect mode is set. Slave mod is applied.";
        qWarning() << "Available mods: <slave>, <master>.";
    }
}

const QString ConnectionArgumentsParser::hostArgument() const
{
    return m_hostArgument;
}

const QString ConnectionArgumentsParser::portArgument() const
{
    return m_portArgument;
}

const QString ConnectionArgumentsParser::modeArgument() const
{
    return m_modeArgument;
}
