#include "DrawingArea.h"


vector<MyPoint> DrawingArea::createPolygon(const vector<MyPoint>& vertices, StraightLineAlgorithm algorithm)
{
	vector<MyPoint> points;
	for (int i(0); i < vertices.size() - 1; ++i)
	{
		vector<MyPoint> temp_points = createStraightLine(vertices[i].x, vertices[i].y, vertices[i + 1].x, vertices[i + 1].y, algorithm); // 这里使用新的统一调用接口
		points.insert(points.end(), temp_points.begin(), temp_points.end());
	}
	vector<MyPoint> temp_points = createStraightLine(vertices[vertices.size() - 1].x, vertices[vertices.size() - 1].y, vertices[0].x, vertices[0].y, algorithm); // 首尾相连
	points.insert(points.end(), temp_points.begin(), temp_points.end());
	//qDebug() << points.size();
	return points;
}
