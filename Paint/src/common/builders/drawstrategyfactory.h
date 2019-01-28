#ifndef DRAWSTRATEGYFACTORY_H
#define DRAWSTRATEGYFACTORY_H
#include <memory>
#include "../strategies/drawstrategy.h"

class DrawStrategyFactory
{
public:
    static std::unique_ptr<IDrawStrategy> createDrawStrategy(PaintTypes::ShapeType type);
};

#endif // DRAWSTRATEGYFACTORY_H
