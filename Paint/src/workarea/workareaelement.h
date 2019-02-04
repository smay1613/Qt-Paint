#ifndef WORKAREA_H
#define WORKAREA_H
#include <QQuickPaintedItem>
#include <memory>
#include "workareaimpl.h"

/*! \class WorkAreaElement
    \brief QML element used for drawing.
    \details All drawings related things are encapsulated in WorkAreaImpl,
    because it must change it's behavior dynamically based on connection mode.
*/

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
    //! Changes the implementation at runtime
    void onConnectionModeChanged();

private:
    void connectSignals();
    void setDefaultPaintSettings();
    std::unique_ptr<WorkAreaImpl> m_workAreaBL;
    QPainter* m_painter;
};

#endif // WORKAREA_H
