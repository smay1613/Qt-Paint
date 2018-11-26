#ifndef WORKAREASERVERIMPL_H
#define WORKAREASERVERIMPL_H
#include <QObject>
#include <QPainter>
#include "../common/drawhistory/drawhistory.h"

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

private:
    void connectActiveCommand();
    void updatePainter(QPainter* painter);

    bool m_paintStarted;
    QPainter* m_painter;
    std::unique_ptr<DrawCommand> m_activeCommand;

    DrawHistory m_history;
};

#endif // WORKAREASERVERIMPL_H
