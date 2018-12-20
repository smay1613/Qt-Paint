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

signals:
    void connectionError(QString error);
    void connectionStateChanged(QString connected);

public slots:
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

protected:
    QTcpSocket m_socket;

private:
    ConnectionManagerAdaptor();

    void connectToPaintServer();
    void connectSocketSignals();

    ConnectionSettings& m_rConnectionSettings;
};

#endif // CONNECTIONMANAGER_H
