#ifndef IPACKAGE_H
#define IPACKAGE_H
#include <QVariant>
#include "packagetypes.h"

class IPackage
{
public:
    virtual ~IPackage() = default;
    virtual networking::PType type() const = 0;
    virtual QVariant data() const = 0;
};

#endif // IPACKAGE_H
