#ifndef SERVERARGUMENTSPARSER_H
#define SERVERARGUMENTSPARSER_H
#include <QCommandLineParser>

class ServerArgumentsParser
{
public:
    explicit ServerArgumentsParser(const QCoreApplication& app);

    QString hostArgument() const;
    QString portArgument() const;

private:
    QCommandLineParser m_parser;
    QString m_hostArgument;
    QString m_portArgument;
};

#endif // SERVERARGUMENTSPARSER_H
