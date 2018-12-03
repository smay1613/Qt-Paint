#ifndef DRAWLINESTRATEGY_H
#define DRAWLINESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/lineshape.h"
#include <QPainter>

class DrawLineStrategy : public IDrawStrategy
{
public:
    DrawLineStrategy() = default;

    void drawRequest(QPainter* painter) override;
    void mouseTouch(const QMouseEvent& state, bool paintStarted) override;

private:
    LineShape m_line;
};

#endif // DRAWLINESTRATEGY_H
