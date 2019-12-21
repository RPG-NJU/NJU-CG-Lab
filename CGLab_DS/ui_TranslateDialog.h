/********************************************************************************
** Form generated from reading UI file 'TranslateDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATEDIALOG_H
#define UI_TRANSLATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TranslateDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *dx;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *dy;
    QLineEdit *primitive_id;

    void setupUi(QDialog *TranslateDialog)
    {
        if (TranslateDialog->objectName().isEmpty())
            TranslateDialog->setObjectName(QString::fromUtf8("TranslateDialog"));
        TranslateDialog->resize(552, 242);
        buttonBox = new QDialogButtonBox(TranslateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(200, 200, 341, 32));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213"));
        font.setPointSize(11);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(TranslateDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 30, 461, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        dx = new QLineEdit(gridLayoutWidget);
        dx->setObjectName(QString::fromUtf8("dx"));
        dx->setFont(font);

        gridLayout->addWidget(dx, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        dy = new QLineEdit(gridLayoutWidget);
        dy->setObjectName(QString::fromUtf8("dy"));
        dy->setFont(font);

        gridLayout->addWidget(dy, 1, 4, 1, 1);

        primitive_id = new QLineEdit(gridLayoutWidget);
        primitive_id->setObjectName(QString::fromUtf8("primitive_id"));
        primitive_id->setFont(font);

        gridLayout->addWidget(primitive_id, 0, 1, 1, 2);


        retranslateUi(TranslateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TranslateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TranslateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TranslateDialog);
    } // setupUi

    void retranslateUi(QDialog *TranslateDialog)
    {
        TranslateDialog->setWindowTitle(QCoreApplication::translate("TranslateDialog", "\345\271\263\347\247\273\345\233\276\345\205\203", nullptr));
        label_3->setText(QCoreApplication::translate("TranslateDialog", "dx=", nullptr));
        label->setText(QCoreApplication::translate("TranslateDialog", "\345\233\276\345\205\203\347\274\226\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("TranslateDialog", "\345\271\263\347\247\273\350\267\235\347\246\273\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("TranslateDialog", "dy=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TranslateDialog: public Ui_TranslateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATEDIALOG_H
