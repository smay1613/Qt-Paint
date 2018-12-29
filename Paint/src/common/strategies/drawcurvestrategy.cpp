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

QVariant DrawCurveStrategy::getData() const
{
    return QVariant::fromValue(m_spline);
}

void DrawCurveStrategy::setData(const QVariant& data)
{
    m_spline = data.value<SplineShape>();
}
