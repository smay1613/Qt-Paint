#ifndef BASICSHAPE_H
#define BASICSHAPE_H
#include <QRectF>
#include <QLineF>

class BoundedShape
{
public:
    BoundedShape();
    virtual ~BoundedShape();

    void setStart(const QPointF& startPoint);
    void setEnd(const QPointF& endPoint);

    const QRectF getRect() const;

protected:
    QLineF m_diagonal;
};

#endif // BASICSHAPE_H
