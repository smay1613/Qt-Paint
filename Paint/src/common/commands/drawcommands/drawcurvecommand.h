#ifndef DRAWCURVECOMMAND_H
#define DRAWCURVECOMMAND_H
#include "../drawcommand.h"

class DrawCurveCommand : public DrawCommand
{
public:
    explicit DrawCurveCommand(QPainter* painter);
};

#endif // DRAWCURVECOMMAND_H
