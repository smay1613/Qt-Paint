#ifndef NETWORKINGTYPES_H
#define NETWORKINGTYPES_H
#include <QObject>

namespace networking
{
Q_NAMESPACE

enum class ConnectionMode {
    Client,
    Server
};

Q_ENUM_NS(ConnectionMode)
}
#endif // NETWORKINGTYPES_H
