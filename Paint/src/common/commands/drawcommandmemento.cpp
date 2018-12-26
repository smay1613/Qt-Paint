#include "drawcommandmemento.h"

DrawCommandMemento::DrawCommandMemento(const QVariant &strategy, const QPen &pen)
    : m_strategyVariant {strategy},
      m_pen {pen}
{
}

QDataStream& operator>>(QDataStream &stream, DrawCommandMemento& memento)
{
    stream >> memento.m_strategyVariant;
    stream >> memento.m_pen;
    return stream;
}

QDataStream& operator<<(QDataStream &stream, const DrawCommandMemento& memento)
{
    return stream << memento.m_strategyVariant << memento.m_pen;
}
