#ifndef TOOLBARPLUGIN_H
#define TOOLBARPLUGIN_H
#include <QQmlExtensionPlugin>
#include <QQmlEngine>
#include "colorpicker/colorsmodel.h"
#include "paintsettings/paintsettings.h"

class ToolBarPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
public:
    void registerTypes(const char *uri)
    {
        qmlRegisterType<ColorsModel>(uri, 1, 0, "ColorsModel");

        auto qmlInstance = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
            Q_UNUSED(engine)
            Q_UNUSED(scriptEngine)
            return &PaintSettings::instance();
        };

        qmlRegisterSingletonType<PaintSettings>(uri, 1, 0, "PaintSettings", qmlInstance);
    }
};

#endif // TOOLBARPLUGIN_H
