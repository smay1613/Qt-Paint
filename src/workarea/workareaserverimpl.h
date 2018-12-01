#ifndef WORKAREASERVERIMPL_H
#define WORKAREASERVERIMPL_H
#include <QObject>
#include <QPainter>
#include "../common/drawhistory/drawhistory.h"
#include "../common/builders/commandbuilder.h"
#include "../common/builders/paintpenbuilder.h"

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

private:
    void connectActiveCommand();
    void updatePainter(QPainter* painter);
    void updateActiveCommand();
    void updateActivePen();

    bool m_paintStarted;
    QPainter* m_painter;
    std::unique_ptr<DrawCommand> m_activeCommand;
    QPen m_activePen;

    DrawHistory m_history;
    DrawCommandBuilder m_commandBuilder;
    PaintPenBuilder m_penBuilder;
};

#endif // WORKAREASERVERIMPL_H
