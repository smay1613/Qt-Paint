#include "paintpenbuilder.h"
#include "../../toolbar/paintsettings/paintsettings.h"

const QPen PaintPenBuilder::getActivePen() const
{
    // Return value optimization must work in this case.
    const qreal size = static_cast<qreal>(PaintSettings::instance().currentPenSize());
    return QPen {PaintSettings::instance().activeColor(), size};
}
