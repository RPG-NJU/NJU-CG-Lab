#include "DrawingArea.h"

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
