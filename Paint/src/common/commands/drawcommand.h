#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H
#include "command.h"
#include <QPainter>
#include <QObject>
#include <QMouseEvent>
#include <memory>
#include "../strategies/drawstrategy.h"
#include "drawcommandmemento.h"

class DrawCommand : public QObject, public ICommand
{
    Q_OBJECT
public:
    explicit DrawCommand(QPainter* painter, PaintTypes::ShapeType type = PaintTypes::ShapeType::Invalid);
    virtual ~DrawCommand() = default;

    virtual void execute(const QMouseEvent& mouseState, bool paintStarted);
    virtual void execute() override;

    void setPainter(QPainter *painter);

    QPen pen() const;
    void setPen(const QPen &pen);

    DrawCommandMemento getMemento() const;
    PaintTypes::ShapeType type() const;

    void retrieveMemento(const DrawCommandMemento& memento);

signals:
    void updateRequested();

private:
    QPainter* m_painter;
    QPen m_pen;
    PaintTypes::ShapeType m_type;
    std::unique_ptr<IDrawStrategy> m_drawStrategy;    
};

#endif // DRAWCOMMAND_H
