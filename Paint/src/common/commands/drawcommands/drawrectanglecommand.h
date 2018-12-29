#ifndef DRAWRECTANGLECOMMAND_H
#define DRAWRECTANGLECOMMAND_H
#include "../drawcommand.h"

class DrawRectangleCommand : public DrawCommand
{
public:
    explicit DrawRectangleCommand(QPainter* painter);
    PaintTypes::ShapeType type() const;
};

#endif // DRAWRECTANGLECOMMAND_H
