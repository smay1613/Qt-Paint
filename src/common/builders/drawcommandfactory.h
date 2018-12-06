#ifndef DRAWCOMMANDFACTORY_H
#define DRAWCOMMANDFACTORY_H
#include "../commands/drawcommand.h"
#include "../../toolbar/paintsettings/paintsettings.h"

class DrawCommandFactory
{
public:
    DrawCommandFactory() = default;

    std::unique_ptr<DrawCommand> createActiveCommand(QPainter* painter) const;
};

#endif // COMMANDBUILDER_H
