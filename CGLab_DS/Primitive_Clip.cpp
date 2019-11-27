#include "DrawingArea.h"

//#include <cmath>

using std::max;
using std::min;

bool StraightLine::clip(const int x1, const int y1, const int x2, const int y2, ClipAlgorithm algorithm)
{
	switch (algorithm)
	{
	case ClipAlgorithm::Cohen_Sutherland: return clipByCohen_Sutherland(x1, y1, x2, y2);
	case ClipAlgorithm::Liang_Barsky: return clipByLiang_Barsky(x1, y1, x2, y2);
	default: return true;
	}
}

bool StraightLine::clipByCohen_Sutherland(const int x1, const int y1, const int x2, const int y2)
{
	/*
	 *    X     X     X     X
	 *   上    下    右    左
	 */
	const int left(x1 < x2 ? x1 : x2), right(x1 > x2 ? x1 : x2), up(y1 > y2 ? y1 : y2), down(y1 < y2 ? y1 : y2); // 规定了四个方向的边界
	int begin_flag(0), end_flag(0);
	
	if (begin_x < left)
		begin_flag += 1;
	else if (begin_x > right)
		begin_flag += 2;
	if (begin_y < down)
		begin_flag += 4;
	else if (begin_y > up)
		begin_flag += 8;

	if (end_x < left)
		end_flag += 1;
	else if (end_x > right)
		end_flag += 2;
	if (end_y < down)
		end_flag += 4;
	else if (end_y > up)
		end_flag += 8;

	if ((begin_flag | end_flag) == 0) // 此时线段完全落在裁剪窗口内部，不需要进行操作，直接返回即可
		return true;
	else if ((begin_flag & end_flag) != 0) // 此时线段完全落在裁剪窗口外部，返回删除标志则可
		return false;

	// 剩下的就是需要裁剪的一般情况
	// 计算交点的顺序为，左，右，下，上

	const double m((static_cast<double>(begin_y) - static_cast<double>(end_y)) / (static_cast<double>(begin_x) - static_cast<double>(end_x))); // 计算得到的斜率
	
	// 左
	double y_left(0.0);
	y_left = begin_y + m * (left - begin_x);
	if (begin_x <= left && end_x <= left)
	{
		return false;
	}
	else if (begin_x >= left && end_x >= left)
	{
		;
	}
	else if (begin_x < left && end_x > left)
	{
		begin_x = left;
		begin_y = static_cast<int>(y_left);
	}
	else if (begin_x > left && end_x < left)
	{
		end_x = left;
		end_y = static_cast<int>(y_left);
	}

	// 右
	double y_right(0.0);
	y_right = begin_y + m * (right - begin_x);
	if (begin_x >= right && end_x >= right)
	{
		return false;
	}
	else if (begin_x <= right && end_x <= right)
	{
		;
	}
	else if (begin_x > right && end_x < right)
	{
		begin_x = right;
		begin_y = static_cast<int>(y_right);
	}
	else if (begin_x < right && end_x > right)
	{
		end_x = right;
		end_y = static_cast<int>(y_right);
	}

	// 下
	double x_down(0.0);
	x_down = begin_x + (1 / m) * (down - begin_y);
	if (begin_y <= down && end_y <= down)
	{
		return false;
	}
	else if (begin_y >= down && end_y >= down)
	{
		;
	}
	else if (begin_y < down && end_y > down)
	{
		begin_y = down;
		begin_x = static_cast<int>(x_down);
	}
	else if (begin_y > down && end_y < down)
	{
		end_y = down;
		end_x = static_cast<int>(x_down);
	}

	// 上
	double x_up(0.0);
	x_up = begin_x + (1 / m) * (up - begin_y);
	if (begin_y >= up && end_y >= up)
	{
		return false;
	}
	else if (begin_y <= up && end_y <= up)
	{
		;
	}
	else if (begin_y > up && end_y < up)
	{
		begin_y = up;
		begin_x = static_cast<int>(x_up);
	}
	else if (begin_y < up && end_y > up)
	{
		end_y = up;
		end_x = static_cast<int>(x_up);
	}
	
	return true;
}

bool StraightLine::clipByLiang_Barsky(const int x1, const int y1, const int x2, const int y2)
{
	/*
	 * 同样的，k=1，2，3，4分别对应于左，右，下，上
	 */
	int p[4], q[4]; // 用于记录p/q数组
	const int dx(end_x - begin_x), dy(end_y - begin_y);
	const int left(x1 < x2 ? x1 : x2), right(x1 > x2 ? x1 : x2), up(y1 > y2 ? y1 : y2), down(y1 < y2 ? y1 : y2); // 规定了四个方向的边界
	
	p[0] = -dx;
	p[1] = dx;
	p[2] = -dy;
	p[3] = dy;

	q[0] = begin_x - left;
	q[1] = right - begin_x;
	q[2] = begin_y - down;
	q[3] = up - begin_y;
	// 初始化

	double r(0.0), u1(0.0), u2(1.0);

	for (int i(0); i < 4; ++i)
	{
		if (p[i] == 0)
		{
			if (q[i] < 0)
				return false;
			else
				continue;
		}

		// 下面是P不等于0的情况

		r = static_cast<double>(q[i]) / static_cast<double>(p[i]);

		if (p[i] < 0) // 用于更新u1
		{
			u1 = max(u1, r);
			if (u1 > u2)
				return false;
		}

		else // 用于更新u2
		{
			u2 = min(u2, r);
			if (u1 > u2)
				return false;
		}

	}

	const int temp_begin_x(begin_x), temp_begin_y(begin_y), temp_end_x(end_x), temp_end_y(end_y);
	begin_x = static_cast<int>(temp_begin_x + u1 * dx);
	begin_y = static_cast<int>(temp_begin_y + u1 * dy);
	end_x = static_cast<int>(temp_begin_x + u2 * dx);
	end_y = static_cast<int>(temp_begin_y + u2 * dy);
	
	return true;
}







bool Ellipse::clip(const int x1, const int y1, const int x2, const int y2, ClipAlgorithm algorithm)
{
	return true;
}

bool Polygon::clip(const int x1, const int y1, const int x2, const int y2, ClipAlgorithm algorithm)
{
	return true;
}

bool Ellipse::clipByCohen_Sutherland(const int x1, const int y1, const int x2, const int y2)
{
	return true;
}

bool Ellipse::clipByLiang_Barsky(const int x1, const int y1, const int x2, const int y2)
{
	return true;
}

bool Polygon::clipByCohen_Sutherland(const int x1, const int y1, const int x2, const int y2)
{
	return true;
}

bool Polygon::clipByLiang_Barsky(const int x1, const int y1, const int x2, const int y2)
{
	return true;
}
