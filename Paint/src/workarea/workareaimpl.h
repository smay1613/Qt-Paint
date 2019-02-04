#ifndef WORKAREAIMPL_H
#define WORKAREAIMPL_H
#include <QObject>
#include <QPainter>
#include <memory>
#include "../common/drawhistory/drawhistory.h"
#include "../common/builders/drawcommandfactory.h"

class WorkAreaImpl : public QObject
{
    Q_OBJECT
public:
    WorkAreaImpl();

public slots:
    void onPaint(QPainter* painter);

public slots:
    virtual void onMouseMoved(const QMouseEvent* event) = 0;
    virtual void onMousePressed(const QMouseEvent* event) = 0;
    virtual void onMouseReleased(const QMouseEvent* event) = 0;

signals:
    void updateRequested();

protected:
    void updatePainter(QPainter* painter);

    QPainter* m_painter;
    std::unique_ptr<DrawCommand> m_activeCommand;

    DrawHistory m_history;
};

#endif // WORKAREAIMPL_H
