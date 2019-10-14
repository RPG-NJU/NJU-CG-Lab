/********************************************************************************
** Form generated from reading UI file 'AboutAuthorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTAUTHORDIALOG_H
#define UI_ABOUTAUTHORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutAuthorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QPushButton *buttonConnectAuthor;

    void setupUi(QDialog *AboutAuthorDialog)
    {
        if (AboutAuthorDialog->objectName().isEmpty())
            AboutAuthorDialog->setObjectName(QString::fromUtf8("AboutAuthorDialog"));
        AboutAuthorDialog->resize(349, 150);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        AboutAuthorDialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MainWindow/aboutAuthor"), QSize(), QIcon::Normal, QIcon::Off);
        AboutAuthorDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(AboutAuthorDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(AboutAuthorDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        textBrowser->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(textBrowser);

        buttonConnectAuthor = new QPushButton(AboutAuthorDialog);
        buttonConnectAuthor->setObjectName(QString::fromUtf8("buttonConnectAuthor"));

        verticalLayout->addWidget(buttonConnectAuthor, 0, Qt::AlignRight);


        retranslateUi(AboutAuthorDialog);

        QMetaObject::connectSlotsByName(AboutAuthorDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutAuthorDialog)
    {
        AboutAuthorDialog->setWindowTitle(QCoreApplication::translate("AboutAuthorDialog", "\345\205\263\344\272\216\344\275\234\350\200\205", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AboutAuthorDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213';\">\344\275\234\350\200\205\357\274\232RPG</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213';\">NJU 2017 CS</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent"
                        ":0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213';\">Email\357\274\232officialRPG2017@gmail.com</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\215\216\346\226\207\344\270\255\345\256\213';\">GitHub\357\274\232HELLORPG</span></p></body></html>", nullptr));
        buttonConnectAuthor->setText(QCoreApplication::translate("AboutAuthorDialog", "\350\201\224\347\263\273\344\275\234\350\200\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutAuthorDialog: public Ui_AboutAuthorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTAUTHORDIALOG_H
