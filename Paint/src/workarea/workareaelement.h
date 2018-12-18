#ifndef WORKAREA_H
#define WORKAREA_H
#include <QQuickPaintedItem>
#include <memory>
#include "workareaserverimpl.h"

class WorkAreaElement : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit WorkAreaElement();
    void paint(QPainter* painter) override;

signals:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private slots:
    void onUpdateRequested();

private:
    void connectSignals();
    void setDefaultPaintSettings();
    std::unique_ptr<WorkAreaServerImpl> m_workAreaBL;
    QPainter* m_painter;
};

#endif // WORKAREA_H
