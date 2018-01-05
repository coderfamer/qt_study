#-------------------------------------------------
#
# Project created by QtCreator 2017-03-11T10:58:37
#
#-------------------------------------------------
QT     += core gui sql widgets script xml axcontainer network printsupport serialport webkit webkitwidgets
LIBS += -lpthread libwsock32 libws2_32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPort
TEMPLATE = app

#------------------------------------------------
INCLUDEPATH += $$(SerialPort)

SOURCES += main.cpp \
    device.cpp \
    commix.cpp \
    ldataconverter.cpp \
    lfilesystem.cpp \
    lcombobox.cpp \
    iconhelper.cpp \
    lbasedialog.cpp \
    lstyledialog.cpp \
    mythread.cpp

HEADERS  += \
    device.h \
    lglobal.h \
    commix.h \
    ldataconverter.h \
    lfilesystem.h \
    lcombobox.h \
    iconhelper.h \
    myhelper.h \
    lbasedialog.h \
    lstyledialog.h \
    mythread.h


RESOURCES += \
    res.qrc

OTHER_FILES +=
