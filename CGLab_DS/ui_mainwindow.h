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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *showAbout;
    QWidget *centralwidget;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        showAbout = new QAction(MainWindow);
        showAbout->setObjectName(QString::fromUtf8("showAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        QFont font;
        font.setPointSize(9);
        menuAbout->setFont(font);
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(showAbout);

        retranslateUi(MainWindow);
        QObject::connect(showAbout, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CGLab-DS \302\251RPG", nullptr));
#if QT_CONFIG(statustip)
        MainWindow->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        showAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\350\275\257\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        showAbout->setToolTip(QCoreApplication::translate("MainWindow", "\345\261\225\347\244\272\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        showAbout->setStatusTip(QCoreApplication::translate("MainWindow", "\345\261\225\347\244\272\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        showAbout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        menuAbout->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        menuAbout->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
