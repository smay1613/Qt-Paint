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
    src/workarea/workareaplugin.cpp \
    src/workarea/workareaelement.cpp \
    src/workarea/workareaserverimpl.cpp \
    src/common/commands/drawcommands/drawlinecommand.cpp \
    src/common/commands/command.cpp \
    src/common/commands/drawcommand.cpp \
    src/common/strategies/drawstrategy.cpp \
    src/common/shapes/boundedshape.cpp \
    src/common/shapes/lineshape.cpp \
    src/common/strategies/drawlinestrategy.cpp \
    src/common/drawhistory/history.cpp \
    src/common/drawhistory/drawhistory.cpp \
    src/common/commands/drawcommands/drawrectanglecommand.cpp \
    src/common/strategies/drawrectanglestrategy.cpp \
    src/common/commands/drawcommands/drawcirclecommand.cpp \
    src/common/strategies/drawcirclestrategy.cpp \
    src/common/commands/drawcommands/drawcurvecommand.cpp \
    src/common/strategies/drawcurvestrategy.cpp \
    src/common/shapes/splineshape.cpp \
    src/toolbar/toolbarplugin.cpp

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
    src/toolbar/toolbarplugin.h
