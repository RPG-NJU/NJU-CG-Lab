#include "DrawingArea.h"
#include <algorithm>
#include <cmath>

using std::swap;

void DrawingArea::selectPrimitive(QPoint begin, QPoint end)
{
	int xmin(begin.x()), ymin(begin.y()), xmax(end.x()), ymax(end.y());
	if (xmin > xmax)
		swap(xmin, xmax);
	if (ymin > ymax)
		swap(ymin, ymax);
	// 上面规范化边界
	selected_primitives_id.clear();
	for (const auto &primitive : primitives)
	{
		vector<MyPoint> points;
		switch (primitive->_type())
		{
		case PrimitiveType::StraightLine:
		{
			StraightLine* p_straightline = dynamic_cast<StraightLine*>(primitive);
			StraightLineAlgorithm algorithm = p_straightline->_algorithm();
			points = createStraightLine(p_straightline->x1(), p_straightline->y1(), p_straightline->x2(), p_straightline->y2(), p_straightline->_algorithm());
		}break;
		case PrimitiveType::Ellipse:
		{
			Ellipse* p_ellipse = dynamic_cast<Ellipse*>(primitive);
			points = createEllipse(p_ellipse->_x0(), p_ellipse->_y0(), p_ellipse->_rx(), p_ellipse->_ry());
		}break;
		case PrimitiveType::Polygon:
		{
			Polygon* p_polygon = dynamic_cast<Polygon*>(primitive);
			points = createPolygon(p_polygon->_vertices(), p_polygon->_algorithm());
		}break;
		case PrimitiveType::Curve:
		{
			Curve* p_curve = dynamic_cast<Curve*>(primitive);
			points = createCurve(p_curve->_fixed_points(), p_curve->_algorithm());
		}break;
		default: break; // 此时无法进行任何的操作
		}
		bool flag(true);
		for (const auto &point : points)
		{
			if (point.x > xmax || point.x < xmin || point.y > ymax || point.y < ymin)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			selected_primitives_id.push_back(primitive->id());
		}
	}

	qDebug() << "选择了图元：";
	for (const auto id : selected_primitives_id)
		qDebug() << id;
	qDebug() << endl;

	return;
}


void DrawingArea::selectCenter(QPoint begin, QPoint end)
{
	center_x = (begin.x() + end.x()) / 2;
	center_y = (begin.y() + end.y()) / 2;
	return;
}


void DrawingArea::mouseTransform(QImage& thisPaper)
{
	for (auto &p : primitives)
	{
		delete p;
	}
	primitives.clear();

	for (const auto& p : save_primitives)
	{
		switch (p->_type())
		{
		case PrimitiveType::StraightLine: primitives.push_back(new StraightLine(*dynamic_cast<StraightLine*>(p))); break;
		case PrimitiveType::Ellipse: primitives.push_back(new Ellipse(*dynamic_cast<Ellipse*>(p))); break;
		case PrimitiveType::Polygon: primitives.push_back(new Polygon(*dynamic_cast<Polygon*>(p))); break;
		case PrimitiveType::Curve: primitives.push_back(new Curve(*dynamic_cast<Curve*>(p))); break;
		default: break;
		}
	}
	
	if (isTranslate)
	{
		mouseTranslate(thisPaper);
	}
	else if (isRotate)
	{
		mouseRotate(thisPaper);
	}
}

void DrawingArea::mouseTranslate(QImage& thisPaper)
{
	const int dx(end_point.x() - begin_point.x()), dy(end_point.y() - begin_point.y());
	for (const auto id : selected_primitives_id)
	{
		for (auto &p : primitives)
		{
			if (p->id() == id)
			{
				p->translate(dx, dy);
			}
		}
	}
	center_x += dx;
	center_y += dy;
	
	this->update();
}

void DrawingArea::mouseRotate(QImage& thisPaper)
{
	/*
	 * 在旋转中有许多不可以忽视的误差，所以需要对它进行一定的重构
	 */
	double a, b, c;
	a = sqrt((begin_point.x() - center_x) * (begin_point.x() - center_x) + (begin_point.y() - center_y) * (begin_point.y() - center_y));
	b = sqrt((end_point.x() - center_x) * (end_point.x() - center_x) + (end_point.y() - center_y) * (end_point.y() - center_y));
	c = sqrt((begin_point.x() - end_point.x()) * (begin_point.x() - end_point.x()) + (begin_point.y() - end_point.y()) * (begin_point.y() - end_point.y()));

	double cos = (a * a + b * b - c * c) / (2 * a * b);
	int r = 180 * acos(cos) / PI;

	// 这里还需要考虑角度的正负问题
    double y_standard = ((double)end_point.x() - begin_point.x()) / ((double)center_x - begin_point.x()) * ((double)center_y - begin_point.y()) + begin_point.y();
	if (begin_point.x() < center_x)
	{
		if (end_point.y() > y_standard)
			r = -r;
	}
	else
	{
		if (end_point.y() < y_standard)
			r = -r;
	}

	for (const auto id : selected_primitives_id)
	{
		for (auto& p : primitives)
		{
			if (p->id() == id)
			{
				p->rotate(center_x, center_y, r);
			}
		}
	}

	this->update();
}

void DrawingArea::beginTransform()
{
	for (auto& p : save_primitives)
		delete p;
	save_primitives.clear();

	for (const auto& p : primitives)
	{
		switch(p->_type())
		{
		case PrimitiveType::StraightLine: save_primitives.push_back(new StraightLine(*dynamic_cast<StraightLine*>(p))); break;
		case PrimitiveType::Ellipse: save_primitives.push_back(new Ellipse(*dynamic_cast<Ellipse*>(p))); break;
		case PrimitiveType::Polygon: save_primitives.push_back(new Polygon(*dynamic_cast<Polygon*>(p))); break;
		case PrimitiveType::Curve: save_primitives.push_back(new Curve(*dynamic_cast<Curve*>(p))); break;
		default: break;
		}
	}
	qDebug() << save_primitives.size();

	return;
}

void DrawingArea::endTransform()
{
	return;
}

