#ifndef PAINTSERVER_H
#define PAINTSERVER_H
#include <QTcpServer>
#include <utility>

class PaintServer : public QObject
{
    Q_OBJECT
public:
    using Id = uint;
    explicit PaintServer(QHostAddress address, quint16 port);

public slots:
    void onNewConnection();

private:
    void connectSignals();
    QTcpServer m_server;

    QTcpSocket* m_masterSocket;
    std::vector<std::pair<Id, QTcpSocket*>> m_clientSockets; // Client Id and it's socket

    QHostAddress m_listenAddress;
    quint16 m_listenPort;
};

#endif // PAINTSERVER_H
