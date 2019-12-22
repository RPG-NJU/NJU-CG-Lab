#include "DrawingArea.h"

/*
 * 该文件实现了所有的事件触发函数
 * 几乎所有的Event函数都是在这里重写实现的
 */


// 重写绘制函数
void DrawingArea::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);

	if (isSelect)
	{
		clearPaper(true);
		drawAllincludeSelected();
	}

	//painter.drawImage(0, 0, paper);
	//isDrawing ? painter.drawImage(0, 0, tempPaper) : painter.drawImage(0, 0, paper);	// 当处于画图阶段的时候，输出的是临时图像，否则则为真实图像
	if (isDrawing)
	{
		if (drawMode == DrawMode::Curve_B_spline || drawMode == DrawMode::Curve_Bezier)
		{
			painter.drawImage(0, 0, temptempPaper);
		}
		else
		{
			painter.drawImage(0, 0, tempPaper);
		}
	}
	else // 此时不是在绘图
	{
		painter.drawImage(0, 0, paper);
	}
	return;
}


// 重写鼠标点击函数
void DrawingArea::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) // 识别左键
	{
#ifdef PRINT_MOUSE_EVENT
		qDebug() << "[Press Mouse Left Button]" << endl;
#endif
		if (!isSelect && !isDrawing)
		{
			isDrawing = true;
			begin_point = event->pos(); // 获得当前鼠标的位置
			end_point = event->pos(); // 增加这行代码为了防止在点击和释放中间没有移动鼠标而导致的错误图元问题

			tempPaper = paper; // 将当前的图层保存到临时图层，之后都基于临时图层进行操作
			mouseDraw(tempPaper);
		}

		else if (isDrawing) // 此时的逻辑是终止绘图
		{
			isDrawing = false;
			if (temp_primitive != nullptr) // 当前图元不为空，为空则跳过
			{
				primitives.push_back(temp_primitive);
				now_primitive_num++;
				paper = tempPaper;
				temp_primitive = nullptr;
			}
		}

		else if (isSelectArea) // 此时是正在选择区域
		{
			begin_point = event->pos();
			end_point = event->pos();
			selectedArea->move(begin_point);
			selectedArea->resize(0, 0);
			selectedArea->show();
		}
	}

	else if (event->button() == Qt::RightButton) // 识别右键，用于如多边形，曲线的增加信息点
	{
#ifdef PRINT_MOUSE_EVENT
		qDebug() << "[Press Mouse Right Button]" << endl;
#endif
		if (isDrawing) // 如果正在绘图
		{
			mouseDrawAdd(tempPaper);
			tempPaper = paper; // 将当前的图层保存到临时图层，之后都基于临时图层进行操作
			mouseDraw(tempPaper);
		}
	}

	this->update();
	return;
}


// 重写鼠标释放函数
void DrawingArea::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) // 识别左键
	{
#ifdef PRINT_MOUSE_EVENT
		qDebug() << "[Release Mouse Left Button]" << endl;
#endif
		if (isSelectArea)
		{
			isSelectArea = false;
			selectPrimitive(begin_point, end_point);
			selectedArea->hide();
		}
	}
	else if (event->button() == Qt::RightButton) // 识别右键
	{
#ifdef PRINT_MOUSE_EVENT
		qDebug() << "[Release Mouse Right Button]" << endl;
#endif
	}
	return;
}


// 重写鼠标移动函数
void DrawingArea::mouseMoveEvent(QMouseEvent* event)
{
	//qDebug() << QString("鼠标位置为") << event->pos() << endl;
	QString x = QString::number(event->pos().x());
	QString y = QString::number(event->pos().y());

#ifdef PRINT_MOUSE_LOCATION
	qDebug() << "当前鼠标的坐标为：" << x << "," << y << endl;
#endif

	QString location = "(" + x + "," + y + ")" +
		"    \xe7\x94\xbb\xe6\x9d\xbf\xe5\xa4\xa7\xe5\xb0\x8f = "/*画板大小*/ + QString::number(this->getXsize()) +
		"\xc3\x97"/*×*/ + QString::number(this->getYsize());
	// 两串UTF-8编码分别为：画板大小 ×
	// 使用了python来完成编码的转化，str.encode("utf-8")即可

	//this->setStatusTip(x + " , " + y);
	emit newLocationStatus(location); // 通过emit发出信号，鼠标位置更新


	// 应当进行相关的画图工作

	if (isDrawing) // 此时正在绘图
	{
		end_point = event->pos(); // 获取移动时的鼠标位置
		tempPaper = paper; // 将当前的图层保存到临时图层，之后都基于临时图层进行操作
		// 之后进行draw操作
		//draw(tempPaper); //进行绘图操作
		mouseDraw(tempPaper);
	}

	else if (isSelectArea) // 选择区域
	{
		end_point = event->pos();
		selectedArea->resize(abs(end_point.x() - begin_point.x()), abs(end_point.y() - begin_point.y()));

		// ----------对方位进行讨论----------
		if (begin_point.x() <= end_point.x() && begin_point.y() <= end_point.y())
			selectedArea->move(begin_point);
		else if (end_point.x() < begin_point.x() && end_point.y() < begin_point.y())
			selectedArea->move(end_point);
		else if (end_point.x() < begin_point.x() && end_point.y() > begin_point.y())
			selectedArea->move(end_point.x(), begin_point.y());
		else
			selectedArea->move(begin_point.x(), end_point.y());
		// ----------对方位进行讨论----------
	}
	this->update();
	// END of Drawing Works
	return;
}


// 重写鼠标离开窗体函数
void DrawingArea::leaveEvent(QEvent* event)
{
	qDebug() << "[Mouse Out]" << endl;

	//// 此时，需要判定位鼠标已经抬起，也就是要终止所有的画图事件
	//isDrawing = false;
	/* 不需要这一段代码
	 * 这是因为当鼠标处于press状态下移出widget的时候，并不会停止坐标的捕获
	 * 事实上，这个时候鼠标的坐标显示可能是超出画布大小的
	 * 这个时候，保持绘画的状态不解除
	 */
	emit mouseLeave();
}


// 重写鼠标进入窗体函数
void DrawingArea::enterEvent(QEvent* event)
{
#ifdef PRINT_MOUSE_EVENT
	qDebug() << "[Mouse In]" << endl;
#endif

	return;
}