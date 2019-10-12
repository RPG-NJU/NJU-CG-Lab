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
    QAction *actionAboutAuthor;
    QAction *actionAboutSoftware;
    QWidget *centralwidget;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionAboutAuthor = new QAction(MainWindow);
        actionAboutAuthor->setObjectName(QString::fromUtf8("actionAboutAuthor"));
        actionAboutSoftware = new QAction(MainWindow);
        actionAboutSoftware->setObjectName(QString::fromUtf8("actionAboutSoftware"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        QFont font;
        font.setPointSize(9);
        menuAbout->setFont(font);
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionAboutAuthor);
        menuAbout->addAction(actionAboutSoftware);

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
#if QT_CONFIG(tooltip)
        menuAbout->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        menuAbout->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
