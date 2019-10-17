#include "DrawingArea.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QString>

//constexpr int INIT_WIDTH = 800;
#define INIT_WIDTH 800
#define INIT_HEIGHT 600


DrawingArea::DrawingArea(QWidget* parent) : QWidget(parent)
{
	/*qDebug() << this->width() << " " << this->height() << endl;
    qDebug() << this->geometry().width() << " " << this->geometry().height() << endl;*/
	/*
	 * 在这里通过这种方式是无法获得在Qt Designer中设计好的DrawingArea的大小的
	 * 这是因为，在ui_mainwindow.h的初始化中，是先调用了new DrawingArea函数，然后才进行setGeometry设定的，所以此时还无法捕获大小
	 */
	paper = QImage(INIT_WIDTH, INIT_HEIGHT, QImage::Format_RGB32);
	paper.fill(qRgb(255, 255, 255));
	/*QPainter painter(this);
	painter.drawImage(0, 0, paper);*/
	// 需要重写绘图函数paintEvent来完成
	this->setMouseTracking(true);
	
	return;
}

void DrawingArea::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawImage(0, 0, paper);

	return;
}

void DrawingArea::mouseMoveEvent(QMouseEvent* event)
{
	qDebug() << QString("鼠标位置为") << event->pos() << endl;
	QString x = QString::number(event->pos().x());
	QString y = QString::number(event->pos().y());
	qDebug() << x << "," << y << endl;
	QString location = x + " , " + y;
	
	//this->setStatusTip(x + " , " + y);
	emit newLocation(location);

	return;
}


