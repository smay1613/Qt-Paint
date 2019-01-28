QT += gui # only for types to be able for reading!
QT += network

CONFIG += c++14 console
CONFIG -= app_bundle

SOURCES += ../../Paint/src/networking/packages/basicpackage.cpp
HEADERS += ../../Paint/src/networking/packages/basicpackage.h

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../../Paint/src/networking
INCLUDEPATH += ../../Paint/src/common

INCLUDEPATH += ../../Paint/src/common/commands \
               ../../Paint/src/common/shapes

#Export data for registering as metatype for reading
HEADERS += \
           ../../Paint/src/common/commands/drawcommandmemento.h \
           ../../Paint/src/common/commands/drawcommand.h \
           ../../Paint/src/common/builders/drawcommandfactory.h \
           ../../Paint/src/common/builders/drawstrategyfactory.h \
           ../../Paint/src/common/shapes/lineshape.h \
           ../../Paint/src/common/shapes/splineshape.h \
           ../../Paint/src/common/shapes/boundedshape.h
SOURCES += \
           ../../Paint/src/common/commands/drawcommandmemento.cpp \
           ../../Paint/src/common/commands/drawcommand.cpp \
           ../../Paint/src/common/builders/drawstrategyfactory.cpp \
           ../../Paint/src/common/builders/drawcommandfactory.cpp \
           ../../Paint/src/common/shapes/lineshape.cpp \
           ../../Paint/src/common/shapes/splineshape.cpp \
           ../../Paint/src/common/shapes/boundedshape.cpp

HEADERS +=  ../../Paint/src/common/strategies/drawcirclestrategy.h \
            ../../Paint/src/common/strategies/drawcurvestrategy.h \
            ../../Paint/src/common/strategies/drawlinestrategy.h \
            ../../Paint/src/common/strategies/drawrectanglestrategy.h \

SOURCES +=  ../../Paint/src/common/strategies/drawcirclestrategy.cpp \
            ../../Paint/src/common/strategies/drawcurvestrategy.cpp \
            ../../Paint/src/common/strategies/drawlinestrategy.cpp \
            ../../Paint/src/common/strategies/drawrectanglestrategy.cpp \

HEADERS += ../../Paint/src/common/drawhistory/drawhistory.h
SOURCES += ../../Paint/src/common/drawhistory/drawhistory.cpp

HEADERS += ../../Paint/src/networking/workers/historyworker.h \
           ../../Paint/src/networking/hashers/historyhash.h
SOURCES += ../../Paint/src/networking/workers/historyworker.cpp \
           ../../Paint/src/networking/hashers/historyhash.cpp

SOURCES += \
        main.cpp \
    paintserver.cpp \
    serverargumentsparser.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    paintserver.h \
    serverargumentsparser.h
