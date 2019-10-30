#include "Primitive.h"


void Primitive::print() const
{
	qDebug() << "[图元 #" << p_num << "]" << endl;
}

void StraightLinePrimitive::print() const
{
	qDebug() << "[图元 #" << p_num << "    直线]" << endl;
	qDebug() << "起点：" << begin_x << "," << begin_y << endl;
	qDebug() << "终点：" << end_x << "," << end_y << endl;
	qDebug() << endl;

	return;
}

void EllipsePrimitive::print() const
{
	qDebug() << "[图元 #" << p_num << "    椭圆]" << endl;
	qDebug() << "圆心：" << x0 << "," << y0 << endl;
	qDebug() << "半径    rx=" << rx << " ry=" << ry << endl;
	qDebug() << endl;

	return;
}

bool StraightLinePrimitive::setDataByMouseEvent(int p_num, QPen pen, QPoint begin_xy, QPoint end_xy)
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

EllipsePrimitive::EllipsePrimitive(QPoint begin, QPoint end, QPen pen, int p_num) : Primitive(p_num, pen, PrimitiveType::Ellipse)
{
	int x1(begin.x()), x2(end.x()), y1(begin.y()), y2(end.y());

	x0 = (x1 + x2) / 2;
	y0 = (y1 + y2) / 2;

	rx = abs(x2 - x1) / 2;
	ry = abs(y2 - y1) / 2;
}



