#include "Define.h"


MyPoint_double operator+(const MyPoint_double left, const MyPoint_double right)
{
	return { left.x + right.x, left.y + right.y };
}

MyPoint_double operator*(const MyPoint_double left, const MyPoint_double right)
{
	return { left.x * right.x, left.y * right.y };
}

MyPoint_double operator*(const double left, const MyPoint_double right)
{
	return { left * right.x, left * right.y };
}

MyPoint_double operator*(const MyPoint left, const MyPoint_double right)
{
	return { left.x * right.x, left.y * right.y };
}

MyPoint_double operator*(const MyPoint left, const double right)
{
	return { left.x * right, left.y * right };
}

