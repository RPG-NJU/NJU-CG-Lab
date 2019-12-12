#include "Primitive.h"


void Primitive::print() const
{
	qDebug() << "[图元 #" << p_num << "]" << endl;
}

void StraightLine::print() const
{
	qDebug() << "[图元 #" << p_num << "    直线]";
	qDebug() << "起点：" << begin_x << "," << begin_y;
	qDebug() << "终点：" << end_x << "," << end_y;
	qDebug() << "算法：" << (algorithm == StraightLineAlgorithm::DDA ? "DDA" : "Bresenham");
	qDebug() << endl;

	return;
}

void Ellipse::print() const
{
	qDebug() << "[图元 #" << p_num << "    椭圆]";
	qDebug() << "圆心：" << x0 << "," << y0;
	qDebug() << "半径    rx=" << rx << " ry=" << ry;
	qDebug() << endl;

	return;
}

void Polygon::print() const
{
	qDebug() << "[图元 #" << p_num << "    "<< vertices.size() << "多边形]";
	
	qDebug() << "算法：" << (algorithm == StraightLineAlgorithm::DDA ? "DDA" : "Bresenham"); // 之所以只进行二元判断，是因为我们在实验中确实只使用了两种算法，DDA和Bresenham
	
	return;
}

bool StraightLine::setDataByMouseEvent(int p_num, QPen pen, QPoint begin_xy, QPoint end_xy)
{
	if (type != PrimitiveType::None) // 此时不可以设定数据
		return false;
	
	this->p_num = p_num;
	pen_in_use = pen;
	type = PrimitiveType::StraightLine;

	begin_x = begin_xy.x();
	begin_y = begin_xy.y();
	end_x = end_xy.x();
	end_y = end_xy.y();

	return true;
}

Ellipse::Ellipse(QPoint begin, QPoint end, QPen pen, int p_num) : Primitive(p_num, pen, PrimitiveType::Ellipse)
{
	int x1(begin.x()), x2(end.x()), y1(begin.y()), y2(end.y());

	x0 = (x1 + x2) / 2;
	y0 = (y1 + y2) / 2;

	rx = abs(x2 - x1) / 2;
	ry = abs(y2 - y1) / 2;
}


void Polygon::addPoint()
{
	MyPoint point = vertices[vertices.size() - 1];
	vertices.push_back(point);

	return;
}


void Curve::print() const
{
	qDebug() << "[图元 #" << p_num << "    " << fixed_points.size() << "点曲线]";
	qDebug() << "算法：" << (algorithm == CurveAlgorithm::B_spline ? "B_spline" : "Bezier");
	return;
}



