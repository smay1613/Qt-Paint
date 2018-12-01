#include "workareaserverimpl.h"
#include <QDebug>
#include "../common/painttypes.h"
#include "../common/commands/drawcommands/drawcurvecommand.h"

WorkAreaServerImpl::WorkAreaServerImpl()
    : m_paintStarted(false),
      m_painter(nullptr)
{
    updateActiveCommand();
    updateActivePen();
    connect(&PaintSettings::instance(), &PaintSettings::activeShapeTypeChanged,
                this, &WorkAreaServerImpl::onActiveCommandSettingsChanged);
    connect(&PaintSettings::instance(), &PaintSettings::activeColorChanged,
                this, &WorkAreaServerImpl::onActivePenSettingsChanged);
    connect(&PaintSettings::instance(), &PaintSettings::penSizeChanged,
                this, &WorkAreaServerImpl::onActivePenSettingsChanged);
}

void WorkAreaServerImpl::submit()
{
    if (m_activeCommand) {
        m_history.add(std::move(m_activeCommand), m_activePen);
        m_activeCommand.reset(nullptr);
    }
    updateActiveCommand();
}

void WorkAreaServerImpl::onMousePositionChanged(const int mouseX, const int mouseY, const bool mousePressed)
{
    if (m_activeCommand && m_paintStarted) {
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

void WorkAreaServerImpl::onMouseReleased(const int mouseX, const int mouseY)
{
    if (m_paintStarted) {
        onMouseClicked(mouseX, mouseY);
    } else {
        submit();
    }
}

void WorkAreaServerImpl::onPaint(QPainter *painter)
{
    if (m_painter != painter) {
        updatePainter(painter);
    }

    for (const auto& command : m_history) {
        m_painter->setPen(command.second);
        if (const auto drawCommand = dynamic_cast<DrawCommand*>(command.first.get())) {
            drawCommand->draw();
        }
    }

    if (m_activeCommand) {
        m_painter->setPen(m_activePen);
        m_activeCommand->draw();
    }
}

void WorkAreaServerImpl::onActiveCommandSettingsChanged()
{
    updateActiveCommand();
}

void WorkAreaServerImpl::onActivePenSettingsChanged()
{
    updateActivePen();
}

void WorkAreaServerImpl::connectActiveCommand()
{
    connect(m_activeCommand.get(), &DrawCommand::updateRequested,
                    this, &WorkAreaServerImpl::updateRequested);
}

void WorkAreaServerImpl::updatePainter(QPainter *painter)
{
    m_painter = painter;
    if (m_activeCommand) {
        m_activeCommand->setPainter(m_painter);
    }

    for (auto& command : m_history) {
        if (const auto drawCommand = dynamic_cast<DrawCommand*>(command.first.get())) {
            drawCommand->setPainter(m_painter);
        }
    }
}

void WorkAreaServerImpl::updateActiveCommand()
{
    m_activeCommand = m_commandBuilder.getActiveCommand(m_painter);
    if (m_activeCommand) {
        connectActiveCommand();
    } else {
        qDebug() << "Active command is nullptr!";
    }
}

void WorkAreaServerImpl::updateActivePen()
{
    m_activePen = m_penBuilder.getActivePen();
}
