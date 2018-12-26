#include "boundedshape.h"
#include <utility>
#include <QDebug>

void BoundedShape::setStart(const QPoint& startPoint)
{
    m_diagonal.setP1(startPoint);
    m_diagonal.setP2(startPoint);
}

void BoundedShape::setEnd(const QPoint& endPoint)
{
    m_diagonal.setP2(endPoint);
}

const QRect BoundedShape::getRect() const
{
    QPoint topLeft;
    QPoint bottomRight;
    bool isP1LeftTop = (m_diagonal.p1().x() >= m_diagonal.p2().x()) &&
                            (m_diagonal.p1().y() >= m_diagonal.p2().y());

    topLeft = isP1LeftTop ? m_diagonal.p1() : m_diagonal.p2();
    bottomRight = isP1LeftTop ? m_diagonal.p2() : m_diagonal.p1();

    if (topLeft.isNull() && bottomRight.isNull()) {
        return QRect {};
    }

    return QRect {topLeft, bottomRight};
}

QDataStream& operator>>(QDataStream &stream, BoundedShape& shape)
{
    return stream >> shape.m_diagonal;
}

QDataStream& operator<<(QDataStream &stream, const BoundedShape& shape)
{
    return stream << shape.m_diagonal;
}
