#ifndef LINESHAPE_H
#define LINESHAPE_H
#include <QPoint>
#include <QLine>
#include <QMetaType>

class LineShape
{
public:
    LineShape() = default;
    void setStart(const QPoint& startPoint);
    void setEnd(const QPoint& endPoint);
    const QLine getLine() const;

private:
    QLine m_line;
};

Q_DECLARE_METATYPE(LineShape)

#endif // LINESHAPE_H
