#include "historyhash.h"

HistoryHash::HistoryHash()
      : m_pHistory {nullptr},
        m_totalHash {0}
{
}

void HistoryHash::trackHistory(DrawHistory *history)
{
    m_pHistory = history; // here should be a disconnect...but hope it will work
    if (m_pHistory != nullptr) {
        connect(m_pHistory, &DrawHistory::historyChanged,
                    this, &HistoryHash::onHistoryChanged);
    }
}

void HistoryHash::onHistoryChanged()
{
    updateHash();
}

void HistoryHash::updateHash()
{
    m_totalHash = 0;

    std::vector<uint64_t> newHashes(m_pHistory->size());

    for (const auto& command : *m_pHistory) {
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
