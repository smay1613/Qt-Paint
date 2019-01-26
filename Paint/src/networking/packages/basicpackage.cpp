#include "basicpackage.h"
#include <QDebug>

BasicPackage::BasicPackage(networking::PType type, const QIODevice::OpenModeFlag openMode)
    : m_translationStream {&m_rawData, QIODevice::WriteOnly},
      m_type {type},
      m_mode {openMode}
{
    m_translationStream << static_cast<qint32>(m_type);
    Q_ASSERT_X((openMode == QIODevice::OpenModeFlag::WriteOnly
                || openMode == QIODevice::OpenModeFlag::ReadOnly
                || openMode == QIODevice::OpenModeFlag::ReadWrite), "BasicPackage::BasicPackage(type, openMode)",
                                                                    "INVALID MODE PROVIDED!");
}

BasicPackage::BasicPackage(const QVariant &data, networking::PType type)
    : BasicPackage(type, QIODevice::OpenModeFlag::WriteOnly)
{
    m_translationStream << data;
}

networking::PType BasicPackage::type() const
{
    return m_type;
}

QDataStream& operator>>(QDataStream& stream, BasicPackage& package)
{
    if (package.m_mode != QIODevice::OpenModeFlag::WriteOnly) {
        quint32 type;
        stream >> type;
        package.m_type = static_cast<networking::PType>(type);

        QVariant data;
        stream >> data;
        package.m_data = data;

        if (package.m_mode == QIODevice::OpenModeFlag::ReadWrite) {
            package.m_translationStream << static_cast<qint32>(type) << data;
        }
    }

    return stream;
}

QVariant BasicPackage::data() const
{
    return m_mode == QIODevice::OpenModeFlag::WriteOnly ? QVariant {}
                                                        : m_data;
}

QByteArray BasicPackage::rawData() const
{
    return m_mode == QIODevice::OpenModeFlag::ReadOnly ? QByteArray {}
                                                        : m_rawData;
}
