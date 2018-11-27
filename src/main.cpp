#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/toolbar/colorpicker/colorsmodel.h"

#include "src/toolbar/toolbarplugin.h"
#include "src/workarea/workareaplugin.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    WorkAreaPlugin workAreaPlugin;
    workAreaPlugin.registerTypes("WorkAreaPlugin");

    ToolBarPlugin toolBarPlugin;
    toolBarPlugin.registerTypes("ToolBarPlugin");

    engine.addImportPath("qrc:/qml");
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
