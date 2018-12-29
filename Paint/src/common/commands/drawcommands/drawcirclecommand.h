#ifndef DRAWCIRCLECOMMAND_H
#define DRAWCIRCLECOMMAND_H
#include "../drawcommand.h"

class DrawCircleCommand : public DrawCommand
{
public:
    explicit DrawCircleCommand(QPainter* painter);

    PaintTypes::ShapeType type() const;
};

#endif // DRAWCIRCLECOMMAND_H
