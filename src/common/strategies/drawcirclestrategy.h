#ifndef DRAWCIRCLESTRATEGY_H
#define DRAWCIRCLESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/boundedshape.h"

class DrawCircleStrategy : public IDrawStrategy
{
public:
    DrawCircleStrategy() = default;
    virtual void drawRequest(QPainter* painter);
    virtual void mouseTouch(const PaintTypes::MouseState& state, bool paintStarted);

private:
    BoundedShape m_bounds;
};

#endif // DRAWCIRCLESTRATEGY_H
