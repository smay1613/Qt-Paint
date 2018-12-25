#ifndef DRAWCOMMANDMEMENTO_H
#define DRAWCOMMANDMEMENTO_H
#include <QVariant>
#include <QPen>

class DrawCommandMemento
{
public:
    DrawCommandMemento(const QVariant& strategy, const QPen& pen);

private:
    QVariant m_strategyVariant;
    QPen m_pen;
};

#endif // DRAWCOMMANDMEMENTO_H
