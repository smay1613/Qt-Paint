#include "basicpackage.h"

BasicPackage::BasicPackage(QDataStream &data, networking::PType type)
    : m_data {data},
      m_type {type}
{

}

networking::PType BasicPackage::type() const
{
    return m_type;
}

QDataStream& operator<<(QDataStream& stream, const BasicPackage& package)
{
    stream << static_cast<qint32>(package.m_type);
    stream << package.m_data;
    return stream;
}

QDataStream& operator>>(QDataStream& stream, BasicPackage& package)
{
    auto type = static_cast<qint32>(package.m_type);
    stream >> type;
    stream >> package.m_data;
    return stream;
}

QVariant BasicPackage::data() const
{
    return m_data;
}
