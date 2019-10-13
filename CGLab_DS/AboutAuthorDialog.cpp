#include "AboutAuthorDialog.h"
#include "ui_AboutAuthorDialog.h"

AboutAuthorDialog::AboutAuthorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutAuthorDialog)
{
    ui->setupUi(this);
}

AboutAuthorDialog::~AboutAuthorDialog()
{
    delete ui;
}
