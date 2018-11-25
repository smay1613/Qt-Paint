#ifndef DRAWCURVESTRATEGY_H
#define DRAWCURVESTRATEGY_H
#include "drawstrategy.h"

class DrawCurveStrategy : public IDrawStrategy
{
public:
    DrawCurveStrategy();

    void drawRequest(QPainter* painter) override;
    void mouseTouch(const MouseState& state, bool paintStarted) override;


};

#endif // DRAWCURVESTRATEGY_H
