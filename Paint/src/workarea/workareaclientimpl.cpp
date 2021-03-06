#include "workareaclientimpl.h"
#include "src/networking/managers/clientservermanager.h"
#include "../common/builders/drawcommandfactory.h"

WorkAreaClientImpl::WorkAreaClientImpl()
{
    connectSignals();
}

void WorkAreaClientImpl::onMouseMoved(const QMouseEvent *event)
{
    Q_UNUSED(event)
}

void WorkAreaClientImpl::onMousePressed(const QMouseEvent *event)
{
    Q_UNUSED(event)
}

void WorkAreaClientImpl::onMouseReleased(const QMouseEvent *event)
{
    Q_UNUSED(event)
}

void WorkAreaClientImpl::onActiveCommandRecieved(const DrawCommandMemento& commandMemento)
{
    if (!m_activeCommand ||
            (m_activeCommand && m_activeCommand->type() != commandMemento.type())) {
        m_activeCommand = DrawCommandFactory::createCommandByType(m_painter, commandMemento.type());
    }

    m_activeCommand->retrieveMemento(commandMemento);
    emit updateRequested();
}

void WorkAreaClientImpl::onCommandsRecieved()
{
    updatePainter(m_painter);
    emit updateRequested();
}

void WorkAreaClientImpl::connectSignals()
{
    const auto& clientServer = ClientServerManager::instance();

    connect(&clientServer, &ClientServerManager::activeCommandRecieved,
                this, &WorkAreaClientImpl::onActiveCommandRecieved);
    connect(&clientServer, &ClientServerManager::commandsRecieved,
                this, &WorkAreaClientImpl::onCommandsRecieved);
}
