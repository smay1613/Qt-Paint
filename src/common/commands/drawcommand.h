#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H
#include "command.h"
#include <QPainter>
#include <QObject>
#include <memory>
#include "../painttypes.h"
#include "../strategies/drawstrategy.h"

class DrawCommand : public QObject, public ICommand
{
    Q_OBJECT
public:
    explicit DrawCommand(QPainter* painter);
    virtual ~DrawCommand() = default;

    void execute() final;
    virtual void execute(const PaintTypes::MouseState& mouseState, bool paintStarted);
    virtual void draw() const;

    void setPainter(QPainter *painter);

signals:
    void updateRequested();

protected:
    QPainter* m_painter;
    std::unique_ptr<IDrawStrategy> m_drawStrategy;
};

#endif // DRAWCOMMAND_H
