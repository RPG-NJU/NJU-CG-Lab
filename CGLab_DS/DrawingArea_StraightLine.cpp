#include "DrawingArea.h"

vector<MyPoint> DrawingArea::createStraightLine(int x1, int y1, int x2, int y2, StraightLineAlgorithm algorithm)
{
	switch (algorithm)
	{
	case StraightLineAlgorithm::None: return createStraightLineByNone(x1, x2, y1, y2);
	case StraightLineAlgorithm::DDA: return createStraightLineByDDA(x1, y1, x2, y2);
	case StraightLineAlgorithm::Bresenham: return createStraightLineByBresenham(x1, y1, x2, y2);
	default: return createStraightLineByBresenham(x1, y1, x2, y2);
	}
}


void DrawingArea::drawStraightLine(QImage& thisPaper, const QPoint line_begin, const QPoint line_end, const StraightLineAlgorithm algorithm)
{
	int x1 = line_begin.x(), x2 = line_end.x();
	int y1 = line_begin.y(), y2 = line_end.y();
	/*
	 * 这里重新存储了直线的起始位置和终止位置
	 * 没有绝对性的必要，只是为了简化变量的名字
	 */

	vector<MyPoint> points;
	QPainter painter(&thisPaper); // 使用QImage初始化QPainter，需要使用指针
	painter.setPen(pen);

	switch (algorithm)
	{
	case StraightLineAlgorithm::DDA:
	{
		points = createStraightLineByDDA(x1, y1, x2, y2);
		break;
	}
	case StraightLineAlgorithm::Bresenham:
	{
		points = createStraightLineByBresenham(x1, y1, x2, y2);
		break;
	}
	case StraightLineAlgorithm::None:
	{
		points = createStraightLineByNone(x1, x2, y1, y2);
		break;
	}
	default:
	{
		qDebug() << "!!! < 未匹配当前算法 >" << endl;
		break;
	}
	}

	for (int i(0); i < points.size(); ++i)
	{
		painter.drawPoint(points[i].x, points[i].y);
	}

	// 在完成了绘图之后，还需要将图元信息存储


	this->update(); // 更新窗体，可以使得QWidget调用paintEvent函数，绘制窗体
	return;
}

vector<MyPoint> DrawingArea::createStraightLineByNone(int x1, int x2, int y1, int y2)
{
	vector<MyPoint> points;

	double k(static_cast<double>(static_cast<double>(y2) - static_cast<double>(y1)) / 
		static_cast<double>(static_cast<double>(x2) - static_cast<double>(x1)));

	if (abs(k) < 1)
	{
		if (x2 < x1)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		const double s(static_cast<double>(x2) - static_cast<double>(x1));
		for (int i(0); i <= x2 - x1; ++i)
		{
			points.push_back({ x1 + i, y1 + static_cast<int>(round(k * i)) });
		}
	}
	else
	{
		k = 1 / k; // 目前这么写，有可能导致一定的误差
		if (y2 < y1)
		{
			swap(y1, y2);
			swap(x1, x2);
			//k = -k;
		}
		//const double d(x2 - x1);
		const double s(y2 - y1);
		for (int i(0); i <= y2 - y1; ++i)
		{
			points.push_back({ x1 + static_cast<int>(round(k * i)), y1 + i });
		}
	}

	return points;
}

vector<MyPoint> DrawingArea::createStraightLineByDDA(int x1, int y1, int x2, int y2)
{
	vector<MyPoint> points;

	if (x2 - x1 == 0) // 如果是没有斜率的直线
	{
		if (y2 < y1)
		{
			swap(y1, y2);
		}

		for (int y(y1); y <= y2; ++y)
		{
			points.push_back({ x1, y });
		}
		return points;
	}

	// 下面都是斜率存在的情况
	double m(static_cast<double>(static_cast<double>(y2) - static_cast<double>(y1)) / 
		static_cast<double>(static_cast<double>(x2) - static_cast<double>(x1))); // 计算增量
	
	if (abs(m) <= 1)
	{
		if (x2 < x1) // 都要替换为增量为正的情况
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		double y = y1;
		for (int x(x1); x <= x2; ++x)
		{
			y += m;
			points.push_back({ x, static_cast<int>(floor(y))});
		}
	}
	else
	{
		m = 1 / m;
		if (y2 < y1)
		{
			swap(y1, y2);
			swap(x1, x2);
		}
		double x = x1;
		for (int y(y1); y <= y2; ++y)
		{
			x += m;
			points.push_back({ static_cast<int>(floor(x)), y});
		}
	}

	return points;
}


vector<MyPoint> DrawingArea::createStraightLineByBresenham(int x1, int y1, int x2, int y2)
{
	vector<MyPoint> points;

	if (x2 - x1 == 0) // 如果是没有斜率的直线
	{
		if (y2 < y1)
		{
			swap(y1, y2);
		}

		for (int y(y1); y <= y2; ++y)
		{
			points.push_back({ x1, y });
		}
		return points;
	}

	// 下面是斜率存在的直线
	const double k(static_cast<double>(static_cast<double>(y2) - static_cast<double>(y1)) /
		static_cast<double>(static_cast<double>(x2) - static_cast<double>(x1))); // 计算斜率

	const int dx(abs(x2 - x1)), dy(abs(y2 - y1));
	
	if (abs(k) <= 1)
	{
		if (k >= 0) // 都要替换为增量为正的情况
		{
			if (x2 < x1)
			{
				swap(x1, x2);
				swap(y1, y2);
			}

			int x(x1), y(y1);
			int p(2 * dy - dx);

			for (; x <= x2; ++x)
			{
				points.push_back({ x, y });
				if (p >= 0)
				{
					++y;
					p += 2 * (dy - dx);
				}
				else
				{
					p += 2 * dy;
				}
			}
		}

		else
		{
			if (x1 < x2)
			{
				swap(x1, x2);
				swap(y1, y2);
			}

			int x(x1), y(y1);
			int p(2 * dy - dx);

			for (; x >= x2; --x)
			{
				points.push_back({ x, y });
				if (p >= 0)
				{
					++y;
					p += 2 * (dy - dx);
				}
				else
				{
					p += 2 * dy;
				}
			}
		}
	}
	else
	{

		if (k >= 0) // 都要替换为增量为正的情况
		{
			if (y2 < y1)
			{
				swap(x1, x2);
				swap(y1, y2);
			}

			int x(x1), y(y1);
			int p(2 * dx - dy);

			for (; y <= y2; ++y)
			{
				points.push_back({ x, y });
				if (p >= 0)
				{
					++x;
					p += 2 * (dx - dy);
				}
				else
				{
					p += 2 * dx;
				}
			}
		}

		else
		{
			if (y1 < y2)
			{
				swap(x1, x2);
				swap(y1, y2);
			}

			int x(x1), y(y1);
			int p(2 * dx - dy);

			for (; y >= y2; --y)
			{
				points.push_back({ x, y });
				if (p >= 0)
				{
					++x;
					p += 2 * (dx - dy);
				}
				else
				{
					p += 2 * dx;
				}
			}
		}
	}

	

	return points;
}
