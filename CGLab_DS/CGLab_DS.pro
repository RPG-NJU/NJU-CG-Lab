QT       += core gui
UI_DIR=../CGLab_DS

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
# CONFIG += console # 这是为了达到控制台输出而添加的

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AboutAuthorDialog.cpp \
    AboutSoftwareDialog.cpp \
    DrawingArea.cpp \
    DrawingArea_API.cpp \
    DrawingArea_Command.cpp \
    DrawingArea_Ellipse.cpp \
    DrawingArea_File.cpp \
    DrawingArea_Polygon.cpp \
    DrawingArea_StraightLine.cpp \
    OpFile.cpp \
    Primitive.cpp \
    Primitive_Translate.cpp \
    SetPaperSizeDialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AboutAuthorDialog.h \
    AboutSoftwareDialog.h \
    Define.h \
    DrawingArea.h \
    OpFile.h \
    Primitive.h \
    SetPaperSizeDialog.h \
    mainwindow.h

FORMS += \
    AboutAuthorDialog.ui \
    AboutSoftwareDialog.ui \
    SetPaperSizeDialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
