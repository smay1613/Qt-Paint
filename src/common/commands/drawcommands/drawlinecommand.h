#ifndef DRAWLINECOMMAND_H
#define DRAWLINECOMMAND_H
#include "../drawcommand.h"

class DrawLineCommand : public DrawCommand
{
public:
    explicit DrawLineCommand(QPainter* painter);
};

#endif // DRAWLINECOMMAND_H
