#ifndef BASICSHAPE_H
#define BASICSHAPE_H
#include <QRect>
#include <QLine>
#include <QMetaType>

class BoundedShape
{
public:
    BoundedShape() = default;
    virtual ~BoundedShape() = default;

    void setStart(const QPoint& startPoint);
    void setEnd(const QPoint& endPoint);

    const QRect getRect() const;

protected:
    QLine m_diagonal;
};

Q_DECLARE_METATYPE(BoundedShape)

#endif // BASICSHAPE_H
