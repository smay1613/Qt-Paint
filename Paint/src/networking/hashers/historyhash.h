#ifndef HISTORYHASH_H
#define HISTORYHASH_H
#include "src/common/drawhistory/drawhistory.h"

class HistoryHash : public QObject
{
    Q_OBJECT
public:
    HistoryHash(const DrawHistory& history);

    uint64_t totalHash() const;
    std::vector<uint64_t> commandHashes() const;

public slots:
    void onHistoryChanged();

private:
    void updateHash();

    const DrawHistory& m_rHistory;
    uint64_t m_totalHash;
    std::vector<uint64_t> m_commandHashes;
};

#endif // HISTORYHASH_H
