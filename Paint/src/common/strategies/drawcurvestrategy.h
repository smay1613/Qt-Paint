#ifndef DRAWCURVESTRATEGY_H
#define DRAWCURVESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/splineshape.h"

class DrawCurveStrategy : public IDrawStrategy
{
public:
    void drawRequest(QPainter* painter) override;
    void mouseTouch(const QMouseEvent &state, bool paintStarted) override;

    QVariant getData() const override;
    void setData(const QVariant& data) override;
private:
    SplineShape m_spline;
};

#endif // DRAWCURVESTRATEGY_H
