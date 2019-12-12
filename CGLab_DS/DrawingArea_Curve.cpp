#include "DrawingArea.h"


vector<MyPoint> DrawingArea::createCurve(const vector<MyPoint>& fixed_points, CurveAlgorithm algorithm)
{
	switch (algorithm)
	{
	case CurveAlgorithm::Bezier: return createCurveByBezier(fixed_points);

	default: vector<MyPoint> points; return points; // 作为默认情况
	}
}


vector<MyPoint> DrawingArea::createCurveByBezier(const vector<MyPoint>& fixed_points)
{
	vector<MyPoint> points; // 用于存储所有需要画图的点

	int r(fixed_points.size() - 1); // 用于表示需要迭代的次数，也是贝塞尔曲线的次数

	for (double u(0); u <= 1; u = u + BEZIER_DELTA)
	{
		MyPoint_double point = Bezier_P(fixed_points, 0, r, u);
		points.push_back({ (int)point.x, (int)point.y });
	}

	return points;
}

MyPoint_double DrawingArea::Bezier_P(const vector<MyPoint>& fixed_points, int i, int r, double u)
{
	if (r == 0)
	{
		return { static_cast<double>(fixed_points[i].x) , static_cast<double>(fixed_points[i].y) };
	}

	MyPoint_double p_i, p_iplus1;
	p_i = Bezier_P(fixed_points, i, r - 1, u);
	p_iplus1 = Bezier_P(fixed_points, i + 1, r - 1, u);

	return (1 - u) * p_i + u * p_iplus1;
}


