#include "workareaimpl.h"

WorkAreaImpl::WorkAreaImpl()
    : m_painter {nullptr}
{
}

void WorkAreaImpl::onPaint(QPainter *painter)
{
    if (m_painter != painter) {
        updatePainter(painter);
    }

    for (const auto& command : m_history) {
        if (const auto drawCommand = dynamic_cast<DrawCommand*>(command.get())) {
            m_painter->setPen(drawCommand->pen());
        }
        command->execute();
    }

    if (m_activeCommand) {
        m_painter->setPen(m_activeCommand->pen());
        m_activeCommand->execute();
    }
}

void WorkAreaImpl::updatePainter(QPainter *painter)
{
    m_painter = painter;
    if (m_activeCommand) {
        m_activeCommand->setPainter(m_painter);
    }

    std::for_each(m_history.begin(), m_history.top(), [&](auto& command) {
        if (const auto drawCommand = dynamic_cast<DrawCommand*>(command.get())) {
            drawCommand->setPainter(m_painter);
        }
    });
}
