#include "clientservermanager.h"

void ClientServerManager::setHistory(DrawHistory* history)
{
    m_historyHash.trackHistory(history);
}
