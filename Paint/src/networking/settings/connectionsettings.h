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
    Q_PROPERTY(QString connectionState READ connectionState NOTIFY connectionStateChanged)
    Q_PROPERTY(QString lastError READ lastError NOTIFY lastErrorChanged)
    Q_PROPERTY(int reconnectionTime READ reconnectionTime CONSTANT)

public:
    static ConnectionSettings& instance();
    void initSettings(const ConnectionArgumentsParser& parser);

    networking::ConnectionMode connectionMode() const;
    QHostAddress hostAddress() const;
    QString hostAddressAdapted() const;
    quint16 port() const;

    bool isConnected() const;
    QString lastError() const;

    QString connectionState() const;
    int reconnectionTime() const;

    void setConnectionMode(const networking::ConnectionMode& connectionMode);

signals:
    void connectionModeChanged();
    void hostAddressChanged();
    void portChanged();
    void connectionStateChanged();
    void lastErrorChanged();

    void reconnectionStarted();

public slots:
    void onNetworkError(QString error);
    void onConnectionChanged(QString state);

private:
    ConnectionSettings() = default;
    void connectSignals();

    networking::ConnectionMode m_connectionMode;
    QHostAddress m_hostAddress;
    quint16 m_port;

    QString m_connectionState;
    QString m_lastError;
};

#endif // CONNECTIONSETTINGS_H
