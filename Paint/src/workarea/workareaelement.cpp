#include "workareaelement.h"
#include <QPainter>
#include <QObject>
#include <QPoint>
#include <memory>
#include "workareaserverimpl.h"
#include "workareaclientimpl.h"
#include "src/networking/settings/connectionsettings.h"

WorkAreaElement::WorkAreaElement() :
    m_painter {nullptr}
{
    if (ConnectionSettings::instance().connectionMode() == networking::ConnectionMode::Master) {
        m_workAreaBL = std::make_unique<WorkAreaServerImpl>();
    } else {
        m_workAreaBL = std::make_unique<WorkAreaClientImpl>();
    }
    setAcceptedMouseButtons(Qt::LeftButton);
    setAntialiasing(true);
    setRenderTarget(FramebufferObject);
    connectSignals();
}

void WorkAreaElement::paint(QPainter* painter)
{
    if (m_painter != painter) {
        m_painter = painter;
        setDefaultPaintSettings();
    }
    if (m_workAreaBL) {
        m_workAreaBL->onPaint(painter);
    }
}

void WorkAreaElement::onUpdateRequested()
{
    update({QPoint {0, 0}, size().toSize()});
}

void WorkAreaElement::onConnectionModeChanged()
{
    switch (ConnectionSettings::instance().connectionMode()) {
        case networking::ConnectionMode::Master: {
            m_workAreaBL = std::make_unique<WorkAreaServerImpl>();
            break;
        }
        case networking::ConnectionMode::Slave: {
            m_workAreaBL = std::make_unique<WorkAreaClientImpl>();
            break;
        }
    }
}

void WorkAreaElement::connectSignals()
{
    if (!m_workAreaBL) {
        qWarning() << "WorkAreaElement::connectSignals() - workAreaBl is null!";
        return;
    }

    connect(this, &WorkAreaElement::mousePressEvent,
                    m_workAreaBL.get(), &WorkAreaImpl::onMousePressed);
    connect(this, &WorkAreaElement::mouseMoveEvent,
                    m_workAreaBL.get(), &WorkAreaImpl::onMouseMoved);
    connect(this, &WorkAreaElement::mouseReleaseEvent,
                    m_workAreaBL.get(), &WorkAreaImpl::onMouseReleased);

    connect(m_workAreaBL.get(), &WorkAreaImpl::updateRequested,
                    this, &WorkAreaElement::onUpdateRequested);

    connect(&ConnectionSettings::instance(), &ConnectionSettings::connectionModeChanged,
                this, &WorkAreaElement::onConnectionModeChanged);

}

void WorkAreaElement::setDefaultPaintSettings()
{
    m_painter->setRenderHint(QPainter::RenderHint::Antialiasing);
}
