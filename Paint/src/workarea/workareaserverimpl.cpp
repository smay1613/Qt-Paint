#include "workareaserverimpl.h"
#include <QDebug>
#include "../common/painttypes.h"
#include "src/networking/managers/clientservermanager.h"

WorkAreaServerImpl::WorkAreaServerImpl()
    : m_paintStarted {false},
      m_rPaintSettings {PaintSettings::instance()}
{
    updateActiveCommand();
    updateActivePen();

    connectSignals();
}

void WorkAreaServerImpl::submit()
{
    if (m_activeCommand) {
        m_history.add(std::move(m_activeCommand));
    }
    updateActiveCommand();
}

void WorkAreaServerImpl::onMouseMoved(const QMouseEvent* event)
{
    if (m_activeCommand && m_paintStarted) {
        m_activeCommand->execute(*event, m_paintStarted);
        emit activeCommandChanged(m_activeCommand->getMemento());
    }
}

void WorkAreaServerImpl::onMousePressed(const QMouseEvent* event)
{
    m_paintStarted = !m_paintStarted;

    if (m_activeCommand) {
        m_activeCommand->execute(*event, !m_paintStarted);
        emit activeCommandChanged(m_activeCommand->getMemento());
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

void WorkAreaServerImpl::onActiveCommandSettingsChanged()
{
    updateActiveCommand();
}

void WorkAreaServerImpl::onActivePenSettingsChanged()
{
    updateActivePen();
}

void WorkAreaServerImpl::connectSignals()
{
    // Connections with settings
    connect(&m_rPaintSettings, &PaintSettings::activeShapeTypeChanged,
                this, &WorkAreaServerImpl::onActiveCommandSettingsChanged);
    connect(&m_rPaintSettings, &PaintSettings::activeColorChanged,
                this, &WorkAreaServerImpl::onActivePenSettingsChanged);
    connect(&m_rPaintSettings, &PaintSettings::penSizeChanged,
                this, &WorkAreaServerImpl::onActivePenSettingsChanged);

    // Connections with client-server manager
    auto& clientServer = ClientServerManager::instance();
    connect(this, &WorkAreaServerImpl::activeCommandChanged,
                &clientServer, &ClientServerManager::onActiveCommandChanged);

    auto& actionManager = ActionManagerAdaptor::instance();
    actionManager.trackHistory(&m_history);
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
    m_activeCommand = DrawCommandFactory::createCommandByType(m_painter,
                                                           PaintSettings::instance().activeShapeType());
    updateActivePen();
    if (m_activeCommand) {
        connectActiveCommand();
        emit activeCommandChanged(m_activeCommand->getMemento());
    } else {
        qCritical() << "Active command is nullptr!";
    }
}

void WorkAreaServerImpl::updateActivePen()
{
    if (m_activeCommand) {
        m_activeCommand->setPen(m_penBuilder.getActivePen());
        emit activeCommandChanged(m_activeCommand->getMemento());
    }
}
