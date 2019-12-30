/********************************************************************************
** Form generated from reading UI file 'ClipDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPDIALOG_H
#define UI_CLIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClipDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_5;
    QLineEdit *id;
    QLabel *label_6;
    QLineEdit *y1;
    QLineEdit *x1;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *x2;
    QLineEdit *y2;

    void setupUi(QDialog *ClipDialog)
    {
        if (ClipDialog->objectName().isEmpty())
            ClipDialog->setObjectName(QString::fromUtf8("ClipDialog"));
        ClipDialog->resize(425, 215);
        buttonBox = new QDialogButtonBox(ClipDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 170, 341, 32));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(11);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(ClipDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 30, 361, 121));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 1, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        id = new QLineEdit(gridLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));
        id->setFont(font);

        gridLayout_2->addWidget(id, 0, 1, 1, 2);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 1, 3, 1, 1);

        y1 = new QLineEdit(gridLayoutWidget);
        y1->setObjectName(QString::fromUtf8("y1"));
        y1->setFont(font);

        gridLayout_2->addWidget(y1, 1, 4, 1, 1);

        x1 = new QLineEdit(gridLayoutWidget);
        x1->setObjectName(QString::fromUtf8("x1"));
        x1->setFont(font);

        gridLayout_2->addWidget(x1, 1, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout_2->addWidget(label_9, 2, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 2, 3, 1, 1);

        x2 = new QLineEdit(gridLayoutWidget);
        x2->setObjectName(QString::fromUtf8("x2"));
        x2->setFont(font);

        gridLayout_2->addWidget(x2, 2, 2, 1, 1);

        y2 = new QLineEdit(gridLayoutWidget);
        y2->setObjectName(QString::fromUtf8("y2"));
        y2->setFont(font);

        gridLayout_2->addWidget(y2, 2, 4, 1, 1);


        retranslateUi(ClipDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ClipDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ClipDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ClipDialog);
    } // setupUi

    void retranslateUi(QDialog *ClipDialog)
    {
        ClipDialog->setWindowTitle(QCoreApplication::translate("ClipDialog", "\350\243\201\345\211\252\345\233\276\345\205\203", nullptr));
        label_8->setText(QCoreApplication::translate("ClipDialog", "x1=", nullptr));
        label_10->setText(QCoreApplication::translate("ClipDialog", "\345\233\276\345\205\203\347\274\226\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("ClipDialog", "\350\243\201\345\211\252\347\252\227\345\217\243\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("ClipDialog", "y1=", nullptr));
        label_9->setText(QCoreApplication::translate("ClipDialog", "x2=", nullptr));
        label_7->setText(QCoreApplication::translate("ClipDialog", "y2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClipDialog: public Ui_ClipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPDIALOG_H
