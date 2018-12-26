#ifndef BASICPACKAGE_H
#define BASICPACKAGE_H
#include <QDataStream>
#include "ipackage.h"

/*
 * This class describes the protocol for transmitting data via network.
 *
 * You can only use ReadingOnly, WriteOnly and WriteRead modes.
 *
 * WRITING USAGE:
 * First, user must pack his data intro QVariant (e.g QVariant {<data>})
 * And create BasicPackage object with setting the data and the package type.
 * Class will automatically fill the raw data field with stream's help in format:
 * {qint32 type, QVariant data}.
 * After that, user can exchange this package with socket's write function by
 * calling rawData method, that will return raw data content.
 * Mode will be automatically switched to WriteOnly.
 *
 * READING USAGE:
 * Default package should be created first (NOTE: there is no sense to set the WriteOnly flag in case of
 * default creating, because it cannot be filled later) and then it could be filled with datastream.
 * Operator >> will save all data in members.
 *
 * NOTE: Data placed in QVariant must provide Datastream << and >> operator!
*/

//TODO: MAKE COMMENTS DOXYGEN STYLE
class BasicPackage : public IPackage
{
public:
    BasicPackage(networking::PType type = networking::PType::INVALID,
                     const QIODevice::OpenModeFlag openMode = QIODevice::OpenModeFlag::ReadOnly);

    BasicPackage(const QVariant& data, networking::PType type = networking::PType::INVALID);
    virtual ~BasicPackage() = default;

    networking::PType type() const override;

    // Return empty QVariant if mode is WriteOnly
    QVariant data() const override;

    // Returns empty bytearray if mode is ReadingOnly.
    QByteArray rawData() const override;

    // Will do nothing in case if mode is WriteOnly.
    friend QDataStream& operator>> (QDataStream& stream, BasicPackage& package);

protected:
    QByteArray m_rawData;
    QDataStream m_translationStream;

    networking::PType m_type;
    QVariant m_data;

    QIODevice::OpenModeFlag m_mode;
};

#endif // BASICPACKAGE_H
