#ifndef NETWORKPLUGIN_H
#define NETWORKPLUGIN_H
#include <QQmlExtensionPlugin>
#include <QCoreApplication>
#include <QQmlEngine>
#include "settings/connectionsettings.h"
#include "clparsers/connectionargumentsparser.h"

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
                                            "ConnectionMode",
                                            "Error: only enums");
    }

private:
    const QCoreApplication& m_application;
};

#endif // NETWORKPLUGIN_H
