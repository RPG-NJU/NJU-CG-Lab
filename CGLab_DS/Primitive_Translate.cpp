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
	x0 += dx;
	y0 += dy;
	return;
}

void Polygon::translate(const int dx, const int dy)
{
	for (auto &vertex : vertices)
	{
		vertex.x += dx;
		vertex.y += dy;
	}
	return;
}
