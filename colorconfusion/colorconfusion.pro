TEMPLATE = app

QT += qml quick declarative script widgets

SOURCES += src/main.cpp \
    src/bestscoresobject.cpp \
    src/bestscoresitem.cpp \
    src/configobject.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/bestscoresobject.h \
    src/bestscoresitem.h \
    src/configobject.h \
    src/version.h \
    src/defs.h
