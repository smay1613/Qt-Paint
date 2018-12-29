#ifndef SPLINESHAPE_H
#define SPLINESHAPE_H
#include <QPoint>
#include <QPainterPath>

class SplineShape
{
public:
    SplineShape();
    void addPoint(const QPoint& point);
    const QPainterPath getPath() const;

    friend QDataStream& operator>> (QDataStream& stream, SplineShape& shape);
    friend QDataStream& operator<< (QDataStream& stream, const SplineShape& shape);
private:
    size_t m_pointsCount;
    QPainterPath m_activePath;

    static const size_t m_segmentPointCount = 3;
    bool m_isEmpty;
};

Q_DECLARE_METATYPE(SplineShape)

#endif // SPLINESHAPE_H
