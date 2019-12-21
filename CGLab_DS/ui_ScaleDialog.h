/********************************************************************************
** Form generated from reading UI file 'ScaleDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALEDIALOG_H
#define UI_SCALEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScaleDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *s;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *x0;
    QLineEdit *y0;
    QLineEdit *id;

    void setupUi(QDialog *ScaleDialog)
    {
        if (ScaleDialog->objectName().isEmpty())
            ScaleDialog->setObjectName(QString::fromUtf8("ScaleDialog"));
        ScaleDialog->resize(609, 224);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(11);
        ScaleDialog->setFont(font);
        buttonBox = new QDialogButtonBox(ScaleDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(250, 180, 341, 32));
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(ScaleDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 40, 461, 121));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 1, 6, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 1, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 1, 4, 1, 1);

        s = new QLineEdit(gridLayoutWidget);
        s->setObjectName(QString::fromUtf8("s"));
        s->setFont(font);

        gridLayout_2->addWidget(s, 1, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout_2->addWidget(label_9, 1, 3, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        x0 = new QLineEdit(gridLayoutWidget);
        x0->setObjectName(QString::fromUtf8("x0"));
        x0->setFont(font);

        gridLayout_2->addWidget(x0, 1, 5, 1, 1);

        y0 = new QLineEdit(gridLayoutWidget);
        y0->setObjectName(QString::fromUtf8("y0"));
        y0->setFont(font);

        gridLayout_2->addWidget(y0, 1, 7, 1, 1);

        id = new QLineEdit(gridLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));
        id->setFont(font);

        gridLayout_2->addWidget(id, 0, 1, 1, 3);


        retranslateUi(ScaleDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), ScaleDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), ScaleDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(ScaleDialog);
    } // setupUi

    void retranslateUi(QDialog *ScaleDialog)
    {
        ScaleDialog->setWindowTitle(QCoreApplication::translate("ScaleDialog", "\345\233\276\345\205\203\347\274\251\346\224\276", nullptr));
        label_5->setText(QCoreApplication::translate("ScaleDialog", "\347\274\251\346\224\276\345\200\215\346\225\260\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("ScaleDialog", "y=", nullptr));
        label_7->setText(QCoreApplication::translate("ScaleDialog", "s=", nullptr));
        label_8->setText(QCoreApplication::translate("ScaleDialog", "x=", nullptr));
        label_9->setText(QCoreApplication::translate("ScaleDialog", "\347\274\251\346\224\276\344\270\255\345\277\203\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("ScaleDialog", "\345\233\276\345\205\203\347\274\226\345\217\267\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScaleDialog: public Ui_ScaleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALEDIALOG_H
