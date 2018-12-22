#ifndef BASICPACKAGE_H
#define BASICPACKAGE_H
#include <QDataStream>
#include "ipackage.h"

/*
 * This class describes the protocol for transmitting data via network.
 *
 * WRITING USAGE:
 * First, user must pack his data intro QVariant (e.g QVariant {<data>})
 * And create BasicPackage object with setting the data and the package type.
 * Class will automatically fill the raw data field with stream's help in format:
 * {qint32 type, QVariant data}.
 * After that, user can exchange this package with socket's write function by
 * calling rawData method, that will return raw data content.
 *
 * READING USAGE:
 * Default package should be created first, and then it could be filled with
 * datastream. operator >> will firstly extract the package type from the datastream
 * and set it to the object m_type property (that can be used by type getter)
 * and then it will extract QVariant data and fill she raw data (conversion QVariant->ByteArray).
 * Package data can be used by data() method that will create new QVariant based on raw data.
 *
*/

class BasicPackage : public IPackage
{
public:
    BasicPackage(networking::PType type = networking::PType::INVALID);
    BasicPackage(const QVariant& data, networking::PType type = networking::PType::INVALID);
    virtual ~BasicPackage() = default;

    networking::PType type() const override;
    QVariant data() const override;

    QByteArray rawData() const;

    friend QDataStream& operator>> (QDataStream& stream, BasicPackage& package);

protected:
    QByteArray m_rawData;
    QDataStream m_stream;

    networking::PType m_type;
};

#endif // BASICPACKAGE_H
