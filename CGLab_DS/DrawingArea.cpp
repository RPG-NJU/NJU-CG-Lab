#include "DrawingArea.h"

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
	paperBackground = qRgb(255, 255, 255);
	paper = QImage(INIT_WIDTH, INIT_HEIGHT, QImage::Format_RGB32);
	paper.fill(paperBackground);
	tempPaper = paper;
	/*QPainter painter(this);
	painter.drawImage(0, 0, paper);*/
	// 需要重写绘图函数paintEvent来完成

	pen.setWidth(1);
	pen.setColor(qRgb(0, 0, 0));

	// ----------选择框初始化----------
	/*QRubberBand* qrb = new QRubberBand(QRubberBand::Line, this);
	qrb->resize(100, 100);
	qrb->move(100, 100);
	qrb->setBackgroundRole(QPalette::Light);
	qrb->setAutoFillBackground(false);
	qrb->show();*/
	selectedArea = new QRubberBand(QRubberBand::Line, this);
	selectedArea->setBackgroundRole(QPalette::Light);
	selectedArea->setAutoFillBackground(false);
	// ----------选择框初始化----------

	this->setMouseTracking(true);
	this->update();

	//show_command_text = new QTextEdit(this);
	return;
}




// 关于画笔部分的函数

QString DrawingArea::penModeToQString(DrawMode mode)
{
	switch (mode)
	{
	case DrawMode::None: return("None");
	case DrawMode::Nature: return("Nature");
	case DrawMode::StraightLine: return("StraightLine");
	default: return("Undefine");
	}
}


// 关于画笔部分的函数结束


// 关于绘图的函数

void DrawingArea::draw(QImage& thisPaper)
{
	switch (drawMode)
	{
	case DrawMode::None: break; // 此时不做任何操作
	case DrawMode::Nature: break; // 目前没有实现这种方法
	case DrawMode::StraightLine:
	{
#ifdef PRINT_DRAW
		qDebug() << "[Draw Line " << begin_point << "to" << end_point << "]" << endl;
#endif
		//drawStraightLine(tempPaper, begin_point, end_point, StraightLineAlgorithm::None); // 这里实现的算法是可选的
		//drawStraightLine(tempPaper, begin_point, end_point, StraightLineAlgorithm::DDA);
		drawStraightLine(tempPaper, begin_point, end_point, StraightLineAlgorithm::Bresenham);
	}break;
	case DrawMode::Circle:
	{
#ifdef PRINT_DRAW
		qDebug() << "[Draw Circle " << begin_point << "to" << end_point << "]" << endl;
#endif
		drawCircle(tempPaper, begin_point, end_point);
	}break;
	case DrawMode::Ellipse:
	{
#ifdef PRINT_DRAW
		qDebug() << "[Draw Ellipse " << begin_point << "to" << end_point << "]" << endl;
#endif
		drawEllipse(tempPaper, begin_point, end_point);
	}
	}
	return;
}



// 弃用重写事件函数区域

//void DrawingArea::mousePressEvent(QMouseEvent* event)
//{
//
//	if (event->button() == Qt::LeftButton) // 识别左键
//	{
//#ifdef PRINT_MOUSE_EVENT
//		qDebug() << "[Press Mouse Left Button]" << endl;
//#endif
//		if (!isDrawing)
//		{
//			isDrawing = true;
//			begin_point = event->pos(); // 获得当前鼠标的位置
//			end_point = event->pos(); // 增加这行代码为了防止在点击和释放中间没有移动鼠标而导致的错误图元问题
//		}
//	}
//
//	else if (event->button() == Qt::RightButton) // 识别右键
//	{
//#ifdef PRINT_MOUSE_EVENT
//		qDebug() << "[Press Mouse Right Button]" << endl;
//#endif
//	}
//
//	this->update();
//	return;
//}





//void DrawingArea::mouseReleaseEvent(QMouseEvent* event)
//{
//	if (event->button() == Qt::LeftButton) // 识别左键
//	{
//#ifdef PRINT_MOUSE_EVENT
//		qDebug() << "[Release Mouse Left Button]" << endl;
//#endif
//
//		if (isDrawing)
//		{
//			isDrawing = false;
//
//			// 此时应该将缓存的直线刷新进入真实图片
//			paper = tempPaper;
//			this->update();
//
//			// 同时还需要，存储图元信息
//			appendPrimitiveByMouseEvent();
//		}
//	}
//
//	else if (event->button() == Qt::RightButton) // 识别右键
//	{
//#ifdef PRINT_MOUSE_EVENT
//		qDebug() << "[Release Mouse Right Button]" << endl;
//#endif
//	}
//
//	return;
//}

// 终止



