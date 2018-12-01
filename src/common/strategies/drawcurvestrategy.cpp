#include "drawcurvestrategy.h"
#include <QDebug>

void DrawCurveStrategy::drawRequest(QPainter *painter)
{
    painter->drawPath(m_spline.getPath());
}

void DrawCurveStrategy::mouseTouch(const PaintTypes::MouseState &state, bool paintStarted)
{
    if (paintStarted && state.m_pressed) {
        m_spline.addPoint({state.m_x, state.m_y});
    }
}
