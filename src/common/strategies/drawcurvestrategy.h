#ifndef DRAWCURVESTRATEGY_H
#define DRAWCURVESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/splineshape.h"

class DrawCurveStrategy : public IDrawStrategy
{
public:
    DrawCurveStrategy() = default;

    void drawRequest(QPainter* painter) override;
    void mouseTouch(const PaintTypes::MouseState& state, bool paintStarted) override;

private:
    SplineShape m_spline;
};

#endif // DRAWCURVESTRATEGY_H
