#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TranslateDialog.h"

/*
 * 这个文件用于对应mainwindow中的“图元”下拉菜单
 */


void MainWindow::on_actionInputTranslate_triggered()
{
	time_t uid(time(0));
	TranslateDialog* translate_dialog = new TranslateDialog(uid, this);

	translate_dialog->show();

	connect(translate_dialog, &TranslateDialog::translate_data, this->ui->drawingArea, &DrawingArea::inputTranslate);
	connect(this->ui->drawingArea, &DrawingArea::dialogStatus, translate_dialog, &TranslateDialog::receive);

	return;
}