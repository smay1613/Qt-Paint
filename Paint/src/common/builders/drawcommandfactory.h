#ifndef DRAWCOMMANDFACTORY_H
#define DRAWCOMMANDFACTORY_H
#include "../commands/drawcommand.h"

class DrawCommandFactory
{
public:
    DrawCommandFactory() = default;

    std::unique_ptr<DrawCommand> createActiveCommandFromSettings(QPainter* painter) const;
    std::unique_ptr<DrawCommand> createCommandByType(QPainter* painter, PaintTypes::ShapeType type) const;
};

#endif // COMMANDBUILDER_H
