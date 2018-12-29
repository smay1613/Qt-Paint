#ifndef DRAWLINECOMMAND_H
#define DRAWLINECOMMAND_H
#include "../drawcommand.h"

class DrawLineCommand : public DrawCommand
{
public:
    explicit DrawLineCommand(QPainter* painter);

    PaintTypes::ShapeType type() const;
};

#endif // DRAWLINECOMMAND_H
