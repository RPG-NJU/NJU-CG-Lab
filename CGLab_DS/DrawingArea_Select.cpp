#include "DrawingArea.h"
#include <algorithm>

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
	if (isTranslate)
	{
		mouseTranslate(thisPaper);
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

	this->update();
}

