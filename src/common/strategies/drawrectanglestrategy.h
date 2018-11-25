#ifndef DRAWRECTANGLESTRATEGY_H
#define DRAWRECTANGLESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/boundedshape.h"

class DrawRectangleStrategy : public IDrawStrategy
{
public:
    DrawRectangleStrategy();
    virtual void drawRequest(QPainter* painter);
    virtual void mouseTouch(const MouseState& state, bool paintStarted);

private:
    BoundedShape m_bounds;
};

#endif // DRAWRECTANGLESTRATEGY_H
