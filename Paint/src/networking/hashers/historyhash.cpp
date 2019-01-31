#include "historyhash.h"
#include "../../common/commands/drawcommand.h"

void HistoryHash::updateHash(const IHistory& history)
{
    m_totalHash = 0;

    QVector<quint64> newHashes;
    newHashes.reserve(static_cast<int>(history.size()));

    for (const auto& command : history) {
        if (const auto drawCommand = dynamic_cast<DrawCommand*>(command.get())) {
            const auto& memento = drawCommand->getMemento();
            const auto hash = memento.getHash();
            m_totalHash ^= hash;
            newHashes.push_back(hash);
        }
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
