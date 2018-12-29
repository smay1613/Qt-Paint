#include "drawlinecommand.h"
#include "../../strategies/drawlinestrategy.h"
#include <QDebug>

DrawLineCommand::DrawLineCommand(QPainter* painter)
    : DrawCommand (painter, std::make_unique<DrawLineStrategy>())
{
}

PaintTypes::ShapeType DrawLineCommand::type() const
{
    return PaintTypes::ShapeType::Line;
}

