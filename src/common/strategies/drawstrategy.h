#ifndef DRAWSTRATEGY_H
#define DRAWSTRATEGY_H
#include "../painttypes.h"
#include <QPainter>

class IDrawStrategy
{
public:
    IDrawStrategy();
    virtual ~IDrawStrategy() {}

    virtual void drawRequest(QPainter* painter) = 0;
    virtual void mouseTouch(const PaintTypes::MouseState& state, bool paintStarted) = 0;
};

#endif // DRAWSTRATEGY_H
