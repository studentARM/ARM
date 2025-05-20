QT       += core gui
QT += sql
QT += network
QT += widgets
QT += widgets printsupport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += smtp
SOURCES += $$files(smtp/*.cpp) \
    givefromteacher.cpp \
    performancegraphwindow.cpp \
    sendemailwindow.cpp \
    qcustomplot.cpp \
    temperamentdialog.cpp
HEADERS += $$files(smtp/*.h) \
    givefromteacher.h \
    performancegraphwindow.h \
    sendemailwindow.h \
    qcustomplot.h \
    temperamentdialog.h

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    global.cpp \
    loginwindow.cpp \
    main.cpp \
    arm.cpp \
    mainwindowleader.cpp \
    mainwindowstudent.cpp \
    mainwindowteacher.cpp \
    test.cpp

HEADERS += \
    arm.h \
    global.h \
    loginwindow.h \
    mainwindowleader.h \
    mainwindowstudent.h \
    mainwindowteacher.h \
    test.h

FORMS += \
    arm.ui \
    givefromteacher.ui \
    loginwindow.ui \
    mainwindowleader.ui \
    mainwindowstudent.ui \
    mainwindowteacher.ui \
    performancegraphwindow.ui \
    sendemailwindow.ui \
    temperamentdialog.ui \
    test.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
