#include "historyworker.h"
#include <QObject>
#include <QVector>
#include "../packages/basicpackage.h"

void HistoryWorker::track(DrawHistory& history)
{
    m_pHistory = &history;
    connect(m_pHistory, &DrawHistory::historyChanged,
                this, &HistoryWorker::onHistoryChanged);
}

void HistoryWorker::addClient(QTcpSocket* socket)
{
    if (socket) {
        m_client = socket;
    }
}

void HistoryWorker::removeClient()
{
    m_client = nullptr;
}

bool HistoryWorker::isValidHash(uint64_t hash) const
{
    return hash == m_historyHash.totalHash();
}

int HistoryWorker::getHashesDiffPosition(const QVector<quint64>& newHashes) const
{
    const auto& currentHashes = m_historyHash.commandHashes();

    int currentSize {currentHashes.size()};
    int newSize {newHashes.size()};
    int minSize {std::min(currentSize, newSize)};

    int diffPosition {currentSize != newSize ?
                                             minSize
                                             : -1};

    for (int i = 0; i < minSize; ++i) {
        if (newHashes.at(i) != currentHashes.at(i)) {
            diffPosition = i;
            break;
        }
    }

    return diffPosition;
}

void HistoryWorker::requestCommandHashes() const
{
    BasicPackage package {QVariant::fromValue(true), // dummy data
                            networking::PType::COMMAND_HASHES_REQUEST};
    notifyClient(package);
}

void HistoryWorker::handleHistoryAction(const IPackage& package)
{
    switch (package.type()) {
        case networking::PType::HISTORY_HASH_UPDATE: {
            handleHistoryHashUpdate(package);
            break;
        }
        case networking::PType::COMMAND_HASHES_REQUEST: {
            handleHistoryHashesRequest(package);
            break;
        }
        case networking::PType::COMMAND_HASHES_RESPONSE: {
            handleHistoryHashesResponse(package);
            break;
        }
        case networking::PType::COMMANDS_REQUEST: {
            // TODO
            break;
        }
        default: {
            qWarning() << "Invalid package type!";
        }
    }
}

void HistoryWorker::handleHistoryHashesRequest(const IPackage& request) const
{
    Q_UNUSED(request)
    sendCommandHashes();
}

void HistoryWorker::handleHistoryHashesResponse(const IPackage& response) const
{
    QVector<quint64> hashes {response.data().value<QVector<quint64>>()};

    int diffPosition {getHashesDiffPosition(hashes)};

    if (diffPosition != -1) {
        sendCommandRequest(static_cast<size_t>(diffPosition));
    }
}

void HistoryWorker::sendCommandHashes() const
{
    BasicPackage package {QVariant::fromValue(m_historyHash.commandHashes()),
                            networking::PType::COMMAND_HASHES_RESPONSE};
    notifyClient(package);
}

void HistoryWorker::sendCommandRequest(size_t fromPosition) const
{
    BasicPackage package {QVariant::fromValue(fromPosition),
                            networking::PType::COMMANDS_REQUEST};

    notifyClient(package);
}

void HistoryWorker::notifyClient(const IPackage& data) const
{
    if (m_client) {
        m_client->write(data.rawData());
    }
}

void HistoryWorker::handleHistoryHashUpdate(const IPackage& package) const
{
    const auto newHash = package.data().value<quint64>();
    if (!isValidHash(newHash)) {
        requestCommandHashes();
    }
}

void HistoryWorker::onHistoryChanged()
{
    m_historyHash.calculate(*m_pHistory);
    sendHashUpdate();
}

void HistoryWorker::sendHashUpdate() const
{
    BasicPackage package {QVariant::fromValue(m_historyHash.totalHash()),
                            networking::PType::HISTORY_HASH_UPDATE};
    notifyClient(package);
}
