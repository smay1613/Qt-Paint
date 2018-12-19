#include "paintsettings.h"
#include <QDebug>

PaintSettings::PaintSettings() :
    m_penSizeDefault {14},
    m_penSizeMin {1},
    m_penSizeMax {72},
    m_activeShapeType {PaintTypes::ShapeType::Invalid},
    m_currentPenSize {m_penSizeDefault}
{

}

int PaintSettings::currentPenSize() const
{
    return m_currentPenSize;
}

void PaintSettings::setCurrentPenSize(int currentPenSize)
{
    m_currentPenSize = currentPenSize;
    emit penSizeChanged(m_currentPenSize);
}

PaintSettings& PaintSettings::instance()
{
    static PaintSettings instance;
    return instance;
}

QColor PaintSettings::activeColor() const
{
    return m_activeColor;
}

void PaintSettings::setActiveColor(const QColor &activeColor)
{
    m_activeColor = activeColor;
    emit activeColorChanged(m_activeColor);
}

PaintTypes::ShapeType PaintSettings::activeShapeType() const
{
    return m_activeShapeType;
}

void PaintSettings::setActiveShapeType(const PaintTypes::ShapeType &shapeType)
{
    m_activeShapeType = shapeType;
    emit activeShapeTypeChanged(m_activeShapeType);
}

int PaintSettings::penSizeDefault() const
{
    return m_penSizeDefault;
}

int PaintSettings::penSizeMin() const
{
    return m_penSizeMin;
}

int PaintSettings::penSizeMax() const
{
    return m_penSizeMax;
}
