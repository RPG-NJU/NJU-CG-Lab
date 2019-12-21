#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TranslateDialog.h"
#include "ScaleDialog.h"

/*
 * 这个文件用于对应mainwindow中的“图元”下拉菜单
 */


void MainWindow::on_actionInputTranslate_triggered()
{
	const time_t uid(time(0));
	TranslateDialog* translate_dialog = new TranslateDialog(uid, this);

	translate_dialog->show();

	connect(translate_dialog, &TranslateDialog::translate_data, this->ui->drawingArea, &DrawingArea::inputTranslate);
	connect(this->ui->drawingArea, &DrawingArea::dialogStatus, translate_dialog, &TranslateDialog::receive);

	return;
}

void MainWindow::on_actionInputRotate_triggered()
{
	
}

void MainWindow::on_actionInputScale_triggered()
{
	const time_t uid(time(nullptr));
	ScaleDialog* scale_dialog = new ScaleDialog(uid, this);

	scale_dialog->show();

	connect(scale_dialog, &ScaleDialog::scale_data, ui->drawingArea, &DrawingArea::inputScale);
	connect(ui->drawingArea, &DrawingArea::dialogStatus, scale_dialog, &ScaleDialog::receive);

	return;
}

void MainWindow::on_actionInputClip_triggered()
{

}