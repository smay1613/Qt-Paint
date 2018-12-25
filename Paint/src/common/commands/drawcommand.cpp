#include "drawcommand.h"
#include <QDebug>

DrawCommand::DrawCommand(QPainter* painter)
                : m_painter(painter)
{

}

DrawCommand::DrawCommand(QPainter *painter, std::unique_ptr<IDrawStrategy> strategy)
                : m_painter {painter},
                  m_drawStrategy {std::move(strategy)}
{

}

void DrawCommand::execute(const QMouseEvent& mouseState, bool paintStarted)
{
    if (m_drawStrategy) {
        m_drawStrategy->mouseTouch(mouseState, paintStarted);
        emit updateRequested();
    } else {
        qWarning() << "DrawLineCommand::execute - drawStrategy is null!";
    }
}

void DrawCommand::execute()
{
    if (m_painter && m_painter->isActive()) {
        m_drawStrategy->drawRequest(m_painter);
    } else {
        qWarning() << "DrawLineCommand::draw - painter is not active!";
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
    auto strategyData = m_drawStrategy->getData();
    return DrawCommandMemento {strategyData, m_pen};
}
