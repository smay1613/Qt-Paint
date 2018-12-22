#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H
#include <QObject>
#include <QTcpSocket>
#include "../settings/connectionsettings.h"

class ConnectionManagerAdaptor : public QObject
{
    Q_OBJECT
public:
    static ConnectionManagerAdaptor& instance();

    const static size_t ReconnectionTime = 5000 /*ms*/;

signals:
    void connectionError(QString error);
    void connectionStateChanged(QString connected);
    void reconnectionTimerStarted();

public slots:
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

private slots:
    void onConnected();

protected:
    QTcpSocket m_socket;

private:
    ConnectionManagerAdaptor();

    void connectToPaintServer();
    void connectSocketSignals();

    void sendIntroducingPackage();

    ConnectionSettings& m_rConnectionSettings;
};

#endif // CONNECTIONMANAGER_H
