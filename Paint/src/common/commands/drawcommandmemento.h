#ifndef DRAWCOMMANDMEMENTO_H
#define DRAWCOMMANDMEMENTO_H
#include <QVariant>
#include <QPen>

class DrawCommandMemento
{
public:
    DrawCommandMemento() = default;
    DrawCommandMemento(QVariant strategy, QPen pen);

    friend QDataStream& operator>> (QDataStream& stream, DrawCommandMemento& memento);
    friend QDataStream& operator<< (QDataStream& stream, const DrawCommandMemento& memento);

private:
    QVariant m_strategyVariant;
    QPen m_pen;
};

Q_DECLARE_METATYPE(DrawCommandMemento)
#endif // DRAWCOMMANDMEMENTO_H
