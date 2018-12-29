#include "drawcommandfactory.h"
#include "../commands/drawcommands/drawcurvecommand.h"
#include "../commands/drawcommands/drawcirclecommand.h"
#include "../commands/drawcommands/drawrectanglecommand.h"
#include "../commands/drawcommands/drawlinecommand.h"
#include "../../toolbar/settings/paintsettings.h"
#include <QDebug>

std::unique_ptr<DrawCommand> DrawCommandFactory::createActiveCommandFromSettings(QPainter *painter) const
{
    PaintTypes::ShapeType activeShapeType = PaintSettings::instance().activeShapeType();

    return createCommandByType(painter, activeShapeType);
}

std::unique_ptr<DrawCommand> DrawCommandFactory::createCommandByType(QPainter *painter, PaintTypes::ShapeType type) const
{
    switch(type)
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
