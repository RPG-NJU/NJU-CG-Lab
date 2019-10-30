#include "SetPaperSizeDialog.h"
#include "ui_SetPaperSizeDialog.h"

SetPaperSizeDialog::SetPaperSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPaperSizeDialog)
{
    ui->setupUi(this);
}

SetPaperSizeDialog::~SetPaperSizeDialog()
{
    delete ui;
}


void SetPaperSizeDialog::setXinput(int x)
{
	ui->x_input->setText(QString::fromStdString(std::to_string(x)));
	return;
}

void SetPaperSizeDialog::setYinput(int y)
{
	ui->y_input->setText(QString::fromStdString(std::to_string(y)));
	return;
}

int SetPaperSizeDialog::_x() const
{
	return ui->x_input->text().toInt();
}

int SetPaperSizeDialog::_y() const
{
	return ui->y_input->text().toInt();
}
