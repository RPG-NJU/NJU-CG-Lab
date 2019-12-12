#include "DrawingArea.h"

using std::atoi;
using std::stoi;
using std::stod;

void DrawingArea::runCommand()
{
	/*bool flag = dirExist("./x64/");
	if (flag == true)
		qDebug() << "Yes" << endl;
	else
		qDebug() << "No" << endl;*/
		// 上面这段代码用来测试
		/*newDir("Data/data");*/
		//for (const auto &command : commands) // 对每一条指令进行解析
	for (int line_i(0); line_i < commands.size(); ++line_i)
	{
		vector<string> command = commands[line_i];

		if (command.size() < 1)
			continue;

		QString output_info("");
		for (const auto& word : command)
		{
			output_info = output_info + " " + QString::fromStdString(word);
		}
		qDebug() << "run command: " << output_info;

		if (command[0] == "resetCanvas") // 重置画布，需要清空画布并且设置大小
		{
			const int width(std::stoi(command[1])), height(std::stoi(command[2]));
			clearPaper(false);
			setPaperSize(width, height);
		}

		else if (command[0] == "saveCanvas") // 保存画布
		{
			string file_name(command[1] + ".bmp");
			paper.save(QString::fromStdString(output_path + file_name));
		}

		else if (command[0] == "setColor") // 设置画笔颜色
		{
			QRgb c = qRgb(std::stoi(command[1]), std::stoi(command[2]), std::stoi(command[3]));
			QColor color(c);
			setPenColor(color);
		}

		else if (command[0] == "drawLine") // 画直线
		{
			const int id(stoi(command[1])), x1(stoi(command[2])), y1(stoi(command[3])), x2(stoi(command[4])), y2(stoi(command[5]));

			vector<MyPoint> points;
			QPainter painter(&paper); // 使用QImage初始化QPainter，需要使用指针
			painter.setPen(pen);

			points = command[6] == "DDA" ? createStraightLineByDDA(x1, y1, x2, y2) : createStraightLineByBresenham(x1, y1, x2, y2);

			for (const auto& point : points)
			{
				painter.drawPoint(point.x, point.y);
			}

			appendStraightLinePrimitive(x1, y1, x2, y2, id, pen, command[6] == "DDA" ? StraightLineAlgorithm::DDA : StraightLineAlgorithm::Bresenham);

			qDebug() << "绘制了:";
			primitives[primitives.size() - 1]->print();

			this->update();
		}

		else if (command[0] == "drawEllipse") // 画椭圆
		{
			const int id(stoi(command[1])), x0(stoi(command[2])), y0(stoi(command[3])), rx(stoi(command[4])), ry(stoi(command[5]));

			vector<MyPoint> points;
			QPainter painter(&paper); // 使用QImage初始化QPainter，需要使用指针
			painter.setPen(pen);

			points = createEllipse(x0, y0, rx, ry);

			for (const auto& point : points)
			{
				painter.drawPoint(point.x, point.y);
			}

			appendEllipsePrimitive(x0, y0, rx, ry, id, pen);

			qDebug() << "绘制了:";
			primitives[primitives.size() - 1]->print();

			this->update();
		}

		else if (command[0] == "drawPolygon") // 画多边形
		{
			/*
			 * drawPolygon id n algorithm
			 * x1 y1 x2 y2 … xn yn
			 */
			vector<MyPoint> points;
			QPainter painter(&paper); // 使用QImage初始化QPainter，需要使用指针
			painter.setPen(pen);

			const int id(stoi(command[1])), n(stoi(command[2]));
			StraightLineAlgorithm algorithm_in_use(command[3] == "DDA" ? StraightLineAlgorithm::DDA : StraightLineAlgorithm::Bresenham);
			vector<MyPoint> vertices_in_command;

			++line_i; // 多边形的特殊之处，需要遍历下一行的数据！
			command = commands[line_i];

			for (int i(0); i < command.size(); i = i + 2)
			{
				int x(stoi(command[i])), y(stoi(command[i + 1]));
				vertices_in_command.push_back({ x, y });
			}

			points = createPolygon(vertices_in_command, algorithm_in_use);
			for (const auto& point : points)
			{
				painter.drawPoint(point.x, point.y);
			}

			appendPolygonPrimitive(vertices_in_command, id, pen, algorithm_in_use);

			qDebug() << "绘制了:";
			primitives[primitives.size() - 1]->print();

			this->update();
		}

		else if (command[0] == "drawCurve")
		{
			vector<MyPoint> points;
			QPainter painter(&paper); // 用于初始化
			painter.setPen(pen); // 设置画笔

			const int id(stoi(command[1])), n(stoi(command[2]));
			CurveAlgorithm algorithm_in_use(command[3] == "Bezier" ? CurveAlgorithm::Bezier : CurveAlgorithm::B_spline);
			vector<MyPoint> fixed_points_in_command; // 用于存储，所有的指令中的锚点

			++line_i; // 曲线和多边形一样的地方，需要遍历下一行的数据
			command = commands[line_i];

			for (int i(0); i < command.size(); i = i + 2)
			{
				int x(stoi(command[i])), y(stoi(command[i + 1]));
				fixed_points_in_command.push_back({ x, y });
			}

			points = createCurve(fixed_points_in_command, algorithm_in_use);
			for (const auto& point : points)
			{
				painter.drawPoint(point.x, point.y);
			}

			// 缺少了一个图元的压入
			qDebug() << "here" << endl;

			this->update();
		}

		else if (command[0] == "translate") // 图元的平行变换
		{
			/*
			 * translate id dx dy
			 */
			const int id(stoi(command[1])), dx(stoi(command[2])), dy(stoi(command[3]));
			for (auto& primitive : primitives)
			{
				if (primitive->id() == id) // 如果当前图元的id等于所输入的id
				{
					primitive->translate(dx, dy);
					primitive->print();
					qDebug() << "平移: x,y =" << dx << "," << dy;
					break; // 保证了id的唯一性，当然如果是唯一的，这句话也没有什么必要，只是作为一个体现
				}
			}

			clearPaper(true);
			drawAll();
		}

		else if (command[0] == "rotate") // 图元的旋转
		{
			/*
			 * rotate id x y r
			 */
			const int id(stoi(command[1])), x(stoi(command[2])), y(stoi(command[3])), r(stoi(command[4]));
			for (auto& primitive : primitives)
			{
				if (primitive->id() == id) // 如果当前图元的id等于所输入的id
				{
					primitive->rotate(x, y, r);
					primitive->print();
					qDebug() << "旋转: x,y =" << x << "," << y << "  角度 r =" << r;
					break; // 保证了id的唯一性，当然如果是唯一的，这句话也没有什么必要，只是作为一个体现
				}
			}

			clearPaper(true);
			drawAll();
		}

		else if (command[0] == "scale") // 此时是缩放操作
		{
			/*
			 * scale id x y s
			 */
			 // 在我们的参数中只有一个s，所以是一致缩放
			const int id(stoi(command[1])), x(stoi(command[2])), y(stoi(command[3]));
			const double s(stod(command[4])); // 缩放倍数为浮点数

			for (auto& primitive : primitives)
			{
				if (primitive->id() == id) // 如果当前图元的id等于所输入的id
				{
					primitive->scale(x, y, s);
					primitive->print();
					qDebug() << "缩放: x,y =" << x << "," << y << "  倍数 s =" << s;
					break; // 保证了id的唯一性，当然如果是唯一的，这句话也没有什么必要，只是作为一个体现
				}
			}

			clearPaper(true);
			drawAll();
		}

		else if (command[0] == "clip") // 此时是裁剪操作
		{
			/*
			 * clip id x1 y1 x2 y2 algorithm
			 */
			const int id(stoi(command[1])), x1(stoi(command[2])), y1(stoi(command[3])), x2(stoi(command[4])), y2(stoi(command[5]));
			const ClipAlgorithm algorithm_in_use(command[6] == "Cohen-Sutherland" ? ClipAlgorithm::Cohen_Sutherland : ClipAlgorithm::Liang_Barsky);

			for (auto primitive = primitives.begin(); primitive < primitives.end(); ++primitive)
			{
				if ((*primitive)->id() == id) // 这里不同于之前使用的范围遍历，使用的是迭代器的方法遍历
				{
					bool flag = (*primitive)->clip(x1, y1, x2, y2, algorithm_in_use);
					(*primitive)->print();
					qDebug() << "裁剪: x1, y1 =" << x1 << "," << y1 << "  x2, y2 =" << x2 << "," << y2;
					if (!flag) // 此时需要删除图元
					{
						primitives.erase(primitive); // 删除
					}
					break; // 保证了id的唯一性，当然如果是唯一的，这句话也没有什么必要，只是作为一个体现
				}
			}

			clearPaper(true);
			drawAll();
		}

		else // undefined command
		{
			// 这个时候时没有定义的指令，无法被解析
			qDebug() << "WARNING：该条指令格式未定义" << endl;
		}
	}

	/*for (auto x : primitives)
	{
		x->print();
	}*/
	this->update();
	return;
}
