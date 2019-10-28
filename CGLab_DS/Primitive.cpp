#include "Primitive.h"

Primitive::Primitive(int p_num) : p_num(p_num)
{
	type = PrimitiveType::None;
	// 只有type为None的时候，才可以进行set图元操作
}


void StraightLinePrimitive::setData(int x1, int y1, int x2, int y2)
{
	begin_x = x1;
	begin_y = y1;
	end_x = x2;
	end_y = y2;
}


bool Primitive::setStraightLine(int x1, int y1, int x2, int y2, QPen pen)
{
	if (type != PrimitiveType::None)
		return false;
	
	pen_in_use = pen;
	straight_line.setData(x1, y1, x2, y2);
	return true;
}
