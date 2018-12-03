#ifndef DRAWRECTANGLESTRATEGY_H
#define DRAWRECTANGLESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/boundedshape.h"

class DrawRectangleStrategy : public IDrawStrategy
{
public:
    DrawRectangleStrategy() = default;
    virtual void drawRequest(QPainter* painter);
    virtual void mouseTouch(const QMouseEvent& state, bool paintStarted) override;

private:
    BoundedShape m_bounds;
};

#endif // DRAWRECTANGLESTRATEGY_H
