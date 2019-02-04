#ifndef DRAWCOMMANDMEMENTO_H
#define DRAWCOMMANDMEMENTO_H
#include <QVariant>
#include <QPen>
#include "../painttypes.h"
/*! \brief This class contains all DrawCommand related data for exchanging via network.
 */
class DrawCommandMemento
{
public:
    DrawCommandMemento() = default;
    DrawCommandMemento(QVariant strategy, QPen pen, PaintTypes::ShapeType type);

    friend QDataStream& operator>> (QDataStream& stream, DrawCommandMemento& memento);
    friend QDataStream& operator<< (QDataStream& stream, const DrawCommandMemento& memento);

    /*! Converts m_pen and m_strategyVariant to QByteArray and hashes it's bits.
     *! Final hash is a XOR of all hashed data. \see UtilTools::qVariantToByteArray
    */
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
