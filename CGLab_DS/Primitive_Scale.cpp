#include "Primitive.h"

int Primitive::scale_t(int t, int t0, double s)
{
	// 在这个函数中，t作为一个参数，既可以承载x，也可以承载y，所以用t作为一个通用的参数
	double t_double(static_cast<double>(t)), t0_double(static_cast<double>(t0)), t_ret(0.0);
	t_ret = t_double * s + t0_double * (1.0 - s);
	return t_ret;
}


void StraightLine::scale(const int x, const int y, const double s)
{
	begin_x = Primitive::scale_t(begin_x, x, s);
	begin_y = Primitive::scale_t(begin_y, y, s);
	end_x = Primitive::scale_t(end_x, x, s);
	end_y = Primitive::scale_t(end_y, y, s);
	return;
}

void Ellipse::scale(const int x, const int y, const double s)
{
	/*
	 * 椭圆的缩放算法没有在PPT中提到
	 * 这里只是写出自己的想法：
	 * 顶点依照直线的缩放原则进行点的变换，同时倍数变换rx和ry
	 */
	x0 = Primitive::scale_t(x0, x, s);
	y0 = Primitive::scale_t(y0, y, s);
	rx = static_cast<int>(static_cast<double>(rx) * s);
	ry = static_cast<int>(static_cast<double>(ry) * s);
	return;
}

void Polygon::scale(const int x, const int y, const double s)
{
	for (auto &vertex : vertices)
	{
		vertex.x = Primitive::scale_t(vertex.x, x, s);
		vertex.y = Primitive::scale_t(vertex.y, y, s);
	}
	return;
}

void Curve::scale(const int x, const int y, const double s)
{
	for (auto &fixed_point : fixed_points)
	{
		fixed_point.x = Primitive::scale_t(fixed_point.x, x, s);
		fixed_point.y = Primitive::scale_t(fixed_point.y, y, s);
	}
	return;
}


