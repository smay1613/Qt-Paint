#include "historyhash.h"

HistoryHash::HistoryHash(const DrawHistory& history)
    : m_rHistory {history},
      m_totalHash {0}
{
    connect(&m_rHistory, &DrawHistory::historyChanged,
                this, &HistoryHash::onHistoryChanged);
}

void HistoryHash::onHistoryChanged()
{
    updateHash();
}

void HistoryHash::updateHash()
{
    m_totalHash = 0;

    std::vector<uint64_t> newHashes(m_rHistory.size());

    for (const auto& command : m_rHistory) {
        m_totalHash ^= qHash(command.get());
        newHashes.emplace_back(qHash(command.get()));
    }

    std::swap(m_commandHashes, newHashes);
}

std::vector<uint64_t> HistoryHash::commandHashes() const
{
    return m_commandHashes;
}

uint64_t HistoryHash::totalHash() const
{
    return m_totalHash;
}
