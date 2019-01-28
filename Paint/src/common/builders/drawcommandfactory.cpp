#include "drawcommandfactory.h"
#include "../commands/drawcommand.h"
#include "../../toolbar/settings/paintsettings.h"
#include <QDebug>

std::unique_ptr<DrawCommand> DrawCommandFactory::createActiveCommandFromSettings(QPainter *painter)
{
    PaintTypes::ShapeType activeShapeType = PaintSettings::instance().activeShapeType();

    return createCommandByType(painter, activeShapeType);
}

std::unique_ptr<DrawCommand> DrawCommandFactory::createCommandByType(QPainter *painter, PaintTypes::ShapeType type)
{
    return std::make_unique<DrawCommand>(painter, type);
}


