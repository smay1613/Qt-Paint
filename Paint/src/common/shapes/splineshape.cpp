#include "splineshape.h"
#include <QDebug>

SplineShape::SplineShape() :
    m_pointsCount {0},
    m_segmentPointCount {3},
    m_isEmpty(true)
{

}

void SplineShape::addPoint(const QPoint& point)
{
    if (m_isEmpty) {
        m_activePath.moveTo(point);
        m_isEmpty = false;
    }

    if (m_pointsCount >= m_segmentPointCount) {
        m_activePath.lineTo(point);
        m_pointsCount = 0;
    }

    ++m_pointsCount;
}

const QPainterPath SplineShape::getPath() const
{
    return m_activePath;
}

QDataStream& operator<<(QDataStream &stream, const SplineShape& shape)
{
    return stream << shape.m_activePath;
}

QDataStream& operator>>(QDataStream &stream, SplineShape& shape)
{
    return stream >> shape.m_activePath;
}
