#ifndef VIEWSETTINGS_H
#define VIEWSETTINGS_H
#include <QObject>
#include <QPair>

class ViewSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(float minScale READ minScale CONSTANT)
    Q_PROPERTY(float maxScale READ maxScale CONSTANT)

    Q_PROPERTY(int resolutionWidth READ resolutionWidth WRITE setResolutionWidth NOTIFY resolutionWidthChanged)
    Q_PROPERTY(int resolutionHeight READ resolutionHeight WRITE setResolutionHeight NOTIFY resolutionHeightChanged)
public:
    static ViewSettings& instance();

    float scale() const;
    void setScale(float scale);

    float minScale() const;
    float maxScale() const;

    size_t resolutionWidth() const;
    void setResolutionWidth(const size_t& resolution);

    size_t resolutionHeight() const;
    void setResolutionHeight(const size_t& resolution);

signals:
    void scaleChanged(float scale);
    void resolutionWidthChanged(size_t resolutionWidth);
    void resolutionHeightChanged(size_t resolutionWidth);

private:
    ViewSettings();

    QPair<size_t, size_t> m_resolution;

    float m_scale;
    const float m_minScale;
    const float m_maxScale;
};

#endif // VIEWSETTINGS_H
