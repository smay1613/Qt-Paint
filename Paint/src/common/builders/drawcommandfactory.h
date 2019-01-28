#ifndef DRAWCOMMANDFACTORY_H
#define DRAWCOMMANDFACTORY_H
#include "../commands/drawcommand.h"

class DrawCommandFactory
{
public:
    static std::unique_ptr<DrawCommand> createCommandByType(QPainter* painter, PaintTypes::ShapeType type);
};

#endif // COMMANDBUILDER_H
