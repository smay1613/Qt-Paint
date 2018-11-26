#ifndef SPLINESHAPE_H
#define SPLINESHAPE_H
#include <list>
#include <QPointF>
#include <QPainterPath>

class SplineShape
{
public:
    SplineShape();
    void addPoint(const QPointF point);
    const QPainterPath getPath() const;

private:
    std::list<QPointF> m_points;
    QPainterPath m_activePath;

    const unsigned int m_segmentPointCount;
    bool m_isEmpty;
};

#endif // SPLINESHAPE_H
