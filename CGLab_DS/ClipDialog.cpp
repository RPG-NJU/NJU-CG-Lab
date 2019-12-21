#include "ClipDialog.h"
#include "ui_ClipDialog.h"

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
	emit clip_data(ui->id->text().toInt(), ui->x1->text().toInt(), ui->y1->text().toInt(), ui->x2->text().toInt(), ui->y2->text().toInt(), uid);
	return;
}

void ClipDialog::receive(const time_t uid, bool flag)
{
	if (uid == this->uid && flag == true)
		this->close();
	return;
}


