#ifndef HISTORYHASH_H
#define HISTORYHASH_H
#include "../../common/drawhistory/history.h"
#include <QVector>

class HistoryHash
{
public:
    uint64_t totalHash() const;
    QVector<quint64> commandHashes() const;

    void calculate(const IHistory& history);

private:
    void updateHash(const IHistory& history);

    uint64_t m_totalHash;
    QVector<quint64> m_commandHashes;
};

#endif // HISTORYHASH_H
