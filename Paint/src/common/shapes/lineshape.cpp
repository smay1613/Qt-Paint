#include "lineshape.h"

void LineShape::setStart(const QPoint &startPoint)
{
    m_line.setPoints(startPoint, startPoint);
}

void LineShape::setEnd(const QPoint &endPoint)
{
    m_line.setP2(endPoint);
}

const QLine LineShape::getLine() const
{
    return m_line;
}

QDataStream& operator<<(QDataStream &stream, const LineShape& shape)
{
    return stream << shape.m_line;
}

QDataStream& operator>>(QDataStream &stream, LineShape& shape)
{
    return stream >> shape.m_line;
}
