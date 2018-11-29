#include "drawcurvecommand.h"
#include "../../strategies/drawcurvestrategy.h"

DrawCurveCommand::DrawCurveCommand(QPainter *painter)
    : DrawCommand(painter)
{
    m_drawStrategy = std::make_unique<DrawCurveStrategy>();
}
