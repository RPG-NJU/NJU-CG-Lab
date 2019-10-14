#include "AboutAuthorDialog.h"
#include "ui_AboutAuthorDialog.h"
//#include <stdio.h>

#include <windows.h>
#include <shellapi.h>

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

void AboutAuthorDialog::on_buttonAuthorGithub_clicked()
{
	//system("start https://github.com/HELLORPG");
	// 这种实现方法并不确定在除了Windows10之外的系统上使用的正确性
	//wchar_t method[5] = "open";
	// 参数形式是wchar_t形式，所以需要使用 L 来解释
	ShellExecute(NULL, L"open", L"https://github.com/HELLORPG", NULL, NULL, SW_SHOWMAXIMIZED);
	// 使用system的方法，会在打开之前产生一个命令行窗口，而使用ShellExecute就不会，不过会有系统兼容性问题
	return;
}

void AboutAuthorDialog::on_buttonConnectAuthor_clicked()
{
	ShellExecute(NULL, L"open", L"mailto:officialrpg2017@gmail.com", NULL, NULL, SW_SHOWNORMAL);
	return;
}
