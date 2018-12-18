#include "drawcirclecommand.h"
#include "../../strategies/drawcirclestrategy.h"
#include <QDebug>

DrawCircleCommand::DrawCircleCommand(QPainter* painter)
    : DrawCommand (painter, std::make_unique<DrawCircleStrategy>())
{
}
