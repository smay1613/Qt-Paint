#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H
#include <QObject>
#include <QHostAddress>
#include "../clparsers/connectionargumentsparser.h"

class ConnectionSettings : public QObject
{
    Q_OBJECT

public:
    explicit ConnectionSettings(const ConnectionArgumentsParser& parser);

    enum ConnectionMode {
        Client,
        Server
    };

private:
    ConnectionMode m_connectionMode;
    QHostAddress m_hostAddress;
    quint16 m_port;
};

#endif // CONNECTIONSETTINGS_H
