#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/toolbar/colorpicker/colorsmodel.h"

#include "src/workarea/workareaplugin.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();

    WorkAreaPlugin workAreaPlugin;
    workAreaPlugin.registerTypes("WorkArea");

    ColorsModel defaultColors (nullptr);
    ctxt->setContextProperty("colorsModel", &defaultColors);

    engine.addImportPath("qrc:/qml");
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
