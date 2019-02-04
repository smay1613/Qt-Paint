#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H
#include <QObject>
#include <QTcpSocket>
#include "../settings/connectionsettings.h"
#include "../packages/ipackage.h"
/*!
 *  \brief This class is an entry point for all input packages.
 *  \details Connection manager is a class for setting connection up from ConnectionSettings
 *  and handling it's state (providing it to the QML too).
 *  Implementation of two-side handshake introducing:
 *  ConnectionManagerAdaptor#sendIntroducingPackage and
 *  ConnectionManagerAdaptor#handleIntroducingResponse.
 *
 *  If ConnectionManager can't handle the recieved package, it delegates package handling
 *  to a ClientServerManager object.
*/
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

    //! Synchronization is requested after client successfuly connected to the server.
    void synchronizationRequested();

public slots:
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

    //! Entry point for packages
    void onDataRecieved();

private slots:
    void onConnected();

private:
    ConnectionManagerAdaptor();

    void connectToPaintServer();
    void connectSocketSignals();
    void initClientServer();

    //! Sends introducing package to a PaintServer with the type of client (master or slave)
    void sendIntroducingPackage();

    void handleServerResponse(const IPackage& response);

    //! Applies the result of introducing. If introducing was failed (another master is online), sets mode to slave.
    void handleIntroducingResponse(const IPackage& response);

    ConnectionSettings& m_rConnectionSettings;
    QTcpSocket m_socket;
};

#endif // CONNECTIONMANAGER_H
