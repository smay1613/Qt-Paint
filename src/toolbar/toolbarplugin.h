#ifndef TOOLBARPLUGIN_H
#define TOOLBARPLUGIN_H
#include <QQmlExtensionPlugin>
#include <QQmlEngine>
#include "colorpicker/colorsmodel.h"
#include "settings/paintsettings.h"
#include "settings/viewsettings.h"
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

        const auto paintSettingsInstance = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
            Q_UNUSED(scriptEngine)
            // Only c++ must handle singleton lifetime!
            engine->setObjectOwnership(&PaintSettings::instance(), QQmlEngine::CppOwnership);
            return &PaintSettings::instance();
        };
        qmlRegisterSingletonType<PaintSettings>(uri, 1, 0, "PaintSettings", paintSettingsInstance);

        const auto viewSettingsInstance = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
            Q_UNUSED(scriptEngine)
            engine->setObjectOwnership(&ViewSettings::instance(), QQmlEngine::CppOwnership);
            return &ViewSettings::instance();
        };
        qmlRegisterSingletonType<ViewSettings>(uri, 1, 0, "ViewSettings", viewSettingsInstance);

        const auto actionManagerInstance = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
            Q_UNUSED(scriptEngine)
            engine->setObjectOwnership(&ActionManagerAdaptor::instance(), QQmlEngine::CppOwnership);
            return &ActionManagerAdaptor::instance();
        };
        qmlRegisterSingletonType<ActionManagerAdaptor>(uri, 1, 0, "ActionManager", actionManagerInstance);
    }
};

#endif // TOOLBARPLUGIN_H
