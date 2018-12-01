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
    std::list<QPoint> m_points;
    QPainterPath m_activePath;

    const unsigned int m_segmentPointCount;
    bool m_isEmpty;
};

#endif // SPLINESHAPE_H
