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
    void mousePositionChanged(const int mouseX, const int mouseY, const bool mouseClicked);
    void mouseClicked(const int mouseX, const int mouseY);
    void mouseReleased(const int mouseX, const int mouseY);

private slots:
    void onUpdateRequested();
    void onAntialiasingChanged(bool antialiasing);

private:
    void connectSignals();
    void setDefaultPaintSettings();
    std::unique_ptr<WorkAreaServerImpl> m_workAreaBL;
    QPainter* m_painter;
};

#endif // WORKAREA_H
