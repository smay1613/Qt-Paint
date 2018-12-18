#ifndef BASICPACKAGE_H
#define BASICPACKAGE_H
#include <QDataStream>
#include "ipackage.h"

class BasicPackage : public IPackage
{
public:
    BasicPackage() = default;
    BasicPackage(QDataStream &data, networking::PType type = networking::PType::INVALID);
    virtual ~BasicPackage() override = default;

    networking::PType type() const override;
    QVariant data() const override;

    friend QDataStream& operator<< (QDataStream& stream, const BasicPackage& package);
    friend QDataStream& operator>> (QDataStream& stream, BasicPackage& package);

protected:
    QVariant m_data;
    networking::PType m_type;
};

#endif // BASICPACKAGE_H
