#include "drawrectanglecommand.h"
#include "../../strategies/drawrectanglestrategy.h"
#include <QDebug>

DrawRectangleCommand::DrawRectangleCommand(QPainter* painter)
    : DrawCommand (painter, std::make_unique<DrawRectangleStrategy>())
{
}

PaintTypes::ShapeType DrawRectangleCommand::type() const
{
    return PaintTypes::ShapeType::Rectangle;
}
