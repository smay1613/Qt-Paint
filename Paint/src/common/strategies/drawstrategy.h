#ifndef DRAWSTRATEGY_H
#define DRAWSTRATEGY_H
#include "../painttypes.h"
#include <QPainter>
#include <QMouseEvent>

class IDrawStrategy
{
public:
    IDrawStrategy() = default;
    virtual ~IDrawStrategy() {}

    virtual void drawRequest(QPainter* painter) = 0;
    virtual void mouseTouch(const QMouseEvent& state, bool paintStarted) = 0;

    virtual QVariant getData() const = 0;
};

#endif // DRAWSTRATEGY_H
