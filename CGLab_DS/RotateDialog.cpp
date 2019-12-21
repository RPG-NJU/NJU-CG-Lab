#include "RotateDialog.h"
#include "ui_RotateDialog.h"

RotateDialog::RotateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RotateDialog)
{
    ui->setupUi(this);
}

RotateDialog::~RotateDialog()
{
    delete ui;
}
