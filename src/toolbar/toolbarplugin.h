#ifndef TOOLBARPLUGIN_H
#define TOOLBARPLUGIN_H
#include <QQmlExtensionPlugin>
#include <QQmlEngine>
#include "colorpicker/colorsmodel.h"

class ToolBarPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
public:
    void registerTypes(const char *uri)
    {
        qmlRegisterType<ColorsModel>(uri, 1, 0, "ColorsModel");
    }
};

#endif // TOOLBARPLUGIN_H
