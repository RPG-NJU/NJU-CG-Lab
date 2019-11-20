#include "DrawingArea.h"
#include "mainwindow.h"


// 对外接口

QImage DrawingArea::getPaper() const
{
	return paper;
}


void DrawingArea::setPenColor(QColor color)
{
	pen.setColor(color);
	return;
}


void DrawingArea::setPaperSize(int x, int y)
{
	this->setGeometry(0, 0, x, y);
	//setMinimumSize(x, y);
	//QImage old_paper = paper;
	//QRect rect(0, 0, x, y);
	//paper = old_paper.copy(rect);
	paper = QImage(x, y, QImage::Format_RGB32);
	tempPaper = paper;

	emit setPaperSizeSignal(x, y);
	
	clearPaper(true);
	drawAll();
	
	return;
}



void DrawingArea::changePenMode(const DrawMode new_mode)
{
	drawMode = new_mode;

#ifdef PRINT_PEN
	QString penModeStr = penModeToQString(drawMode);
	qDebug() << "[Change Pen Mode to" << penModeStr << "]" << endl;
#endif


	return;
}



void DrawingArea::drawAll()
{

	QPen now_pen = pen; // 保存当前的pen
	for (const auto &p : primitives)
	{
		vector<MyPoint> points;
		pen = p->_pen();
		switch (p->_type())
		{
		case PrimitiveType::None: break;
		case PrimitiveType::Nature: break; // 目前没有解决自然线条的绘制
		case PrimitiveType::StraightLine:
		{
			StraightLinePrimitive* p_straightline = dynamic_cast<StraightLinePrimitive*>(p);
			// 这里需要讨论使用的算法的区别
			StraightLineAlgorithm algorithm = p_straightline->_algorithm();
			//qDebug() << (algorithm == StraightLineAlgorithm::DDA ? "-DDA" : "-Bresenham") << endl;
			switch (algorithm)
			{
			case StraightLineAlgorithm::Bresenham: points = createStraightLineByBresenham(p_straightline->x1(), p_straightline->y1(), p_straightline->x2(), p_straightline->y2()); break;
			case StraightLineAlgorithm::DDA: points = createStraightLineByDDA(p_straightline->x1(), p_straightline->y1(), p_straightline->x2(), p_straightline->y2()); break;
			case StraightLineAlgorithm::None: points = createStraightLineByNone(p_straightline->x1(), p_straightline->y1(), p_straightline->x2(), p_straightline->y2()); break;
			}
			//points = createStraightLineByBresenham(p_straightline->x1(), p_straightline->y1(), p_straightline->x2(), p_straightline->y2());
		}break;
		case PrimitiveType::Ellipse:
		{
			EllipsePrimitive* p_ellipse = dynamic_cast<EllipsePrimitive*>(p);
			points = createEllipse(p_ellipse->_x0(), p_ellipse->_y0(), p_ellipse->_rx(), p_ellipse->_ry());
		}break;
		}
		QPainter painter(&paper); // 使用QImage初始化QPainter，需要使用指针
		painter.setPen(pen);
		
		for (const auto &point : points)
		{
			painter.drawPoint(point.x, point.y);
		}
	}
	pen = now_pen;
	tempPaper = paper;
	
	this->update(); // 更新窗体，可以使得QWidget调用paintEvent函数，绘制窗体
	
	return;
}


void DrawingArea::clearPaper(bool save_primitives)
{
	paper.fill(paperBackground);
	tempPaper.fill(paperBackground);

	if (!save_primitives)
		primitives.clear();
	 
	this->update();
	return;
}

void DrawingArea::appendPrimitiveByMouseEvent()
{
	switch (drawMode)
	{
	case DrawMode::None: break; // 此时没有需要添加的图元
	case DrawMode::StraightLine:
	{
		primitives.push_back(new StraightLinePrimitive(begin_point, end_point, pen, now_primitive_num));
	}break;
	case DrawMode::Circle:
	{
		primitives.push_back(new EllipsePrimitive((begin_point.x() + end_point.x()) / 2, (begin_point.y() + end_point.y()) / 2,
			abs(begin_point.x() - end_point.x()) / 2, abs(begin_point.x() - end_point.x()) / 2, now_primitive_num, pen));
	}break;
	case DrawMode::Ellipse:
	{
		primitives.push_back(new EllipsePrimitive(begin_point, end_point, pen, now_primitive_num));
	}break;
	}

	++now_primitive_num;

	for (auto x : primitives)
	{
		x->print();
	}

	return;
}


void DrawingArea::appendStraightLinePrimitive(int x1, int y1, int x2, int y2, int p_num, QPen pen, StraightLineAlgorithm algorithm)
{
	primitives.push_back(new StraightLinePrimitive(x1, y1, x2, y2, p_num, pen, algorithm));
	return;
}

void DrawingArea::appendEllipsePrimitive(int x0, int y0, int rx, int ry, int p_num, QPen pen)
{
	primitives.push_back(new EllipsePrimitive(x0, y0, rx, ry, p_num, pen));
}


void DrawingArea::setOutputPath(string dir_path)
{
	output_path = dir_path;
	return;
}

// 对外接口结束