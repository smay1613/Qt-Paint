#include "splineshape.h"
#include <QDebug>

SplineShape::SplineShape() :
    m_segmentPointCount {3},
    m_isEmpty(true)
{

}

void SplineShape::addPoint(const QPoint point)
{
    if (m_isEmpty) {
        m_activePath.moveTo(point);
        m_isEmpty = false;
    }

    if (m_points.size() >= m_segmentPointCount) {
        m_activePath.cubicTo(*std::next(m_points.rend(), m_segmentPointCount - 1),
                                *std::next(m_points.rend()), 
				point);
        m_points.clear();
    }

    m_points.push_back(point);
}

const QPainterPath SplineShape::getPath() const
{
    return m_activePath;
}
