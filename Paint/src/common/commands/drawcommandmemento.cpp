#include "drawcommandmemento.h"

DrawCommandMemento::DrawCommandMemento(QVariant strategy, QPen pen)
    : m_strategyVariant {std::move(strategy)},
      m_pen {std::move(pen)}
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
