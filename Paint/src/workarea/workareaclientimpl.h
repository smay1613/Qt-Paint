#ifndef WORKAREACLIENTIMPL_H
#define WORKAREACLIENTIMPL_H
#include "workareaimpl.h"

class WorkAreaClientImpl : public WorkAreaImpl
{
    Q_OBJECT
public:
    WorkAreaClientImpl();

    void onMouseMoved(const QMouseEvent* event) override; // dummies (!)
    void onMousePressed(const QMouseEvent* event) override;
    void onMouseReleased(const QMouseEvent* event) override;

private slots:
    void onActiveCommandRecieved(const DrawCommandMemento& commandMemento);

private:
    void connectSignals();
};

#endif // WORKAREACLIENTIMPL_H
