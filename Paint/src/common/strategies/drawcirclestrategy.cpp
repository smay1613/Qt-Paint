#include "drawcirclestrategy.h"
#include <QDebug>

void DrawCircleStrategy::drawRequest(QPainter *painter)
{
    painter->drawEllipse(m_bounds.getRect());
}

void DrawCircleStrategy::mouseTouch(const QMouseEvent& state, bool paintStarted)
{
    if (!paintStarted) {
        m_bounds.setStart(state.pos());
    } else {
        m_bounds.setEnd(state.pos());
    }
}

QVariant DrawCircleStrategy::getData() const
{
    return QVariant::fromValue(m_bounds);
}
