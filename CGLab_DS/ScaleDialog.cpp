#include "ScaleDialog.h"
#include "ui_ScaleDialog.h"
#include "GeneralMessageBox.h"

ScaleDialog::ScaleDialog(time_t uid, QWidget *parent) :
    QDialog(parent), uid(uid),
    ui(new Ui::ScaleDialog)
{
    ui->setupUi(this);
}

ScaleDialog::~ScaleDialog()
{
    delete ui;
}

void ScaleDialog::accept()
{
	if (ui->id->text().isEmpty() || ui->x0->text().isEmpty() || ui->y0->text().isEmpty() || ui->s->text().isEmpty())
	{
		GeneralMessageBox::NotCompleteArg(this);
		return;
	}
	emit scale_data(ui->id->text().toInt(), ui->x0->text().toInt(), ui->y0->text().toInt(), ui->s->text().toDouble(), uid); // ·¢³öÐÅºÅ
	return;
}

void ScaleDialog::receive(const time_t uid, bool flag)
{
	if (uid == this->uid && flag == true)
		this->close();
	return;
}
