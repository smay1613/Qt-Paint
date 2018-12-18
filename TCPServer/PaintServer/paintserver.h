#ifndef PAINTSERVER_H
#define PAINTSERVER_H
#include <QTcpServer>
#include <QDataStream>
#include <unordered_map>

class PaintServer : public QObject
{
    Q_OBJECT
public:
    explicit PaintServer(const QHostAddress& address, quint16 port);

public slots:
    void onNewConnection();
    void onReadyRead();

private:
    void connectSignals();
    void connectSocketSignals(QTcpSocket* socket);

    QTcpServer m_server;

    QTcpSocket* m_masterSocket;
    std::vector<QTcpSocket*> m_clientSockets; // Client Id and it's socket

    // Clients that didn't introduce theirself if they are master or client
    std::vector<QTcpSocket*> m_pendingConnections;

    QHostAddress m_listenAddress;
    quint16 m_listenPort;
};

#endif // PAINTSERVER_H
