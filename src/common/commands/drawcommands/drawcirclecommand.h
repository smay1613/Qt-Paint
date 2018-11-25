#ifndef DRAWCIRCLECOMMAND_H
#define DRAWCIRCLECOMMAND_H
#include "../drawcommand.h"

class DrawCircleCommand : public DrawCommand
{
public:
    explicit DrawCircleCommand(QPainter* painter);
};

#endif // DRAWCIRCLECOMMAND_H
