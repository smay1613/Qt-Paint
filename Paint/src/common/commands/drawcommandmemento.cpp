#include "drawcommandmemento.h"
#include "../../networking/networkingtypes.h"

DrawCommandMemento::DrawCommandMemento(QVariant strategy, QPen pen, PaintTypes::ShapeType type)
    : m_strategyVariant {std::move(strategy)},
      m_pen {std::move(pen)},
      m_type {std::move(type)}
{
}

size_t DrawCommandMemento::getHash() const
{
    const auto& strategyData = networking::utils::UtilTools::qVariantToByteArray(m_strategyVariant);
    const auto& penData = networking::utils::UtilTools::qVariantToByteArray(m_pen);
    return qHash(m_type) ^
            qHashBits(strategyData.data(), strategyData.size()) ^
            qHashBits(penData.data(), penData.size());
}

PaintTypes::ShapeType DrawCommandMemento::type() const
{
    return m_type;
}

QDataStream& operator>>(QDataStream &stream, DrawCommandMemento& memento)
{
    qint32 type;
    stream >> type;
    memento.m_type = static_cast<PaintTypes::ShapeType>(type);
    stream >> memento.m_strategyVariant;
    stream >> memento.m_pen;
    return stream;
}

QDataStream& operator<<(QDataStream &stream, const DrawCommandMemento& memento)
{
    return stream << static_cast<qint32>(memento.m_type) << memento.m_strategyVariant << memento.m_pen;
}
