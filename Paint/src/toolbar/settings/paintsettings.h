#ifndef PAINTSETTINGS_H
#define PAINTSETTINGS_H
#include <QObject>
#include <QColor>
#include "../../common/painttypes.h"

class PaintSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QColor activeColor READ activeColor WRITE setActiveColor NOTIFY activeColorChanged)
    Q_PROPERTY(PaintTypes::ShapeType activeShape READ activeShapeType WRITE setActiveShapeType NOTIFY activeShapeTypeChanged)
    Q_PROPERTY(int penSize READ currentPenSize WRITE setCurrentPenSize NOTIFY penSizeChanged)

    Q_PROPERTY(int penSizeDefault READ penSizeDefault CONSTANT)
    Q_PROPERTY(int penSizeMin READ penSizeMin CONSTANT)
    Q_PROPERTY(int penSizeMax READ penSizeMax CONSTANT)

public:
    static PaintSettings& instance();

    QColor activeColor() const;
    void setActiveColor(const QColor &activeColor);

    PaintTypes::ShapeType activeShapeType() const;
    void setActiveShapeType(const PaintTypes::ShapeType &activeShapeType);

    int penSizeDefault() const;
    int penSizeMin() const;
    int penSizeMax() const;

    int currentPenSize() const;
    void setCurrentPenSize(int currentPenSize);

signals:
    void activeColorChanged(const QColor& color);
    void penSizeChanged(const int penSize);
    void activeShapeTypeChanged(const PaintTypes::ShapeType& shapeType);

private:
    PaintSettings();

    const int m_penSizeDefault;
    const int m_penSizeMin;
    const int m_penSizeMax;

    QColor m_activeColor;
    PaintTypes::ShapeType m_activeShapeType;
    int m_currentPenSize;
};

#endif // PAINTSETTINGS_H
