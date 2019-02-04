#ifndef DRAWSTRATEGY_H
#define DRAWSTRATEGY_H
#include "../painttypes.h"
#include <QPainter>
#include <QMouseEvent>
/*! \interface IDrawStrategy
 *  \brief Hides the real drawing implementation.
 */

class IDrawStrategy
{
public:
    IDrawStrategy() = default;
    virtual ~IDrawStrategy() {}

    virtual void drawRequest(QPainter* painter) = 0;
    virtual void mouseTouch(const QMouseEvent& state, bool paintStarted) = 0;

    //! Simulates the "memento" pattern
    virtual QVariant getData() const = 0;
    virtual void setData(const QVariant& data) = 0;
};

#endif // DRAWSTRATEGY_H
