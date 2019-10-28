#include "Primitive.h"


void Primitive::print() const
{
	qDebug() << "[图元 #" << p_num << "]" << endl;
}

void StraightLinePrimtive::print() const
{
	qDebug() << "[图元 #" << p_num << "    直线]" << endl;
	qDebug() << "起点：" << begin_x << "," << begin_y << endl;
	qDebug() << "终点：" << end_x << "," << end_y << endl;
	qDebug() << endl;

	return;
}



bool StraightLinePrimtive::setDataByMouseEvent(int p_num, QPen pen, QPoint begin_xy, QPoint end_xy)
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

