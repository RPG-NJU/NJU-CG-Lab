/********************************************************************************
** Form generated from reading UI file 'SetPaperSizeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPAPERSIZEDIALOG_H
#define UI_SETPAPERSIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetPaperSizeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *x_input;
    QLineEdit *y_input;

    void setupUi(QDialog *SetPaperSizeDialog)
    {
        if (SetPaperSizeDialog->objectName().isEmpty())
            SetPaperSizeDialog->setObjectName(QString::fromUtf8("SetPaperSizeDialog"));
        SetPaperSizeDialog->resize(408, 179);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(11);
        SetPaperSizeDialog->setFont(font);
        buttonBox = new QDialogButtonBox(SetPaperSizeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(220, 140, 167, 24));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(SetPaperSizeDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(90, 40, 221, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        x_input = new QLineEdit(gridLayoutWidget);
        x_input->setObjectName(QString::fromUtf8("x_input"));
        x_input->setFont(font);

        gridLayout_2->addWidget(x_input, 0, 0, 1, 1);

        y_input = new QLineEdit(gridLayoutWidget);
        y_input->setObjectName(QString::fromUtf8("y_input"));
        y_input->setFont(font);

        gridLayout_2->addWidget(y_input, 0, 2, 1, 1);


        retranslateUi(SetPaperSizeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetPaperSizeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetPaperSizeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetPaperSizeDialog);
    } // setupUi

    void retranslateUi(QDialog *SetPaperSizeDialog)
    {
        SetPaperSizeDialog->setWindowTitle(QCoreApplication::translate("SetPaperSizeDialog", "\350\256\276\347\275\256\347\224\273\345\270\203\345\244\247\345\260\217", nullptr));
        label->setText(QCoreApplication::translate("SetPaperSizeDialog", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetPaperSizeDialog: public Ui_SetPaperSizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPAPERSIZEDIALOG_H
