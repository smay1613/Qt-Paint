#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H
#include <QObject>
#include <QHostAddress>
#include "../clparsers/connectionargumentsparser.h"
#include "../networkingtypes.h"

class ConnectionSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(networking::ConnectionMode connectionMode READ connectionMode NOTIFY connectionModeChanged)
    Q_PROPERTY(QString hostAddress READ hostAddressAdapted NOTIFY hostAddressChanged)
    Q_PROPERTY(quint16 port READ port NOTIFY portChanged)

public:
    static ConnectionSettings& instance();
    void initSettings(const ConnectionArgumentsParser& parser);

    networking::ConnectionMode connectionMode() const;
    QHostAddress hostAddress() const;
    QString hostAddressAdapted() const;
    quint16 port() const;

signals:
    void connectionModeChanged();
    void hostAddressChanged();
    void portChanged();

private:
    ConnectionSettings() = default;

    networking::ConnectionMode m_connectionMode;
    QHostAddress m_hostAddress;
    quint16 m_port;
};

#endif // CONNECTIONSETTINGS_H
