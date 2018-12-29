#ifndef DRAWCIRCLESTRATEGY_H
#define DRAWCIRCLESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/boundedshape.h"

class DrawCircleStrategy : public IDrawStrategy
{
public:
    void drawRequest(QPainter* painter) override;
    void mouseTouch(const QMouseEvent &state, bool paintStarted) override;

    QVariant getData() const override;
    void setData(const QVariant& data) override;
private:
    BoundedShape m_bounds;
};

#endif // DRAWCIRCLESTRATEGY_H
