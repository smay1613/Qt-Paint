QT += quick
CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/toolbar/colorpicker/colorsmodel.cpp \
    src/workarea/workareaelement.cpp \
    src/workarea/workareaserverimpl.cpp \
    src/common/commands/drawcommands/drawlinecommand.cpp \
    src/common/commands/drawcommand.cpp \
    src/common/shapes/boundedshape.cpp \
    src/common/shapes/lineshape.cpp \
    src/common/strategies/drawlinestrategy.cpp \
    src/common/drawhistory/drawhistory.cpp \
    src/common/commands/drawcommands/drawrectanglecommand.cpp \
    src/common/strategies/drawrectanglestrategy.cpp \
    src/common/commands/drawcommands/drawcirclecommand.cpp \
    src/common/strategies/drawcirclestrategy.cpp \
    src/common/commands/drawcommands/drawcurvecommand.cpp \
    src/common/strategies/drawcurvestrategy.cpp \
    src/common/shapes/splineshape.cpp \
    src/toolbar/settings/paintsettings.cpp \
    src/toolbar/shapepicker/shapesmodel.cpp \
    src/common/builders/paintpenbuilder.cpp \
    src/toolbar/adaptors/actionmanageradaptor.cpp \
    src/common/builders/drawcommandfactory.cpp \
    src/toolbar/settings/viewsettings.cpp \
    src/networking/clparsers/connectionargumentsparser.cpp \
    src/networking/settings/connectionsettings.cpp \
    src/networking/hashers/historyhash.cpp \
    src/networking/packages/basicpackage.cpp \
    src/networking/managers/connectionmanageradaptor.cpp \
    src/workarea/workareaimpl.cpp \
    src/workarea/workareaclientimpl.cpp \
    src/networking/managers/clientservermanager.cpp \
    src/common/commands/drawcommandmemento.cpp \
    src/networking/workers/historyworker.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $${_PRO_FILE_PWD_}/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/toolbar/colorpicker/colorsmodel.h \
    src/workarea/workareaplugin.h \
    src/workarea/workareaelement.h \
    src/workarea/workareaserverimpl.h \
    src/common/commands/drawcommands/drawlinecommand.h \
    src/common/commands/command.h \
    src/common/commands/drawcommand.h \
    src/common/painttypes.h \
    src/common/strategies/drawstrategy.h \
    src/common/shapes/boundedshape.h \
    src/common/shapes/lineshape.h \
    src/common/strategies/drawlinestrategy.h \
    src/common/drawhistory/history.h \
    src/common/drawhistory/drawhistory.h \
    src/common/commands/drawcommands/drawrectanglecommand.h \
    src/common/strategies/drawrectanglestrategy.h \
    src/common/commands/drawcommands/drawcirclecommand.h \
    src/common/strategies/drawcirclestrategy.h \
    src/common/commands/drawcommands/drawcurvecommand.h \
    src/common/strategies/drawcurvestrategy.h \
    src/common/shapes/splineshape.h \
    src/toolbar/toolbarplugin.h \
    src/toolbar/settings/paintsettings.h \
    src/toolbar/shapepicker/shapesmodel.h \
    src/common/builders/paintpenbuilder.h \
    src/toolbar/adaptors/actionmanageradaptor.h \
    src/common/builders/drawcommandfactory.h \
    src/toolbar/settings/viewsettings.h \
    src/networking/clparsers/connectionargumentsparser.h \
    src/networking/settings/connectionsettings.h \
    src/networking/hashers/historyhash.h \
    src/networking/packages/ipackage.h \
    src/networking/packages/packagetypes.h \
    src/networking/packages/basicpackage.h \
    src/networking/packages/clientpackages/introducingpackage.h \
    src/networking/networkplugin.h \
    src/networking/networkingtypes.h \
    src/networking/managers/connectionmanageradaptor.h \
    src/workarea/workareaimpl.h \
    src/workarea/workareaclientimpl.h \
    src/networking/managers/clientservermanager.h \
    src/common/commands/drawcommandmemento.h \
    src/networking/workers/historyworker.h

DISTFILES +=
