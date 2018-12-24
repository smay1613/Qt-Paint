#ifndef CLIENTSERVERMANAGER_H
#define CLIENTSERVERMANAGER_H
#include "src/networking/hashers/historyhash.h"
#include "src/common/drawhistory/drawhistory.h"

class ClientServerManager
{
public:
    ClientServerManager() = default;

    void setHistory(DrawHistory *history);

private:
    HistoryHash m_historyHash;
};

#endif // CLIENTSERVERMANAGER_H
