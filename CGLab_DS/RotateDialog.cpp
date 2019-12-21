#include "RotateDialog.h"
#include "ui_RotateDialog.h"

RotateDialog::RotateDialog(time_t uid, QWidget* parent) :
	QDialog(parent), uid(uid), 
    ui(new Ui::RotateDialog)
{
    ui->setupUi(this);
}

RotateDialog::~RotateDialog()
{
    delete ui;
}

void RotateDialog::accept()
{
	emit rotate_data(ui->id->text().toInt(), ui->x0->text().toInt(), ui->y0->text().toInt(), ui->r->text().toInt(), uid);
	return;
}

void RotateDialog::receive(const time_t uid, bool flag)
{
	if (uid == this->uid && flag == true)
		this->close();
	return;
}
