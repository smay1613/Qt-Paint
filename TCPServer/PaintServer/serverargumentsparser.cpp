#include "serverargumentsparser.h"
#include <QDebug>

ServerArgumentsParser::ServerArgumentsParser(const QCoreApplication &app)
{
    m_parser.setApplicationDescription("Paint server application");

    m_parser.addHelpOption();
    m_parser.addOptions({{"listen-host", "IP address or a hostname.", "host", "127.0.0.1"},
                         {"listen-port", "Port", "port", "8060"}
                        });

    m_parser.process(app);

    m_hostArgument = m_parser.value("listen-host");
    m_portArgument = m_parser.value("listen-port");
}

QString ServerArgumentsParser::hostArgument() const
{
    return m_hostArgument;
}

QString ServerArgumentsParser::portArgument() const
{
    return m_portArgument;
}
