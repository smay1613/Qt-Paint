#include "workareaserverimpl.h"
#include <QDebug>
#include "../common/painttypes.h"
#include "../common/commands/drawcommands/drawcurvecommand.h"

WorkAreaServerImpl::WorkAreaServerImpl()
    : m_paintStarted(false),
      m_painter(nullptr),
      m_rActionManager(ActionManagerAdaptor::instance())
{
    updateActiveCommand();
    updateActivePen();

    connectSignals();
}

void WorkAreaServerImpl::submit()
{
    if (m_activeCommand) {
        m_history.add(std::move(m_activeCommand));
        updateActionsAvailability();
    }
    updateActiveCommand();
}

void WorkAreaServerImpl::onMouseMoved(const QMouseEvent* event)
{
    if (m_activeCommand && m_paintStarted) {
        m_activeCommand->execute(*event, m_paintStarted);
    }
}

void WorkAreaServerImpl::onMousePressed(const QMouseEvent* event)
{
    m_paintStarted = !m_paintStarted;

    if (m_activeCommand) {
        m_activeCommand->execute(*event, !m_paintStarted);
    }

    if (!m_paintStarted) {
        submit();
    }
}

void WorkAreaServerImpl::onMouseReleased(const QMouseEvent *event)
{
    if (m_paintStarted) {
        onMousePressed(event);
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

void WorkAreaServerImpl::onActiveCommandSettingsChanged()
{
    updateActiveCommand();
}

void WorkAreaServerImpl::onActivePenSettingsChanged()
{
    updateActivePen();
}

void WorkAreaServerImpl::onUndoRequested()
{
    m_history.undo();
    updateActionsAvailability();
    emit updateRequested();
}

void WorkAreaServerImpl::onRedoRequested()
{
    m_history.redo();
    updateActionsAvailability();
    emit updateRequested();
}

void WorkAreaServerImpl::onClearRequested()
{
    m_history.clear();
    updateActionsAvailability();
    emit updateRequested();
}

void WorkAreaServerImpl::connectSignals()
{
    // Connections with settings
    connect(&PaintSettings::instance(), &PaintSettings::activeShapeTypeChanged,
                this, &WorkAreaServerImpl::onActiveCommandSettingsChanged);
    connect(&PaintSettings::instance(), &PaintSettings::activeColorChanged,
                this, &WorkAreaServerImpl::onActivePenSettingsChanged);
    connect(&PaintSettings::instance(), &PaintSettings::penSizeChanged,
                this, &WorkAreaServerImpl::onActivePenSettingsChanged);

    // Connections with ActionManager
    connect(&m_rActionManager, &ActionManagerAdaptor::undoRequested,
                this, &WorkAreaServerImpl::onUndoRequested);
    connect(&m_rActionManager, &ActionManagerAdaptor::redoRequested,
                this, &WorkAreaServerImpl::onRedoRequested);
    connect(&m_rActionManager, &ActionManagerAdaptor::clearRequested,
                this, &WorkAreaServerImpl::onClearRequested);
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

    std::for_each(m_history.begin(), m_history.top(), [&](auto& command) {
        if (const auto drawCommand = dynamic_cast<DrawCommand*>(command.get())) {
            drawCommand->setPainter(m_painter);
        }
    });
}

void WorkAreaServerImpl::updateActiveCommand()
{
    m_activeCommand = m_commandBuilder.createActiveCommand(m_painter);
    updateActivePen();
    if (m_activeCommand) {
        connectActiveCommand();
    } else {
        qCritical() << "Active command is nullptr!";
    }
}

void WorkAreaServerImpl::updateActivePen()
{
    if (m_activeCommand) {
        m_activeCommand->setPen(m_penBuilder.getActivePen());
    }
}

void WorkAreaServerImpl::updateActionsAvailability()
{
    m_rActionManager.setUndoAvailable(!m_history.isEmpty() && !m_history.isOnStart());
    m_rActionManager.setRedoAvailable(!m_history.isEmpty() && !m_history.isOnTop());
}
