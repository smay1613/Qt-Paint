#include "drawcirclestrategy.h"
#include <QDebug>

void DrawCircleStrategy::drawRequest(QPainter *painter)
{
    painter->drawEllipse(m_bounds.getRect());
}

void DrawCircleStrategy::mouseTouch(const PaintTypes::MouseState &state, bool paintStarted)
{
    if (!paintStarted) {
        m_bounds.setStart({state.m_x, state.m_y});
    } else {
        m_bounds.setEnd({state.m_x, state.m_y});
    }
}
