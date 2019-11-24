#include "DrawingArea.h"

using std::atoi;
using std::stoi;

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
		for (const auto &word : command)
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

			for (const auto &point : points)
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
			QString output_info("");
			for (const auto& word : command)
			{
				output_info = output_info + " " + QString::fromStdString(word);
			}
			qDebug() << "polygon data: " << output_info;
			
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

		else if (command[0] == "translate") // 图元的平行变换
		{
			/*
			 * translate id dx dy
			 */
			const int id(stoi(command[1])), dx(stoi(command[2])), dy(stoi(command[3]));
			for (auto &primitive : primitives)
			{
				if (primitive->id() == id) // 如果当前图元的id等于所输入的id
				{
					primitive->translate(dx, dy);
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
