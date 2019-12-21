#include "DrawingArea.h"


vector<MyPoint> DrawingArea::createCurve(const vector<MyPoint>& fixed_points, CurveAlgorithm algorithm)
{
	switch (algorithm)
	{
	case CurveAlgorithm::Bezier: return createCurveByBezier(fixed_points);
	case CurveAlgorithm::B_spline: return createCurveByB_spline(fixed_points);

	default: vector<MyPoint> points; return points; // 作为默认情况
	}
}


vector<MyPoint> DrawingArea::createCurveByBezier(const vector<MyPoint>& fixed_points)
{
	vector<MyPoint> points; // 用于存储所有需要画图的点

	int r(fixed_points.size() - 1); // 用于表示需要迭代的次数，也是贝塞尔曲线的次数

	for (double u(0); u <= 1; u = u + BEZIER_DELTA / fixed_points.size())
	{
		MyPoint_double point = Bezier_P(fixed_points, 0, r, u);
		//points.push_back({ (int)point.x, (int)point.y });
		if (points.empty()) // 如果当时点位为空，则必须需要压入一个点位
		{
			points.push_back({ static_cast<int>(round(point.x)), static_cast<int>(round(point.y)) });
		} // 否则
		else if (point != points[points.size() - 1]) // 只有当这个点和之前的结尾点不一样的时候，才考虑压入
			points.push_back({ static_cast<int>(round(point.x)), static_cast<int>(round(point.y)) });
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


vector<MyPoint> DrawingArea::createCurveByB_spline(const vector<MyPoint>& fixed_points)
{
	// 在我们的实验中，只考虑三次均匀B样条曲线
	vector<MyPoint> points; // 用于存储所有需要画图的点

	if (fixed_points.size() > B_SPLINE_K) // 对于三次曲线，如果小于四个点，则不能进行运算，所以就不返回有效点
	{
		for (int i(0); i + B_SPLINE_K < fixed_points.size(); ++i) // 每四个点作为一组
		{
			vector<MyPoint> p_points;
			p_points.push_back(fixed_points[i]);
			p_points.push_back(fixed_points[i + 1]);
			p_points.push_back(fixed_points[i + 2]);
			p_points.push_back(fixed_points[i + 3]);
			for (double u(0.0); u <= 1; u = u + B_SPLINE_DELTA)
			{
				const MyPoint_double point = B_spline_3(p_points, u);
				if (points.empty()) // 如果当前点的列表为空，则必须需要压入一个点
				{
					points.push_back({ static_cast<int>(round(point.x)), static_cast<int>(round(point.y)) });
				} // 否则
				else if (point != points[points.size() - 1]) // 只有与上一个点不重复的时候才会压入一个点
					points.push_back({ static_cast<int>(round(point.x)), static_cast<int>(round(point.y)) });
			}
		}
	}


	return points;
}

MyPoint_double DrawingArea::B_spline_3(const vector<MyPoint> p_points, double u)
{
	if (p_points.size() != 4)
		return { 0, 0 };
	double b0, b1, b2, b3;
	b0 = 1.0 / 6.0 * (1 - u) * (1 - u) * (1 - u);
	b1 = 1.0 / 6.0 * (3 * u * u * u - 6 * u * u + 4);
	b2 = 1.0 / 6.0 * (-3 * u * u * u + 3 * u * u + 3 * u + 1);
	b3 = 1.0 / 6.0 * u * u * u;

	MyPoint_double point;
	point = p_points[0] * b0 + p_points[1] * b1 + p_points[2] * b2 + p_points[3] * b3;
	return point;
}

