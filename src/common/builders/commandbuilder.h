#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H
#include "../commands/drawcommand.h"
#include "../../toolbar/paintsettings/paintsettings.h"

class DrawCommandBuilder
{
public:
    DrawCommandBuilder() = default;

    std::unique_ptr<DrawCommand> getActiveCommand(QPainter* painter) const;
};

#endif // COMMANDBUILDER_H
