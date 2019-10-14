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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAboutAuthor;
    QAction *actionAboutSoftware;
    QAction *actionProjectView;
    QAction *actionReleaseHistory;
    QAction *actionUpgrade;
    QWidget *centralwidget;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuProject;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
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
        actionReleaseHistory = new QAction(MainWindow);
        actionReleaseHistory->setObjectName(QString::fromUtf8("actionReleaseHistory"));
        actionReleaseHistory->setFont(font2);
        actionUpgrade = new QAction(MainWindow);
        actionUpgrade->setObjectName(QString::fromUtf8("actionUpgrade"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font3.setPointSize(11);
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
        menuProject->addAction(actionProjectView);

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
#if QT_CONFIG(tooltip)
        menuAbout->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        menuAbout->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menuProject->setTitle(QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
