#ifndef PAINTBRUSHBUILDER_H
#define PAINTBRUSHBUILDER_H
#include <QPen>

class PaintPenBuilder
{
public:
    PaintPenBuilder() = default;

    const QPen getActivePen() const;
};

#endif // PAINTBRUSHBUILDER_H
