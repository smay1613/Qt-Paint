#include "drawlinecommand.h"
#include "../../strategies/drawlinestrategy.h"
#include <QDebug>

DrawLineCommand::DrawLineCommand(QPainter* painter)
    : DrawCommand (painter)
{
    m_drawStrategy.reset(new DrawLineStrategy());
}
