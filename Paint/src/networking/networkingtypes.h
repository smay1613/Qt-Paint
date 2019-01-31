#ifndef NETWORKINGTYPES_H
#define NETWORKINGTYPES_H
#include <QObject>
#include <QVariant>
#include <QDataStream>

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

    static QByteArray qVariantToByteArray(const QVariant& var) {
        QByteArray rawData;
        QDataStream stream {&rawData, QIODevice::WriteOnly};
        stream.setVersion(QDataStream::Qt_5_9);
        stream << var;
        return rawData;
    }
};
}

Q_ENUM_NS(ConnectionMode)
}

#endif // NETWORKINGTYPES_H
