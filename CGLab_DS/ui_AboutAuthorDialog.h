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
    QPushButton *pushButton;

    void setupUi(QDialog *AboutAuthorDialog)
    {
        if (AboutAuthorDialog->objectName().isEmpty())
            AboutAuthorDialog->setObjectName(QString::fromUtf8("AboutAuthorDialog"));
        AboutAuthorDialog->resize(269, 157);
        verticalLayout = new QVBoxLayout(AboutAuthorDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(AboutAuthorDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        pushButton = new QPushButton(AboutAuthorDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignRight);


        retranslateUi(AboutAuthorDialog);

        QMetaObject::connectSlotsByName(AboutAuthorDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutAuthorDialog)
    {
        AboutAuthorDialog->setWindowTitle(QCoreApplication::translate("AboutAuthorDialog", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AboutAuthorDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\344\275\234\350\200\205\357\274\232RPG</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">2017 CS</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("AboutAuthorDialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutAuthorDialog: public Ui_AboutAuthorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTAUTHORDIALOG_H
