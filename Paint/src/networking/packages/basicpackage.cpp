#include "basicpackage.h"

BasicPackage::BasicPackage(networking::PType type)
    : m_stream {&m_rawData, QIODevice::WriteOnly},
      m_type {type}
{
}

BasicPackage::BasicPackage(const QVariant &data, networking::PType type)
    : BasicPackage(type)
{
    m_stream << static_cast<qint32>(m_type) << data;
}

networking::PType BasicPackage::type() const
{
    return m_type;
}

QDataStream& operator>>(QDataStream& stream, BasicPackage& package)
{
    quint32 type;
    stream >> type;
    package.m_type = static_cast<networking::PType>(type);

    QVariant data;
    stream >> data;
    package.m_rawData = data.toByteArray();

    return stream;
}

QVariant BasicPackage::data() const
{
    return QVariant {m_rawData};
}

QByteArray BasicPackage::rawData() const
{
    return m_rawData;
}
