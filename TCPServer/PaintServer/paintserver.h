#ifndef PAINTSERVER_H
#define PAINTSERVER_H
#include <QTcpServer>
#include <QDataStream>
#include <vector>
#include "packages/ipackage.h"

class PaintServer : public QObject
{
    Q_OBJECT
public:
    explicit PaintServer(const QHostAddress& address, quint16 port);

    void handlePackage(const IPackage& package, QTcpSocket* socket);

public slots:
    void onReadyRead();

    void onNewConnection();
    void onClientDisconnected();

private:
    void connectSignals();
    void connectSocketSignals(QTcpSocket* socket);

    void handleIntroducingPackage(const IPackage& package, QTcpSocket *socket);
    void handleActiveCommandPackage(const IPackage& package);

    QTcpServer m_server;

    QTcpSocket* m_masterSocket;
    std::vector<QTcpSocket*> m_clientSockets;

    QHostAddress m_listenAddress;
    quint16 m_listenPort;
};

#endif // PAINTSERVER_H
