#include "TranslateDialog.h"
#include "ui_TranslateDialog.h"
#include "GeneralMessageBox.h"

TranslateDialog::TranslateDialog(time_t uid, QWidget *parent) :
    QDialog(parent), uid(uid),
    ui(new Ui::TranslateDialog)
{
    ui->setupUi(this);
}

TranslateDialog::~TranslateDialog()
{
    delete ui;
}


void TranslateDialog::accept()
{
	if (ui->primitive_id->text().isEmpty() || ui->dx->text().isEmpty() || ui->dy->text().isEmpty())
	{
		GeneralMessageBox::NotCompleteArg(this);
		return;
	}
	emit translate_data(this->ui->primitive_id->text().toInt(), this->ui->dx->text().toInt(), this->ui->dy->text().toInt(), uid); // ´«³öÐÅºÅ
	//this->close();
	return;
}

void TranslateDialog::receive(const time_t uid, bool flag)
{
	if (uid == this->uid && flag == true)
		this->close();
	return;
}

