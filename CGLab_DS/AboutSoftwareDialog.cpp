#include "AboutSoftwareDialog.h"
#include "ui_AboutSoftwareDialog.h"

#include <windows.h>
#include <shellapi.h>

AboutSoftwareDialog::AboutSoftwareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutSoftwareDialog)
{
    ui->setupUi(this);
}

AboutSoftwareDialog::~AboutSoftwareDialog()
{
    delete ui;
}

void AboutSoftwareDialog::on_buttonUserMenu_clicked()
{
	ShellExecute(nullptr, L"open", L"https://github.com/HELLORPG/RPG-DrawingSoftware/blob/master/%E4%BD%BF%E7%94%A8%E6%89%8B%E5%86%8C.md", nullptr, nullptr, SW_SHOWMAXIMIZED);
	return;
}

void AboutSoftwareDialog::on_buttonProjectPage_clicked()
{
	ShellExecute(nullptr, L"open", L"https://github.com/HELLORPG/RPG-DrawingSoftware", nullptr, nullptr, SW_SHOWMAXIMIZED);
	return;
}
