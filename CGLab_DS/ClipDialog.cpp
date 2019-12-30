#include "ClipDialog.h"
#include "ui_ClipDialog.h"
#include "GeneralMessageBox.h"

ClipDialog::ClipDialog(time_t uid, QWidget *parent) :
    QDialog(parent), uid(uid),
    ui(new Ui::ClipDialog)
{
    ui->setupUi(this);
}

ClipDialog::~ClipDialog()
{
    delete ui;
}

void ClipDialog::accept()
{
	if (ui->id->text().isEmpty() || ui->x1->text().isEmpty() || ui->y1->text().isEmpty() || ui->x2->text().isEmpty() || ui->y2->text().isEmpty())
	{
		GeneralMessageBox::NotCompleteArg(this);
		return;
	}
	emit clip_data(ui->id->text().toInt(), ui->x1->text().toInt(), ui->y1->text().toInt(), ui->x2->text().toInt(), ui->y2->text().toInt(), uid);
	return;
}

void ClipDialog::receive(const time_t uid, bool flag)
{
	if (uid == this->uid && flag == true)
		this->close();
	return;
}


