#ifndef PAINTTYPES_H
#define PAINTTYPES_H
#include <QObject>

namespace PaintTypes
{
Q_NAMESPACE

enum ShapeType {
    Line,
    Curve,
    Circle,
    Rectangle,
    Invalid
};

Q_ENUM_NS(ShapeType)
}
#endif // PAINTTYPES_H
