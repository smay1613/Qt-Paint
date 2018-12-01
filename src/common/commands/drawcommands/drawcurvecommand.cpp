#include "drawcurvecommand.h"
#include "../../strategies/drawcurvestrategy.h"

DrawCurveCommand::DrawCurveCommand(QPainter *painter)
    : DrawCommand(painter, std::make_unique<DrawCurveStrategy>())
{
}
