#ifndef VIEWSETTINGS_H
#define VIEWSETTINGS_H
#include <QObject>

class ViewSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(float minScale READ minScale CONSTANT)
    Q_PROPERTY(float maxScale READ maxScale CONSTANT)
public:
    static ViewSettings& instance();

    float scale() const;
    void setScale(float scale);

    float minScale() const;
    float maxScale() const;

signals:
    void scaleChanged(float scale);

private:
    ViewSettings();

    float m_scale;
    const float m_minScale;
    const float m_maxScale;
};

#endif // VIEWSETTINGS_H
