#include "commandbuilder.h"
#include "../commands/drawcommands/drawcurvecommand.h"
#include "../commands/drawcommands/drawcirclecommand.h"
#include "../commands/drawcommands/drawrectanglecommand.h"
#include "../commands/drawcommands/drawlinecommand.h"
#include <QDebug>

std::unique_ptr<DrawCommand> DrawCommandBuilder::getActiveCommand(QPainter *painter)
{
    PaintTypes::ShapeType activeShapeType = PaintSettings::instance().activeShapeType();

    switch(activeShapeType)
    {
        case PaintTypes::ShapeType::Circle:
            return std::make_unique<DrawCircleCommand>(painter);
        case PaintTypes::ShapeType::Curve:
            return std::make_unique<DrawCurveCommand>(painter);
        case PaintTypes::ShapeType::Line:
            return std::make_unique<DrawLineCommand>(painter);
        case PaintTypes::ShapeType::Rectangle:
            return std::make_unique<DrawRectangleCommand>(painter);
        default:
            qWarning() << "Invalid type of shape is set!";
            return nullptr;
    }
}
