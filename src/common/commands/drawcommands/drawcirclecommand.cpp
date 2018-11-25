#include "drawcirclecommand.h"
#include "../../strategies/drawcirclestrategy.h"
#include <QDebug>

DrawCircleCommand::DrawCircleCommand(QPainter* painter)
    : DrawCommand (painter)
{
    m_drawStrategy.reset(new DrawCircleStrategy());
}
