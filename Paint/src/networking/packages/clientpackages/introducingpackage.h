#ifndef INTRODUCINGPACKAGE_H
#define INTRODUCINGPACKAGE_H
#include "../basicpackage.h"

class IntroducingPackage : public BasicPackage
{
public:
    IntroducingPackage(QDataStream &data, networking::PType type = networking::PType::INTRODUCING);
};

#endif // INTRODUCINGPACKAGE_H
