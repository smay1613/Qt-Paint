#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H
#include "../commands/drawcommand.h"
#include "../../toolbar/paintsettings/paintsettings.h"

class DrawCommandBuilder
{
public:
    DrawCommandBuilder() = default;

    std::unique_ptr<DrawCommand> getActiveCommand(QPainter* painter);

private:
    std::unique_ptr<DrawCommand> m_currentCommand;
};

#endif // COMMANDBUILDER_H
