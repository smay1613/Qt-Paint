#ifndef DRAWCOMMANDMEMENTO_H
#define DRAWCOMMANDMEMENTO_H
#include <QVariant>
#include <QPen>
#include "../painttypes.h"

class DrawCommandMemento
{
public:
    DrawCommandMemento() = default;
    DrawCommandMemento(QVariant strategy, QPen pen, PaintTypes::ShapeType type);

    friend QDataStream& operator>> (QDataStream& stream, DrawCommandMemento& memento);
    friend QDataStream& operator<< (QDataStream& stream, const DrawCommandMemento& memento);

    size_t getHash() const;

    friend class DrawCommand;

    PaintTypes::ShapeType type() const;

private:
    QVariant m_strategyVariant;
    QPen m_pen;
    PaintTypes::ShapeType m_type;
};

Q_DECLARE_METATYPE(DrawCommandMemento)
#endif // DRAWCOMMANDMEMENTO_H
