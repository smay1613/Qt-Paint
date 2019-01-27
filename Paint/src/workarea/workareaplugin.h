#ifndef WORKAREAPLUGIN_H
#define WORKAREAPLUGIN_H
#include <QQmlExtensionPlugin>
#include "workareaelement.h"
#include "../common/shapes/boundedshape.h"
#include "../common/shapes/lineshape.h"
#include "../common/shapes/splineshape.h"

class WorkAreaPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri)
    {
        qmlRegisterType<WorkAreaElement>(uri, 1, 0, "WorkArea");

        qRegisterMetaType<DrawCommandMemento>("DrawCommandMemento"); // enables converting to QVariant
        qRegisterMetaTypeStreamOperators<DrawCommandMemento>("DrawCommandMemento");

        qRegisterMetaType<SplineShape>("SplineShape");
        qRegisterMetaTypeStreamOperators<SplineShape>("SplineShape");

        qRegisterMetaType<BoundedShape>("BoundedShape");
        qRegisterMetaTypeStreamOperators<BoundedShape>("BoundedShape");

        qRegisterMetaType<LineShape>("LineShape");
        qRegisterMetaTypeStreamOperators<LineShape>("LineShape");

        qRegisterMetaTypeStreamOperators<QVector<quint64>>("QVector<quint64>");
        qRegisterMetaTypeStreamOperators<QList<DrawCommandMemento>>("QList<DrawCommandMemento>");
    }
};

#endif // WORKAREAPLUGIN_H
