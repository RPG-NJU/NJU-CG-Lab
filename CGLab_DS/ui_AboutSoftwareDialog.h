/********************************************************************************
** Form generated from reading UI file 'AboutSoftwareDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTSOFTWAREDIALOG_H
#define UI_ABOUTSOFTWAREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutSoftwareDialog
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QPushButton *buttonUserMenu;
    QPushButton *buttonProjectPage;

    void setupUi(QDialog *AboutSoftwareDialog)
    {
        if (AboutSoftwareDialog->objectName().isEmpty())
            AboutSoftwareDialog->setObjectName(QString::fromUtf8("AboutSoftwareDialog"));
        AboutSoftwareDialog->resize(562, 221);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        AboutSoftwareDialog->setFont(font);
        gridLayout = new QGridLayout(AboutSoftwareDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(AboutSoftwareDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        textBrowser->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(textBrowser, 0, 0, 1, 2);

        buttonUserMenu = new QPushButton(AboutSoftwareDialog);
        buttonUserMenu->setObjectName(QString::fromUtf8("buttonUserMenu"));

        gridLayout->addWidget(buttonUserMenu, 1, 0, 1, 1);

        buttonProjectPage = new QPushButton(AboutSoftwareDialog);
        buttonProjectPage->setObjectName(QString::fromUtf8("buttonProjectPage"));

        gridLayout->addWidget(buttonProjectPage, 1, 1, 1, 1);


        retranslateUi(AboutSoftwareDialog);

        QMetaObject::connectSlotsByName(AboutSoftwareDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutSoftwareDialog)
    {
        AboutSoftwareDialog->setWindowTitle(QCoreApplication::translate("AboutSoftwareDialog", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AboutSoftwareDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:10.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt;\">\347\256\200\346\230\223\347\232\204\347\273\230\345\233\276\346\235\277\350\275\257\344\273\266</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt;\">\350\277\220\350\241\214\345\234\250Windows\346\223\215\344\275\234"
                        "\347\263\273\347\273\237\344\270\213</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt;\">\344\275\277\347\224\250Qt 5.13.1\350\277\233\350\241\214\347\274\226\345\206\231</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt;\">CTO\357\274\232GRP</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt;\">CDO\357\274\232YMY</span></p></body></html>", nullptr));
        buttonUserMenu->setText(QCoreApplication::translate("AboutSoftwareDialog", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        buttonProjectPage->setText(QCoreApplication::translate("AboutSoftwareDialog", "\351\241\271\347\233\256\344\270\273\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutSoftwareDialog: public Ui_AboutSoftwareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSOFTWAREDIALOG_H
