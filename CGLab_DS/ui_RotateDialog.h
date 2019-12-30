/********************************************************************************
** Form generated from reading UI file 'RotateDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATEDIALOG_H
#define UI_ROTATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RotateDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *y0;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *x0;
    QLineEdit *id;
    QLabel *label_9;
    QLineEdit *r;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_11;

    void setupUi(QDialog *RotateDialog)
    {
        if (RotateDialog->objectName().isEmpty())
            RotateDialog->setObjectName(QString::fromUtf8("RotateDialog"));
        RotateDialog->resize(563, 226);
        buttonBox = new QDialogButtonBox(RotateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(210, 180, 341, 32));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(11);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(RotateDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 40, 461, 121));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        y0 = new QLineEdit(gridLayoutWidget);
        y0->setObjectName(QString::fromUtf8("y0"));
        y0->setFont(font);

        gridLayout_2->addWidget(y0, 1, 8, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 1, 7, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 1, 5, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        x0 = new QLineEdit(gridLayoutWidget);
        x0->setObjectName(QString::fromUtf8("x0"));
        x0->setFont(font);

        gridLayout_2->addWidget(x0, 1, 6, 1, 1);

        id = new QLineEdit(gridLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));
        id->setFont(font);

        gridLayout_2->addWidget(id, 0, 1, 1, 4);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout_2->addWidget(label_9, 1, 4, 1, 1);

        r = new QLineEdit(gridLayoutWidget);
        r->setObjectName(QString::fromUtf8("r"));
        r->setFont(font);

        gridLayout_2->addWidget(r, 1, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout_2->addWidget(label_11, 1, 3, 1, 1);


        retranslateUi(RotateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RotateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RotateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RotateDialog);
    } // setupUi

    void retranslateUi(QDialog *RotateDialog)
    {
        RotateDialog->setWindowTitle(QCoreApplication::translate("RotateDialog", "\346\227\213\350\275\254\345\233\276\345\205\203", nullptr));
        label_6->setText(QCoreApplication::translate("RotateDialog", "y=", nullptr));
        label_8->setText(QCoreApplication::translate("RotateDialog", "x=", nullptr));
        label_5->setText(QCoreApplication::translate("RotateDialog", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("RotateDialog", "\346\227\213\350\275\254\344\270\255\345\277\203\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("RotateDialog", "\345\233\276\345\205\203\347\274\226\345\217\267\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("RotateDialog", "r=", nullptr));
        label_11->setText(QCoreApplication::translate("RotateDialog", "\302\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RotateDialog: public Ui_RotateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATEDIALOG_H
