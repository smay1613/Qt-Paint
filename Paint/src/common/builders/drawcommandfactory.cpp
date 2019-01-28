#include "drawcommandfactory.h"
#include "../commands/drawcommand.h"
#include "../../toolbar/settings/paintsettings.h"

std::unique_ptr<DrawCommand> DrawCommandFactory::createCommandByType(QPainter *painter, PaintTypes::ShapeType type)
{
    return std::make_unique<DrawCommand>(painter, type);
}


