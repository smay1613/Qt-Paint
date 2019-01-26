#include "historyhash.h"
#include <QHash>

void HistoryHash::updateHash(const IHistory& history)
{
    m_totalHash = 0;

    QVector<quint64> newHashes (static_cast<int>(history.size()));

    for (const auto& command : history) {
        m_totalHash ^= qHash(command.get());
        newHashes.append(qHash(command.get()));
    }

    m_commandHashes.swap(newHashes);
}

QVector<quint64> HistoryHash::commandHashes() const
{
    return m_commandHashes;
}

void HistoryHash::calculate(const IHistory& history)
{
    updateHash(history);
}

uint64_t HistoryHash::totalHash() const
{
    return m_totalHash;
}
