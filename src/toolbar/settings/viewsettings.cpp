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

float ViewSettings::maxScale() const
{
    return m_maxScale;
}

float ViewSettings::minScale() const
{
    return m_minScale;
}
