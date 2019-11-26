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
