#include "drawrectanglestrategy.h"

void DrawRectangleStrategy::drawRequest(QPainter *painter)
{
    painter->drawRect(m_bounds.getRect());
}

void DrawRectangleStrategy::mouseTouch(const PaintTypes::MouseState &state, bool paintStarted)
{
    if (!paintStarted) {
        m_bounds.setStart({static_cast<qreal>(state.m_x), static_cast<qreal>(state.m_y)});
    } else {
        m_bounds.setEnd({static_cast<qreal>(state.m_x), static_cast<qreal>(state.m_y)});
    }
}
