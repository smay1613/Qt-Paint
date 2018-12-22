#ifndef NETWORKINGTYPES_H
#define NETWORKINGTYPES_H
#include <QObject>
#include <QVariant>

namespace networking
{
Q_NAMESPACE

enum ConnectionMode {
    Slave,
    Master
};

enum Status {
    Success,
    Failure
};

namespace utils {
struct UtilTools {
    template<class T>
    static QString socketEnumTostring(const T socketError) {
        return QVariant::fromValue(socketError).toString();
    }
};
}

Q_ENUM_NS(ConnectionMode)
}

#endif // NETWORKINGTYPES_H
