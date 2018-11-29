#ifndef LINESHAPE_H
#define LINESHAPE_H
#include <QPoint>
#include <QLineF>

class LineShape
{
public:
    LineShape() = default;
    void setStart(const QPoint& startPoint);
    void setEnd(const QPoint& endPoint);
    const QLineF getLine() const;

private:
    QLineF m_line;
};

#endif // LINESHAPE_H
