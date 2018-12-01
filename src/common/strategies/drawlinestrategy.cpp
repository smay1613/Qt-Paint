#include "drawlinestrategy.h"
#include <QDebug>

void DrawLineStrategy::drawRequest(QPainter *painter)
{
    if (!m_line.getLine().isNull()) {
        painter->drawLine(m_line.getLine());
    }
}

void DrawLineStrategy::mouseTouch(const PaintTypes::MouseState &state, bool paintStarted)
{
    if (!paintStarted) {
        m_line.setStart({state.m_x, state.m_y});
    } else {
        m_line.setEnd({state.m_x, state.m_y});
    }
}
