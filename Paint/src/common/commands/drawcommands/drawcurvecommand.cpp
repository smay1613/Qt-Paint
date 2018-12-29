#include "drawcurvecommand.h"
#include "../../strategies/drawcurvestrategy.h"

DrawCurveCommand::DrawCurveCommand(QPainter *painter)
    : DrawCommand(painter, std::make_unique<DrawCurveStrategy>())
{
}

PaintTypes::ShapeType DrawCurveCommand::type() const
{
    return PaintTypes::ShapeType::Curve;
}
