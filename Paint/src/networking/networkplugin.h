#ifndef NETWORKPLUGIN_H
#define NETWORKPLUGIN_H
#include <QQmlExtensionPlugin>
#include <QCoreApplication>
#include <QQmlEngine>
#include "settings/connectionsettings.h"
#include "clparsers/connectionargumentsparser.h"
#include "../common/commands/drawcommandmemento.h"

class NetworkPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
public:
    NetworkPlugin(const QCoreApplication& app)
        : m_application {app} {}

    void registerTypes(const char *uri) {
        ConnectionSettings::instance().initSettings(ConnectionArgumentsParser{m_application});

        const auto connectionSettingsInstance = [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
            Q_UNUSED(scriptEngine)
            engine->setObjectOwnership(&ConnectionSettings::instance(), QQmlEngine::CppOwnership);
            return &ConnectionSettings::instance();
        };

        qmlRegisterSingletonType<ConnectionSettings>(uri, 1, 0, "ConnectionSettings", connectionSettingsInstance);

        qRegisterMetaType<networking::ConnectionMode>("networking::ConnectionMode");
        qmlRegisterUncreatableMetaObject(networking::staticMetaObject,
                                            uri,
                                            1, 0,
                                            "Network",
                                            "Error: only enums");

        qRegisterMetaTypeStreamOperators<QVector<quint64>>("QVector<quint64>");
        qRegisterMetaTypeStreamOperators<QPair<QList<DrawCommandMemento>, quint64>>("QPair<QList<DrawCommandMemento>, quint64>");
    }

private:
    const QCoreApplication& m_application;
};

#endif // NETWORKPLUGIN_H
