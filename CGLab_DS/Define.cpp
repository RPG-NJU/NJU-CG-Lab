#include "Define.h"
#include <cmath>


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

bool operator==(const MyPoint& left, const MyPoint& right)
{
	if (left.x == right.x && left.y == right.y)
		return true;
	else
		return false;
}

bool operator!=(const MyPoint& left, const MyPoint& right)
{
	return !(left == right);
}

bool operator==(const MyPoint_double& left, const MyPoint& right)
{
	if (static_cast<int>(round(left.x)) == right.x && static_cast<int>(round(left.y)) == right.y)
		return true;
	else
		return false;
}

bool operator!=(const MyPoint_double& left, const MyPoint& right)
{
	return !(left == right);
}




