#include "drawstrategyfactory.h"

#include "../strategies/drawcirclestrategy.h"
#include "../strategies/drawcurvestrategy.h"
#include "../strategies/drawlinestrategy.h"
#include "../strategies/drawrectanglestrategy.h"
#include <QDebug>

std::unique_ptr<IDrawStrategy> DrawStrategyFactory::createDrawStrategy(PaintTypes::ShapeType type)
{
    switch(type)
    {
        case PaintTypes::ShapeType::Circle:
            return std::make_unique<DrawCircleStrategy>();
        case PaintTypes::ShapeType::Curve:
            return std::make_unique<DrawCurveStrategy>();
        case PaintTypes::ShapeType::Line:
            return std::make_unique<DrawLineStrategy>();
        case PaintTypes::ShapeType::Rectangle:
            return std::make_unique<DrawRectangleStrategy>();
        default:
            qWarning() << "Invalid type of shape is set!";
            return nullptr;
    }
}
