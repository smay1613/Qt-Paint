#ifndef HISTORYWORKER_H
#define HISTORYWORKER_H
#include "../../common/drawhistory/drawhistory.h"
#include "../hashers/historyhash.h"
#include <QTcpSocket>

class IPackage;

class HistoryWorker : public QObject
{
    Q_OBJECT
public:

    void track(DrawHistory& history);

    void addClient(QTcpSocket* socket);
    void removeClient();

    void handleHistoryAction(const IPackage& package);

private slots:
    void onHistoryChanged();

private:
    void sendHashUpdate() const;
    void sendCommandHashes() const;
    void sendCommandRequest(size_t fromPosition) const;
    void sendCommands(const QList<DrawCommandMemento>& commands) const;

    void notifyClient(const IPackage& data) const;

    void requestCommandHashes() const;

    void handleHistoryHashUpdate(const IPackage& package) const;

    void handleHistoryHashesRequest(const IPackage& request) const;
    void handleHistoryHashesResponse(const IPackage& response) const;

    void handleCommandsRequest(const IPackage& request) const;
    void handleCommandsResponse(const IPackage& response) const;

    bool isValidHash(uint64_t hash) const;

    int getHashesDiffPosition(const QVector<quint64>& newHashes) const;

    DrawHistory* m_pHistory;
    HistoryHash m_historyHash;

    QTcpSocket* m_client;
};

#endif // HISTORYWORKER_H
