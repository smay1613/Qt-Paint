#include "drawrectanglestrategy.h"

void DrawRectangleStrategy::drawRequest(QPainter *painter)
{
    painter->drawRect(m_bounds.getRect());
}

void DrawRectangleStrategy::mouseTouch(const QMouseEvent &state, bool paintStarted)
{
    if (!paintStarted) {
        m_bounds.setStart(state.pos());
    } else {
        m_bounds.setEnd(state.pos());
    }
}

QVariant DrawRectangleStrategy::getData() const
{
    return QVariant::fromValue(m_bounds);
}

void DrawRectangleStrategy::setData(const QVariant &data)
{
    m_bounds = data.value<BoundedShape>();
}
