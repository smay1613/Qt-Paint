#ifndef DRAWLINECOMMAND_H
#define DRAWLINECOMMAND_H
#include "../drawcommand.h"

class DrawLineCommand : public DrawCommand
{
    Q_OBJECT
public:
    explicit DrawLineCommand(QPainter* painter);
};

#endif // DRAWLINECOMMAND_H
