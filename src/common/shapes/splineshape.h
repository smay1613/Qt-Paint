#ifndef SPLINESHAPE_H
#define SPLINESHAPE_H
#include <list>
#include <QPoint>
#include <QPainterPath>

class SplineShape
{
public:
    SplineShape();
    void addPoint(const QPoint& point);
    const QPainterPath getPath() const;

private:
    size_t m_pointsCount;
    QPainterPath m_activePath;

    const size_t m_segmentPointCount;
    bool m_isEmpty;
};

#endif // SPLINESHAPE_H
