#include "workareaserverimpl.h"
#include <QDebug>
#include "../common/painttypes.h"
#include "../common/commands/drawcommands/drawcirclecommand.h"

WorkAreaServerImpl::WorkAreaServerImpl()
    : m_paintStarted(false),
      m_painter(nullptr),
      m_activeCommand(new DrawCircleCommand(m_painter))
{
    connectActiveCommand();
}

void WorkAreaServerImpl::submit()
{
    if (m_activeCommand) {
        m_history.add(std::move(m_activeCommand));
        m_activeCommand.reset(nullptr);
    }
    m_activeCommand.reset(new DrawCircleCommand(m_painter));
    connectActiveCommand();
}

void WorkAreaServerImpl::onMousePositionChanged(const int mouseX, const int mouseY, const bool mousePressed)
{
    if (m_activeCommand) {
        m_activeCommand->execute({mouseX, mouseY, mousePressed}, m_paintStarted);
    }
}

void WorkAreaServerImpl::onMouseClicked(const int mouseX, const int mouseY)
{
    m_paintStarted = !m_paintStarted;

    if (m_activeCommand) {
        m_activeCommand->execute({mouseX, mouseY, true}, !m_paintStarted);
    }

    if (!m_paintStarted) {
        submit();
    }
}

void WorkAreaServerImpl::onPaint(QPainter *painter)
{
    if (m_painter != painter) {
        updatePainter(painter);
    }

    for (const auto& command : m_history) {
        static_cast<DrawCommand*>(command.get())->draw();
    }

    if (m_activeCommand) {
        m_activeCommand->draw();
    }
}

void WorkAreaServerImpl::connectActiveCommand()
{
    connect(m_activeCommand.get(), &DrawCommand::updateRequested,
                    this, &WorkAreaServerImpl::updateRequested);
}

void WorkAreaServerImpl::updatePainter(QPainter *painter)
{
    m_painter = painter;
    m_activeCommand->setPainter(m_painter);

    for (auto& command : m_history) {
        static_cast<DrawCommand*>(command.get())->setPainter(m_painter);
    }
}
