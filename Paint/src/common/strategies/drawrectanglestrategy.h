#ifndef DRAWRECTANGLESTRATEGY_H
#define DRAWRECTANGLESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/boundedshape.h"

class DrawRectangleStrategy : public IDrawStrategy
{
public:
    void drawRequest(QPainter* painter) override;
    void mouseTouch(const QMouseEvent& state, bool paintStarted) override;

    QVariant getData() const override;
private:
    BoundedShape m_bounds;
};

#endif // DRAWRECTANGLESTRATEGY_H
