QT -= gui

QMAKE_APPLE_DEVICE_ARCHS = x86_64 arm64

CONFIG += c++11 console
CONFIG -= app_bundle

TARGET = ds-convert
DESTDIR = ../../bin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../../include/ds_qt_utils.cpp \
        ds_convert.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../include/ds_global.ds-h \
    ../../include/ds_qt_utils.h \
    ds_convert.h \
    global.h

INCLUDEPATH += ../../include
