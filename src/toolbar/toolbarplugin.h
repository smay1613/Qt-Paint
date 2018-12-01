#ifndef TOOLBARPLUGIN_H
#define TOOLBARPLUGIN_H
#include <QQmlExtensionPlugin>
#include <QQmlEngine>
#include "colorpicker/colorsmodel.h"
#include "paintsettings/paintsettings.h"
#include "adaptors/actionmanageradaptor.h"
#include "shapepicker/shapesmodel.h"
#include "../common/painttypes.h"

class ToolBarPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
public:
    void registerTypes(const char *uri)
    {
        qmlRegisterType<ColorsModel>(uri, 1, 0, "ColorsModel");
        qmlRegisterType<ShapesModel>(uri, 1, 0, "ShapesModel");

        const auto settingsInstance = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
            Q_UNUSED(scriptEngine)
            // Only c++ must handle singleton lifetime!
            engine->setObjectOwnership(&PaintSettings::instance(), QQmlEngine::CppOwnership);
            return &PaintSettings::instance();
        };
        qmlRegisterSingletonType<PaintSettings>(uri, 1, 0, "PaintSettings", settingsInstance);

        const auto actionManagerInstance = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
            Q_UNUSED(scriptEngine)
            engine->setObjectOwnership(&ActionManagerAdaptor::instance(), QQmlEngine::CppOwnership);
            return &ActionManagerAdaptor::instance();
        };
        qmlRegisterSingletonType<ActionManagerAdaptor>(uri, 1, 0, "ActionManager", actionManagerInstance);
    }
};

#endif // TOOLBARPLUGIN_H
