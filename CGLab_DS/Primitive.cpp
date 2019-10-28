#include "Primitive.h"

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

