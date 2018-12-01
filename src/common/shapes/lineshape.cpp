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
