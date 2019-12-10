#include "DrawingArea.h"

/*
 * 这个文件重新构建了鼠标绘制图像的事件
 * 独立出来文件表示重构信息
 */

void DrawingArea::mouseDraw(QImage& thisPaper)
{
	//if (!temp_primitive)
	//	delete temp_primitive; // 释放空间，防止内存泄漏
	switch (drawMode)
	{
	case DrawMode::None: break;	// 此时是不做图模式
	case DrawMode::Nature: break;	// 自然绘图模式当前没有实现
	case DrawMode::StraightLine: mouseDrawStraightLine(thisPaper, StraightLineAlgorithm::Bresenham); break;	// 默认使用Bresenham算法进行绘制
	case DrawMode::Circle: mouseDrawCircle(thisPaper); break;
	case DrawMode::Ellipse: mouseDrawEllipse(thisPaper); break;
	case DrawMode::Polygon: mouseDrawPolygon(thisPaper, StraightLineAlgorithm::Bresenham); break;
	default: break; // 如果找不到对应的，就不做任何处理
	}

	drawPrimitive(temp_primitive, thisPaper);
	return;
}

void DrawingArea::mouseDrawAdd(QImage& thisPaper)
{
	switch (drawMode)
	{
	case DrawMode::Polygon: mouseDrawPolygonAddPoint(thisPaper);
	}
}



void DrawingArea::mouseDrawCircle(QImage& thisPaper)
{
	if (!temp_primitive)
		delete temp_primitive; // 释放空间，防止内存泄漏
	
	int x1 = begin_point.x(), x2 = end_point.x();
	int y1 = begin_point.y(), y2 = end_point.y();
	int x0 = (x2 + x1) / 2;
	int y0 = (y2 + y1) / 2;
	int rx = abs(x2 - x1) / 2;
	int ry = abs(y2 - y1) / 2;

	ry > rx ? rx = ry : rx = rx;

	temp_primitive = new Ellipse(x0, y0, rx, rx, now_primitive_num, pen);
	//temp_primitive->print();
	return;
}

void DrawingArea::mouseDrawEllipse(QImage& thisPaper)
{
	if (!temp_primitive)
		delete temp_primitive; // 释放空间，防止内存泄漏
	
	const int x1 = begin_point.x(), x2 = end_point.x();
	const int y1 = begin_point.y(), y2 = end_point.y();

	const int x0 = (x2 + x1) / 2;
	const int y0 = (y2 + y1) / 2;
	const int rx = abs(x2 - x1) / 2;
	const int ry = abs(y2 - y1) / 2;

	temp_primitive = new Ellipse(x0, y0, rx, ry, now_primitive_num, pen);
	return;
}

void DrawingArea::mouseDrawPolygon(QImage& thisPaper, const StraightLineAlgorithm algorithm)
{
	if (temp_primitive && temp_primitive->_type() == PrimitiveType::Polygon) // 此时，如果已经是多边形
	{
		Polygon* polygon = dynamic_cast<Polygon*>(temp_primitive);
		polygon->setTail(end_point.x(), end_point.y());
	}

	else
	{
		if (!temp_primitive)
			delete temp_primitive;

		vector<MyPoint> vertices;
		vertices.push_back({ begin_point.x(), begin_point.y() });
		vertices.push_back({ end_point.x(), end_point.y() });

		temp_primitive = new Polygon(vertices, now_primitive_num, pen, algorithm);
	}

	return;
}

void DrawingArea::mouseDrawPolygonAddPoint(QImage& thisPaper)
{
	if (temp_primitive && temp_primitive->_type() == PrimitiveType::Polygon) // 此时，如果已经是多边形
	{
		Polygon* polygon = dynamic_cast<Polygon*>(temp_primitive);
		polygon->addPoint();
	}
	return;
}


void DrawingArea::mouseDrawStraightLine(QImage& thisPaper, const StraightLineAlgorithm algorithm)
{
	if (!temp_primitive)
		delete temp_primitive; // 释放空间，防止内存泄漏
	
	int x1 = begin_point.x(), x2 = end_point.x();
	int y1 = begin_point.y(), y2 = end_point.y();

	temp_primitive = new StraightLine(x1, y1, x2, y2, now_primitive_num, pen, algorithm);
	return;
}



