#include "paintpenbuilder.h"
#include "../../toolbar/settings/paintsettings.h"

const QPen PaintPenBuilder::getActivePen() const
{
    // Return value optimization must work in this case.
    const auto size = static_cast<qreal>(PaintSettings::instance().currentPenSize());
    return QPen {PaintSettings::instance().activeColor(),
                    size,
                    Qt::SolidLine,
                    Qt::RoundCap,
                    Qt::RoundJoin};
}
