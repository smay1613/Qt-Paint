#include "drawcirclestrategy.h"

DrawCircleStrategy::DrawCircleStrategy()
{

}

void DrawCircleStrategy::drawRequest(QPainter *painter)
{
    painter->drawEllipse(m_bounds.getRect());
}

void DrawCircleStrategy::mouseTouch(const MouseState &state, bool paintStarted)
{
    if (!paintStarted) {
        m_bounds.setStart({static_cast<qreal>(state.m_x), static_cast<qreal>(state.m_y)});
    } else {
        m_bounds.setEnd({static_cast<qreal>(state.m_x), static_cast<qreal>(state.m_y)});
    }
}
