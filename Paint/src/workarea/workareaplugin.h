#ifndef WORKAREAPLUGIN_H
#define WORKAREAPLUGIN_H

#include <QQmlExtensionPlugin>

#include "workareaelement.h"

class WorkAreaPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri)
    {
        qmlRegisterType<WorkAreaElement>(uri, 1, 0, "WorkArea");
    }
};

#endif // WORKAREAPLUGIN_H
