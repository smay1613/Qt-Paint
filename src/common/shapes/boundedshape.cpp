#include "boundedshape.h"
#include <utility>
#include <QDebug>

BoundedShape::BoundedShape()
{

}

BoundedShape::~BoundedShape()
{

}

void BoundedShape::setStart(const QPointF &startPoint)
{
    m_diagonal.setP1(startPoint);
    m_diagonal.setP2(startPoint);
}

void BoundedShape::setEnd(const QPointF &endPoint)
{
    m_diagonal.setP2(endPoint);
}

const QRectF BoundedShape::getRect() const
{
    QPointF topLeft;
    QPointF bottomRight;
    bool isP1LeftTop = (m_diagonal.p1().x() >= m_diagonal.p2().x()) &&
                            (m_diagonal.p1().y() >= m_diagonal.p2().y());

    topLeft = isP1LeftTop ? m_diagonal.p1() : m_diagonal.p2();
    bottomRight = isP1LeftTop ? m_diagonal.p2() : m_diagonal.p1();

    return QRectF {topLeft, bottomRight};
}
