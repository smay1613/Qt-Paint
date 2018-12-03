#include "drawcurvestrategy.h"
#include <QDebug>

void DrawCurveStrategy::drawRequest(QPainter *painter)
{
    painter->drawPath(m_spline.getPath());
}

void DrawCurveStrategy::mouseTouch(const QMouseEvent& state, bool paintStarted)
{
    if (paintStarted && state.buttons() == Qt::LeftButton) {
        m_spline.addPoint(state.pos());
    }
}
