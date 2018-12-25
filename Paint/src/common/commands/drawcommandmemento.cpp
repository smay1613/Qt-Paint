#include "drawcommandmemento.h"

DrawCommandMemento::DrawCommandMemento(const QVariant &strategy, const QPen &pen)
    : m_strategyVariant {strategy},
      m_pen {pen}
{
}
