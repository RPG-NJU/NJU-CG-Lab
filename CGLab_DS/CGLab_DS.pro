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
    ClipDialog.cpp \
    Define.cpp \
    DrawingArea.cpp \
    DrawingArea_API.cpp \
    DrawingArea_Command.cpp \
    DrawingArea_Curve.cpp \
    DrawingArea_Ellipse.cpp \
    DrawingArea_Event.cpp \
    DrawingArea_File.cpp \
    DrawingArea_Mouse.cpp \
    DrawingArea_Polygon.cpp \
    DrawingArea_PrimitiveResponse.cpp \
    DrawingArea_Select.cpp \
    DrawingArea_StraightLine.cpp \
    GeneralMessageBox.cpp \
    OpFile.cpp \
    Primitive.cpp \
    Primitive_Clip.cpp \
    Primitive_Rotate.cpp \
    Primitive_Scale.cpp \
    Primitive_Translate.cpp \
    RotateDialog.cpp \
    ScaleDialog.cpp \
    SetPaperSizeDialog.cpp \
    TranslateDialog.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow_Primitive.cpp \
    mainwindow_Select.cpp

HEADERS += \
    AboutAuthorDialog.h \
    AboutSoftwareDialog.h \
    ClipDialog.h \
    Define.h \
    DrawingArea.h \
    GeneralMessageBox.h \
    OpFile.h \
    Primitive.h \
    RotateDialog.h \
    ScaleDialog.h \
    SetPaperSizeDialog.h \
    TranslateDialog.h \
    mainwindow.h

FORMS += \
    AboutAuthorDialog.ui \
    AboutSoftwareDialog.ui \
    ClipDialog.ui \
    RotateDialog.ui \
    ScaleDialog.ui \
    SetPaperSizeDialog.ui \
    TranslateDialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
