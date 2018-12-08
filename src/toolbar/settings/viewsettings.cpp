#include "viewsettings.h"

ViewSettings& ViewSettings::instance()
{
    static ViewSettings instance;
    return instance;
}

float ViewSettings::scale() const
{
    return m_scale;
}

void ViewSettings::setScale(float scale)
{
    if (qFuzzyCompare(m_scale, scale)) {
        return;
    }

    m_scale = scale;
    emit scaleChanged(m_scale);
}

ViewSettings::ViewSettings()
    : m_scale {1},
      m_minScale {0.1f},
      m_maxScale {5.0f}
{

}

size_t ViewSettings::resolutionWidth() const
{
    return m_resolution.first;
}

void ViewSettings::setResolutionWidth(const size_t &resolution)
{
    if (m_resolution.first != resolution) {
        m_resolution.first = resolution;
        emit resolutionWidthChanged(m_resolution.first);
    }
}

size_t ViewSettings::resolutionHeight() const
{
    return m_resolution.second;
}

void ViewSettings::setResolutionHeight(const size_t &resolution)
{
    if (m_resolution.second != resolution) {
        m_resolution.second = resolution;
        emit resolutionHeightChanged(m_resolution.second);
    }
}

float ViewSettings::maxScale() const
{
    return m_maxScale;
}

float ViewSettings::minScale() const
{
    return m_minScale;
}
