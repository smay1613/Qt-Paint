#ifndef WORKAREASERVERIMPL_H
#define WORKAREASERVERIMPL_H
#include <QMouseEvent>
#include "workareaimpl.h"
#include "../common/builders/paintpenbuilder.h"
#include "../toolbar/adaptors/actionmanageradaptor.h"
#include "../toolbar/settings/paintsettings.h"

class WorkAreaServerImpl : public WorkAreaImpl
{
    Q_OBJECT
public:
    WorkAreaServerImpl();

    void submit();

    void onMouseMoved(const QMouseEvent* event) override;
    void onMousePressed(const QMouseEvent* event) override;
    void onMouseReleased(const QMouseEvent* event) override;

signals:
    void activeCommandChanged(const DrawCommandMemento& activeCommandMemento);

private slots:
    void onActiveCommandSettingsChanged();
    void onActivePenSettingsChanged();

private:
    void connectSignals();
    void connectActiveCommand();

    void updatePainter(QPainter* painter);

    void updateActiveCommand();
    void updateActivePen();

    bool m_paintStarted;

    PaintPenBuilder m_penBuilder;

    PaintSettings& m_rPaintSettings;
};

#endif // WORKAREASERVERIMPL_H
