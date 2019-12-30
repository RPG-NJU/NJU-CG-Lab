#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TranslateDialog.h"
#include "ScaleDialog.h"
#include "ClipDialog.h"
#include "RotateDialog.h"

/*
 * 这个文件用于对应mainwindow中的“图元”下拉菜单
 */


void MainWindow::on_actionInputTranslate_triggered()
{
	const time_t uid(time(0));
	TranslateDialog* translate_dialog = new TranslateDialog(uid, this);

	//translate_dialog->show();
	translate_dialog->show();

	connect(translate_dialog, &TranslateDialog::translate_data, ui->drawingArea, &DrawingArea::inputTranslate);
	connect(this->ui->drawingArea, &DrawingArea::dialogStatus, translate_dialog, &TranslateDialog::receive);

	return;
}

void MainWindow::on_actionInputRotate_triggered()
{
	const time_t uid(time(nullptr));
	RotateDialog* rotate_dialog = new RotateDialog(uid, this);

	rotate_dialog->show();

	connect(rotate_dialog, &RotateDialog::rotate_data, ui->drawingArea, &DrawingArea::inputRotate);
	connect(ui->drawingArea, &DrawingArea::dialogStatus, rotate_dialog, &RotateDialog::receive);

	return;
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
	const time_t uid(time(nullptr));
	ClipDialog* clip_dialog = new ClipDialog(uid, this);

	clip_dialog->show();

	connect(clip_dialog, &ClipDialog::clip_data, ui->drawingArea, &DrawingArea::inputClip);
	connect(ui->drawingArea, &DrawingArea::dialogStatus, clip_dialog, &ClipDialog::receive);
	
	return;
}