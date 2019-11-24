#include "Primitive.h"

void StraightLine::translate(const int dx, const int dy)
{
	begin_x += dx;
	begin_y += dy;
	end_x += dx;
	end_y += dy;
	return;
}


void Ellipse::translate(const int dx, const int dy)
{
	
}

void Polygon::translate(const int dx, const int dy)
{
	
}
