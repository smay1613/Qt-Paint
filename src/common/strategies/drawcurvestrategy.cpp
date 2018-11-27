#include "drawcurvestrategy.h"
#include <QDebug>

DrawCurveStrategy::DrawCurveStrategy()
{

}

void DrawCurveStrategy::drawRequest(QPainter *painter)
{
    painter->drawPath(m_spline.getPath());
}

void DrawCurveStrategy::mouseTouch(const MouseState &state, bool paintStarted)
{
    if (paintStarted && state.m_pressed) {
        m_spline.addPoint({static_cast<qreal>(state.m_x), static_cast<qreal>(state.m_y)});
    }
}