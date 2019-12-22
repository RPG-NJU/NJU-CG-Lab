#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * 这个文件中，放置了关于Select选择部分的所有函数定义
 */
void MainWindow::setToolBarEnable(const bool enable, const SetToolBarEnableMode mode)
{
	
}


void MainWindow::selectBegin()
{
	clearToolBarChecked(ClearToolBarCheckedMode::All);
	ui->actionSelect->setChecked(true);

	ui->actionCurveBezier->setEnabled(false);
}

void MainWindow::selectEnd()
{
	return;
}

void MainWindow::selectAreaEnd()
{
	return;
}


void MainWindow::on_actionSelect_triggered()
{
	/*QRubberBand* qrb = new QRubberBand(QRubberBand::Line, this);
	qrb->resize(100, 100);
	qrb->move(100, 100);
	qrb->setBackgroundRole(QPalette::Light);
	qrb->setAutoFillBackground(false);
	qrb->show();*/
	selectBegin();
	return;
}


