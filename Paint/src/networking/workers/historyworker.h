#ifndef HISTORYWORKER_H
#define HISTORYWORKER_H
#include "../../common/drawhistory/drawhistory.h"
#include "../hashers/historyhash.h"
#include <set>
#include <QTcpSocket>

/*! \brief This class is responsible for history synchronization.
 * \details Synchronization is a sequence of packages:
 * 1. History updates <client>
 * 2. Send history hash to remote <client>
 * 3. Compare hashes <remote>
 * 4. If not equal, request a command hashes from client <remote>
 * 5. Send command hashes <client>
 * 6. Compare command hashes with current <remote>
 * 7. Find position of diff <remote>
 * 8. Request commands from position of diff <remote>
 * 9. Send commands from position <client>
 * 10. Apply commands <remote> *
 */
class IPackage;

class HistoryWorker : public QObject
{
    Q_OBJECT
public:
    void track(DrawHistory& history);

    void addClient(QTcpSocket* socket);
    void removeClient(QTcpSocket* socket);

    void handleHistoryAction(const IPackage& package);

    //! Recalculates the hash and sends history update package
    void update();
    void startSynchronization(QTcpSocket* socket);

private slots:
    void onHistoryChanged();

private:
    void sendHashUpdate() const;
    void sendHashUpdate(QTcpSocket* socket) const;
    void sendCommandHashes() const;
    void sendCommandRequest(size_t fromPosition) const;
    void sendCommands(const QList<DrawCommandMemento>& commands, quint64 fromPosition) const;

    void notifyClients(const IPackage& data) const;

    void requestCommandHashes() const;

    void handleHistoryHashUpdate(const IPackage& package) const;

    void handleHistoryHashesRequest(const IPackage& request) const;
    void handleHistoryHashesResponse(const IPackage& response) const;

    void handleCommandsRequest(const IPackage& request) const;
    void handleCommandsResponse(const IPackage& response) const;

    bool isValidHash(uint64_t hash) const;

    int getHashesDiffPosition(const QVector<quint64>& newHashes) const;

    DrawHistory* m_pHistory;
    mutable HistoryHash m_historyHash;

    std::set<QTcpSocket*> m_clients;
};

#endif // HISTORYWORKER_H
