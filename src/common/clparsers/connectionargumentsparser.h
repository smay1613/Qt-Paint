#ifndef CONNECTIONARGUMENTSPARSER_H
#define CONNECTIONARGUMENTSPARSER_H
#include <QCommandLineParser>

class ConnectionArgumentsParser
{
public:
    explicit ConnectionArgumentsParser(const QCoreApplication& app);

    const QString hostArgument() const;
    const QString portArgument() const;
    const QString modeArgument() const;

private:
    QCommandLineParser m_parser;
    QString m_hostArgument;
    QString m_portArgument;
    QString m_modeArgument;
};

#endif // CONNECTIONARGUMENTSPARSER_H
