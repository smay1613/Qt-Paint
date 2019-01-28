#include "drawcommand.h"
#include "../builders/drawstrategyfactory.h"
#include <QDebug>

DrawCommand::DrawCommand(QPainter* painter, PaintTypes::ShapeType type)
                : m_painter {painter},
                  m_type {type},
                  m_drawStrategy {DrawStrategyFactory::createDrawStrategy(type)}
{

}

void DrawCommand::execute(const QMouseEvent& mouseState, bool paintStarted)
{
    if (m_drawStrategy) {
        m_drawStrategy->mouseTouch(mouseState, paintStarted);
        emit updateRequested();
    } else {
        qWarning() << "Execute - drawStrategy is null!";
    }
}

void DrawCommand::execute()
{
    if (m_painter && m_painter->isActive()) {
        if (m_drawStrategy) {
            m_drawStrategy->drawRequest(m_painter);
        } else {
            qWarning() << "DrawCommand::execute - drawStrategy is null!";
        }
    } else {
        qWarning() << "DrawCommand::draw - painter is not active!";
    }
}

void DrawCommand::setPainter(QPainter *painter)
{
    m_painter = painter;
}

QPen DrawCommand::pen() const
{
    return m_pen;
}

void DrawCommand::setPen(const QPen &pen)
{
    m_pen = pen;
}

DrawCommandMemento DrawCommand::getMemento() const
{
    auto strategyData = m_drawStrategy ? m_drawStrategy->getData() : QVariant {};
    return DrawCommandMemento {strategyData, m_pen, m_type};
}

PaintTypes::ShapeType DrawCommand::type() const
{
    return m_type;
}

void DrawCommand::retrieveMemento(const DrawCommandMemento& memento)
{
    m_pen = memento.m_pen;
    m_drawStrategy->setData(memento.m_strategyVariant);
}
