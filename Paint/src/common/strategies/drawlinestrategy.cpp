#include "drawlinestrategy.h"
#include <QDebug>

void DrawLineStrategy::drawRequest(QPainter *painter)
{
    if (!m_line.getLine().isNull()) {
        painter->drawLine(m_line.getLine());
    }
}

void DrawLineStrategy::mouseTouch(const QMouseEvent &state, bool paintStarted)
{
    if (!paintStarted) {
        m_line.setStart(state.pos());
    } else {
        m_line.setEnd(state.pos());
    }
}

QVariant DrawLineStrategy::getData() const
{
    return QVariant::fromValue(m_line);
}
