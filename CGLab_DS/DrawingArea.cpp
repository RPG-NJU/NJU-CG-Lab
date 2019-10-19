#include "DrawingArea.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QString>

#include "Define.h"

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


// 重写事件函数区域
void DrawingArea::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawImage(0, 0, paper);

	return;
}


void DrawingArea::mouseMoveEvent(QMouseEvent* event)
{
	//qDebug() << QString("鼠标位置为") << event->pos() << endl;
	QString x = QString::number(event->pos().x());
	QString y = QString::number(event->pos().y());

#ifdef PRINT_MOUSE_LOCATION
	qDebug() << "当前鼠标的坐标为：" << x << "," << y << endl;
#endif
	
	QString location = "(" + x + "," + y + ")" + 
        "    \xe7\x94\xbb\xe6\x9d\xbf\xe5\xa4\xa7\xe5\xb0\x8f = "/*画板大小*/ + QString::number(INIT_WIDTH) + 
		"\xc3\x97"/*×*/ + QString::number(INIT_HEIGHT);
	// 两串UTF-8编码分别为：画板大小 ×
	// 使用了python来完成编码的转化，str.encode("utf-8")即可
	
	//this->setStatusTip(x + " , " + y);
	emit newLocationStatus(location); // 通过emit发出信号，鼠标位置更新

	return;
}


void DrawingArea::leaveEvent(QEvent* event)
{
	qDebug() << "[Mouse Out]" << endl;
	emit mouseLeave();
}


void DrawingArea::enterEvent(QEvent* event)
{
#ifdef PRINT_MOUSE_EVENT
	qDebug() << "[Mouse In]" << endl;
#endif

	return;
}



void DrawingArea::mousePressEvent(QMouseEvent* event)
{

	if (event->button() == Qt::LeftButton) // 识别左键
	{
#ifdef PRINT_MOUSE_EVENT
		qDebug() << "[Press Mouse Left Button]" << endl;
#endif
	}

	else if (event->button() == Qt::RightButton) // 识别右键
	{
#ifdef PRINT_MOUSE_EVENT
		qDebug() << "[Press Mouse Right Button]" << endl;
#endif
	}

	return;
}


void DrawingArea::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) // 识别左键
	{
#ifdef PRINT_MOUSE_EVENT
		qDebug() << "[Release Mouse Left Button]" << endl;
#endif
	}

	else if (event->button() == Qt::RightButton) // 识别右键
	{
#ifdef PRINT_MOUSE_EVENT
		qDebug() << "[Release Mouse Right Button]" << endl;
#endif
	}

	return;
}


// 重写事件函数终止



// 关于画笔部分的函数

QString DrawingArea::penModeToQString(PaintMode mode)
{
	switch (mode)
	{
	case None: return("None"); 
	case Nature: return("Nature");
	case StraightLine: return("StraightLine");
	default: return("Undefine");
	}
}



void DrawingArea::changePenMode(const PaintMode new_mode)
{
	penMode = new_mode;

#ifdef PRINT_PEN
	QString penModeStr = penModeToQString(penMode);
	qDebug() << "[Change Pen Mode to" << penModeStr << "]" << endl;
#endif


	return;
}


// 关于画笔部分的函数结束