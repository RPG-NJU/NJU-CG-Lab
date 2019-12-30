#include "RotateDialog.h"
#include "ui_RotateDialog.h"
#include "GeneralMessageBox.h"

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
	if (ui->id->text().isEmpty() || ui->x0->text().isEmpty() || ui->y0->text().isEmpty() || ui->r->text().isEmpty())
	{
		GeneralMessageBox::NotCompleteArg(this);
		return;
	}
	emit rotate_data(ui->id->text().toInt(), ui->x0->text().toInt(), ui->y0->text().toInt(), ui->r->text().toInt(), uid);
	return;
}

void RotateDialog::receive(const time_t uid, bool flag)
{
	if (uid == this->uid && flag == true)
		this->close();
	return;
}
