#ifndef INTRODUCINGPACKAGE_H
#define INTRODUCINGPACKAGE_H
#include "../basicpackage.h"

class IntroducingPackage : public BasicPackage
{
public:
    IntroducingPackage(QDataStream &data)
        : BasicPackage (data, networking::PType::INTRODUCING) {}
};

#endif // INTRODUCINGPACKAGE_H
