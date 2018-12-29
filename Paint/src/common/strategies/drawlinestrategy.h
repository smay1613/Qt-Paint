#ifndef DRAWLINESTRATEGY_H
#define DRAWLINESTRATEGY_H
#include "drawstrategy.h"
#include "../shapes/lineshape.h"
#include <QPainter>

class DrawLineStrategy : public IDrawStrategy
{
public:
    void drawRequest(QPainter* painter) override;
    void mouseTouch(const QMouseEvent& state, bool paintStarted) override;

    QVariant getData() const override;
    void setData(const QVariant& data) override;
private:
    LineShape m_line;
};

#endif // DRAWLINESTRATEGY_H
