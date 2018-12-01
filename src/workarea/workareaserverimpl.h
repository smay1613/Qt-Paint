#ifndef WORKAREASERVERIMPL_H
#define WORKAREASERVERIMPL_H
#include <QObject>
#include <QPainter>
#include "../common/drawhistory/drawhistory.h"
#include "../common/builders/commandbuilder.h"
#include "../common/builders/paintpenbuilder.h"
#include "../toolbar/adaptors/actionmanageradaptor.h"

class WorkAreaServerImpl : public QObject
{
    Q_OBJECT
public:
    WorkAreaServerImpl();
    void paint(QPainter* painter);

    void submit();

signals:
    void updateRequested();

public slots:
    void onMousePositionChanged(const int mouseX, const int mouseY, const bool mousePressed);
    void onMouseClicked(const int mouseX, const int mouseY);
    void onMouseReleased(const int mouseX, const int mouseY);

    void onPaint(QPainter* painter);

private slots:
    void onActiveCommandSettingsChanged();
    void onActivePenSettingsChanged();

    void onUndoRequested();
    void onRedoRequested();
    void onClearRequested();

private:
    void connectSignals();
    void connectActiveCommand();

    void updatePainter(QPainter* painter);

    void updateActiveCommand();
    void updateActivePen();

    void updateActionsAvailability();

    bool m_paintStarted;
    QPainter* m_painter;

    std::unique_ptr<DrawCommand> m_activeCommand;
    QPen m_activePen;

    DrawHistory m_history;

    DrawCommandBuilder m_commandBuilder;
    PaintPenBuilder m_penBuilder;

    ActionManagerAdaptor& m_rActionManager;
};

#endif // WORKAREASERVERIMPL_H
