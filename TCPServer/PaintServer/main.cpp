#include <QCoreApplication>
#include "serverargumentsparser.h"
#include "paintserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerArgumentsParser argParser {a};
    PaintServer server {QHostAddress(argParser.hostArgument()), static_cast<quint16>(argParser.portArgument().toUInt())};

    return a.exec();
}
