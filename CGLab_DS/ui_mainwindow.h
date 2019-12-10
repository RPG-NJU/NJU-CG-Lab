/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "DrawingArea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAboutAuthor;
    QAction *actionAboutSoftware;
    QAction *actionProjectView;
    QAction *actionReleaseHistory;
    QAction *actionUpgrade;
    QAction *actionChooseNature;
    QAction *actionStraightLine;
    QAction *actionOpenFile;
    QAction *actionSaveFile;
    QAction *actionPalette;
    QAction *actionCircle;
    QAction *actionEllipse;
    QAction *actionRedrawAll;
    QAction *actionClearPaper;
    QAction *actionSetPaperSize;
    QAction *actionPolygon;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    DrawingArea *drawingArea;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuProject;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(874, 734);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        actionAboutAuthor = new QAction(MainWindow);
        actionAboutAuthor->setObjectName(QString::fromUtf8("actionAboutAuthor"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MainWindow/aboutAuthor"), QSize(), QIcon::Normal, QIcon::Off);
        actionAboutAuthor->setIcon(icon);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font1.setPointSize(10);
        actionAboutAuthor->setFont(font1);
        actionAboutSoftware = new QAction(MainWindow);
        actionAboutSoftware->setObjectName(QString::fromUtf8("actionAboutSoftware"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MainWindow/aboutSoftware"), QSize(), QIcon::Normal, QIcon::Off);
        actionAboutSoftware->setIcon(icon1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        actionAboutSoftware->setFont(font2);
        actionProjectView = new QAction(MainWindow);
        actionProjectView->setObjectName(QString::fromUtf8("actionProjectView"));
        actionProjectView->setFont(font1);
        actionReleaseHistory = new QAction(MainWindow);
        actionReleaseHistory->setObjectName(QString::fromUtf8("actionReleaseHistory"));
        actionReleaseHistory->setFont(font2);
        actionUpgrade = new QAction(MainWindow);
        actionUpgrade->setObjectName(QString::fromUtf8("actionUpgrade"));
        actionChooseNature = new QAction(MainWindow);
        actionChooseNature->setObjectName(QString::fromUtf8("actionChooseNature"));
        actionChooseNature->setCheckable(true);
        actionChooseNature->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MainWindow/Nature"), QSize(), QIcon::Normal, QIcon::Off);
        actionChooseNature->setIcon(icon2);
        actionStraightLine = new QAction(MainWindow);
        actionStraightLine->setObjectName(QString::fromUtf8("actionStraightLine"));
        actionStraightLine->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/MainWindow/StraightLine"), QSize(), QIcon::Normal, QIcon::Off);
        actionStraightLine->setIcon(icon3);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionSaveFile = new QAction(MainWindow);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        actionPalette = new QAction(MainWindow);
        actionPalette->setObjectName(QString::fromUtf8("actionPalette"));
        actionPalette->setCheckable(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/MainWindow/Palette"), QSize(), QIcon::Normal, QIcon::Off);
        actionPalette->setIcon(icon4);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        actionCircle->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/MainWindow/Circle"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircle->setIcon(icon5);
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName(QString::fromUtf8("actionEllipse"));
        actionEllipse->setCheckable(true);
        actionEllipse->setChecked(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/MainWindow/Ellipse"), QSize(), QIcon::Normal, QIcon::Off);
        actionEllipse->setIcon(icon6);
        actionRedrawAll = new QAction(MainWindow);
        actionRedrawAll->setObjectName(QString::fromUtf8("actionRedrawAll"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font3.setPointSize(11);
        actionRedrawAll->setFont(font3);
        actionClearPaper = new QAction(MainWindow);
        actionClearPaper->setObjectName(QString::fromUtf8("actionClearPaper"));
        actionClearPaper->setFont(font3);
        actionSetPaperSize = new QAction(MainWindow);
        actionSetPaperSize->setObjectName(QString::fromUtf8("actionSetPaperSize"));
        actionSetPaperSize->setFont(font3);
        actionPolygon = new QAction(MainWindow);
        actionPolygon->setObjectName(QString::fromUtf8("actionPolygon"));
        actionPolygon->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/MainWindow/Ploygon"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolygon->setIcon(icon7);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 852, 617));
        scrollAreaWidgetContents->setMinimumSize(QSize(800, 600));
        drawingArea = new DrawingArea(scrollAreaWidgetContents);
        drawingArea->setObjectName(QString::fromUtf8("drawingArea"));
        drawingArea->setGeometry(QRect(0, 0, 800, 600));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 874, 26));
        menubar->setFont(font3);
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuAbout->setFont(font1);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuProject = new QMenu(menubar);
        menuProject->setObjectName(QString::fromUtf8("menuProject"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuProject->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionAboutAuthor);
        menuAbout->addAction(actionAboutSoftware);
        menuAbout->addSeparator();
        menuAbout->addSeparator();
        menuAbout->addAction(actionReleaseHistory);
        menuAbout->addAction(actionUpgrade);
        menuFile->addAction(actionOpenFile);
        menuFile->addAction(actionSaveFile);
        menuProject->addAction(actionRedrawAll);
        menuProject->addAction(actionClearPaper);
        menuProject->addAction(actionSetPaperSize);
        toolBar->addAction(actionChooseNature);
        toolBar->addAction(actionStraightLine);
        toolBar->addAction(actionCircle);
        toolBar->addAction(actionEllipse);
        toolBar->addAction(actionPolygon);
        toolBar->addAction(actionPalette);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276\346\235\277 \302\251RPG", nullptr));
#if QT_CONFIG(statustip)
        MainWindow->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        actionAboutAuthor->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\344\275\234\350\200\205", nullptr));
#if QT_CONFIG(statustip)
        actionAboutAuthor->setStatusTip(QCoreApplication::translate("MainWindow", "\345\261\225\347\244\272\346\233\264\345\244\232\345\205\263\344\272\216\344\275\234\350\200\205\342\200\246\342\200\246", nullptr));
#endif // QT_CONFIG(statustip)
        actionAboutSoftware->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\350\275\257\344\273\266", nullptr));
#if QT_CONFIG(statustip)
        actionAboutSoftware->setStatusTip(QCoreApplication::translate("MainWindow", "\345\261\225\347\244\272\346\233\264\345\244\232\345\205\263\344\272\216\350\275\257\344\273\266\342\200\246\342\200\246", nullptr));
#endif // QT_CONFIG(statustip)
        actionProjectView->setText(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        actionReleaseHistory->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\347\211\210\346\234\254", nullptr));
#if QT_CONFIG(statustip)
        actionReleaseHistory->setStatusTip(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\350\275\257\344\273\266\345\217\221\345\270\203\347\232\204\345\216\206\345\217\262\347\211\210\346\234\254\342\200\246\342\200\246", nullptr));
#endif // QT_CONFIG(statustip)
        actionUpgrade->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260", nullptr));
#if QT_CONFIG(statustip)
        actionUpgrade->setStatusTip(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\346\243\200\346\237\245\346\233\264\346\226\260\342\200\246\342\200\246", nullptr));
#endif // QT_CONFIG(statustip)
        actionChooseNature->setText(QCoreApplication::translate("MainWindow", "\350\207\252\347\204\266\347\272\277\346\235\241", nullptr));
#if QT_CONFIG(tooltip)
        actionChooseNature->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\347\204\266\347\272\277\346\235\241", nullptr));
#endif // QT_CONFIG(tooltip)
        actionStraightLine->setText(QCoreApplication::translate("MainWindow", "\347\233\264\347\272\277", nullptr));
#if QT_CONFIG(tooltip)
        actionStraightLine->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\264\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpenFile->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenFile->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpenFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveFile->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPalette->setText(QCoreApplication::translate("MainWindow", "\350\260\203\350\211\262\346\235\277", nullptr));
#if QT_CONFIG(tooltip)
        actionPalette->setToolTip(QCoreApplication::translate("MainWindow", "\350\260\203\350\211\262\346\235\277", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCircle->setText(QCoreApplication::translate("MainWindow", "\345\234\206", nullptr));
#if QT_CONFIG(tooltip)
        actionCircle->setToolTip(QCoreApplication::translate("MainWindow", "\345\234\206", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "\346\244\255\345\234\206", nullptr));
#if QT_CONFIG(tooltip)
        actionEllipse->setToolTip(QCoreApplication::translate("MainWindow", "\346\244\255\345\234\206", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRedrawAll->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\347\224\273\345\270\203", nullptr));
#if QT_CONFIG(shortcut)
        actionRedrawAll->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClearPaper->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\224\273\345\270\203", nullptr));
        actionSetPaperSize->setText(QCoreApplication::translate("MainWindow", "\347\224\273\345\270\203\345\244\247\345\260\217", nullptr));
        actionPolygon->setText(QCoreApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242", nullptr));
#if QT_CONFIG(tooltip)
        actionPolygon->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        drawingArea->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(tooltip)
        menuAbout->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        menuAbout->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menuProject->setTitle(QCoreApplication::translate("MainWindow", "\347\224\273\345\270\203", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
