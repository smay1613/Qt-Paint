#include "workareaelement.h"
//#include <QBrush>
#include <QPainter>
#include <QObject>
#include <QPoint>
#include <memory>
#include "workareaserverimpl.h"

WorkAreaElement::WorkAreaElement() :
    m_workAreaBL {std::make_unique<WorkAreaServerImpl>()}
{
    connectSignals();
}

void WorkAreaElement::paint(QPainter *painter)
{
    if (m_workAreaBL) {
        m_workAreaBL->onPaint(painter);
    }
}

void WorkAreaElement::onUpdateRequested()
{
    update({QPoint {0, 0}, size().toSize()});
}

void WorkAreaElement::connectSignals()
{
    if (!m_workAreaBL) {
        qWarning() << "WorkAreaElement::connectSignals() - workAreaBl is null!";
        return;
    }

    connect(this, &WorkAreaElement::mouseClicked,
                    m_workAreaBL.get(), &WorkAreaServerImpl::onMouseClicked);
    connect(this, &WorkAreaElement::mousePositionChanged,
                    m_workAreaBL.get(), &WorkAreaServerImpl::onMousePositionChanged);

    connect(this, &WorkAreaElement::mouseReleased,
                    m_workAreaBL.get(), &WorkAreaServerImpl::onMouseReleased);

    connect(m_workAreaBL.get(), &WorkAreaServerImpl::updateRequested,
                    this, &WorkAreaElement::onUpdateRequested);
}
