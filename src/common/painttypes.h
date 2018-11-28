#ifndef PAINTTYPES_H
#define PAINTTYPES_H
#include <QObject>

namespace PaintTypes
{
Q_NAMESPACE

struct MouseState {
    int m_x;
    int m_y;
    bool m_pressed;
};

enum class ShapeType {
    Line,
    Curve,
    Circle,
    Rectangle
};

Q_ENUM_NS(ShapeType)

}
#endif // PAINTTYPES_H
