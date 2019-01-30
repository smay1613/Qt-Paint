#include <QCoreApplication>
#include "serverargumentsparser.h"
#include "paintserver.h"
#include "drawcommandmemento.h"
#include "splineshape.h"
#include "lineshape.h"
#include "boundedshape.h"

void registerMetaTypes() {
    qRegisterMetaType<DrawCommandMemento>("DrawCommandMemento"); // enables converting to QVariant
    qRegisterMetaTypeStreamOperators<DrawCommandMemento>("DrawCommandMemento");

    qRegisterMetaType<SplineShape>("SplineShape");
    qRegisterMetaTypeStreamOperators<SplineShape>("SplineShape");

    qRegisterMetaType<BoundedShape>("BoundedShape");
    qRegisterMetaTypeStreamOperators<BoundedShape>("BoundedShape");

    qRegisterMetaType<LineShape>("LineShape");
    qRegisterMetaTypeStreamOperators<LineShape>("LineShape");

    qRegisterMetaTypeStreamOperators<QVector<quint64>>("QVector<quint64>");
    qRegisterMetaTypeStreamOperators<QPair<QList<DrawCommandMemento>, quint64>>("QPair<QList<DrawCommandMemento>, quint64>");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    registerMetaTypes();
    ServerArgumentsParser argParser {a};
    PaintServer server {QHostAddress(argParser.hostArgument()), static_cast<quint16>(argParser.portArgument().toUInt())};

    return a.exec();
}
