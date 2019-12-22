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

	ui->drawingArea->beginSelect();
	//ui->drawingArea->setIsSelectArea(true);
	return;
}

void MainWindow::selectEnd()
{
	ui->actionSelect->setChecked(false);

	setToolBarEnable(true, SetToolBarEnableMode::DrawMode);
	setToolBarEnable(true, SetToolBarEnableMode::Primitive);

	ui->drawingArea->endSelect();

	// ----------恢复绘图模式的显示----------
	switch (ui->drawingArea->getDrawMode())
	{
	case DrawMode::StraightLine: ui->actionStraightLine->setChecked(true); break;
	case DrawMode::Circle: ui->actionCircle->setChecked(true); break;
	case DrawMode::Ellipse: ui->actionEllipse->setChecked(true); break;
	case DrawMode::Polygon: ui->actionPolygon->setChecked(true); break;
	case DrawMode::Curve_Bezier: ui->actionCurveBezier->setChecked(true); break;
	case DrawMode::Curve_B_spline: ui->actionCurveB_spline->setChecked(true); break;
	default: break;
	}
	// ----------
	return;
}

void MainWindow::selectAreaEnd()
{
	return;
}


void MainWindow::on_actionSelect_triggered()
{

	selectBegin();
	return;
}

void MainWindow::on_actionCancelSelect_triggered() // 退出选择模式
{
	selectEnd();
	return;
}


void MainWindow::on_actionMouseTranslate_triggered()
{
	ui->drawingArea->setIsTranslate(true);
	ui->drawingArea->setIsClip(false);
	ui->drawingArea->setIsRotate(false);
	ui->drawingArea->setIsScale(false);

	ui->actionMouseTranslate->setChecked(true);
	
	return;
}
