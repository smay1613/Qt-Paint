#include "drawrectanglestrategy.h"

void DrawRectangleStrategy::drawRequest(QPainter *painter)
{
    painter->drawRect(m_bounds.getRect());
}

void DrawRectangleStrategy::mouseTouch(const PaintTypes::MouseState &state, bool paintStarted)
{
    if (!paintStarted) {
        m_bounds.setStart({state.m_x, state.m_y});
    } else {
        m_bounds.setEnd({state.m_x, state.m_y});
    }
}
