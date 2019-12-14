#include "Primitive.h"

#include <cmath>

using std::sin;
using std::cos;

/*
 * 旋转变换的相关笔记：
 * r为旋转角度，x，y为旋转中心
 * r：逆时针表示为正
 */

int Primitive::rotate_x(int x, int x0, int y, int y0, int r)
{
	const double x_double(static_cast<double>(x)), x0_double(static_cast<double>(x0)), y_double(static_cast<double>(y)), y0_double(static_cast<double>(y0));
	const double r_pi = PI * static_cast<double>(r) / 180.0;
	double x_ret(0.0);
	qDebug() << r_pi << endl;

	x_ret = x0_double + (x_double - x0_double) * cos(r_pi) - (y_double - y0_double) * sin(r_pi);
	return static_cast<int>(x_ret);
}

int Primitive::rotate_y(int y, int y0, int x, int x0, int r)
{
	const double x_double(static_cast<double>(x)), x0_double(static_cast<double>(x0)), y_double(static_cast<double>(y)), y0_double(static_cast<double>(y0));
	const double r_pi = PI * static_cast<double>(r) / 180.0;
	double y_ret(0.0);

	y_ret = y0_double + (x_double - x0_double) * sin(r_pi) + (y_double - y0_double) * cos(r_pi);
	return static_cast<int>(y_ret);
}




void StraightLine::rotate(const int x, const int y, const int r)
{
	const int temp_begin_x(begin_x), temp_begin_y(begin_y), temp_end_x(end_x), temp_end_y(end_y);
	begin_x = Primitive::rotate_x(temp_begin_x, x, temp_begin_y, y, r);
	begin_y = Primitive::rotate_y(temp_begin_y, y, temp_begin_x, x, r);
	end_x = Primitive::rotate_x(temp_end_x, x, temp_end_y, y, r);
	end_y = Primitive::rotate_y(temp_end_y, y, temp_end_x, x, r);
	return;
}

void Ellipse::rotate(const int x, const int y, const int r)
{
	/*const int temp_x0(x0), temp_y0(y0);
	x0 = Primitive::rotate_x(temp_x0, x, temp_y0, y, r);
	y0 = Primitive::rotate_y(temp_y0, y, temp_x0, x, r);
	return;*/
	return;
}

void Polygon::rotate(const int x, const int y, const int r)
{
	for (auto &vertex : vertices)
	{
		const int temp_x(vertex.x), temp_y(vertex.y);
		vertex.x = Primitive::rotate_x(temp_x, x, temp_y, y, r);
		vertex.y = Primitive::rotate_y(temp_y, y, temp_x, x, r);
	}
	return;
}

void Curve::rotate(const int x, const int y, const int r)
{
	for (auto &fixed_point : fixed_points)
	{
		const int temp_x(fixed_point.x), temp_y(fixed_point.y);
		fixed_point.x = Primitive::rotate_x(temp_x, x, temp_y, y, r);
		fixed_point.y = Primitive::rotate_y(temp_y, y, temp_x, x, r);
	}
	return;
}


