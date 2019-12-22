#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * 这个文件中，放置了关于Select选择部分的所有函数定义
 */
void MainWindow::setToolBarEnable(const bool enable, const SetToolBarEnableMode mode)
{
	switch (mode)
	{
	case SetToolBarEnableMode::DrawMode:
	{
		ui->actionStraightLine->setEnabled(enable);
		ui->actionCircle->setEnabled(enable);
		ui->actionEllipse->setEnabled(enable);
		ui->actionPolygon->setEnabled(enable);
		ui->actionCurveBezier->setEnabled(enable);
		ui->actionCurveB_spline->setEnabled(enable);
	} break;
	case SetToolBarEnableMode::Primitive:
	{
		ui->actionInputClip->setEnabled(enable);
		ui->actionInputRotate->setEnabled(enable);
		ui->actionInputScale->setEnabled(enable);
		ui->actionInputTranslate->setEnabled(enable);
	} break;
	}
}


void MainWindow::selectBegin()
{
	clearToolBarChecked(ClearToolBarCheckedMode::All);
	ui->actionSelect->setChecked(true);

	setToolBarEnable(false, SetToolBarEnableMode::DrawMode); // 关闭绘图模式
	setToolBarEnable(false, SetToolBarEnableMode::Primitive); // 关闭输入框的图元变化模式

	return;
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

void MainWindow::on_actionCancelSelect_triggered() // 退出选择模式
{
	ui->actionSelect->setChecked(false);

	setToolBarEnable(true, SetToolBarEnableMode::DrawMode);
	setToolBarEnable(true, SetToolBarEnableMode::Primitive);

	return;
}


