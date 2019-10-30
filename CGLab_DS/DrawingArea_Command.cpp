#include "DrawingArea.h"

void DrawingArea::runCommand()
{
	for (const auto &command : commands) // 对每一条指令进行解析
	{
		if (command.size() < 1)
			continue;
		if (command[0] == "resetCanvas") // 设置画布大小
		{
			int width(std::stoi(command[1])), height(std::stoi(command[2]));
			setPaperSize(width, height);
		}

		else if (command[0] == "saveCanvas") // 保存画布
		{
			string file_name(command[1] + ".bmp");
			paper.save(QString::fromStdString(file_name));
		}

		else if (command[0] == "setColor") // 设置画笔颜色
		{
			QRgb c = qRgb(std::stoi(command[1]), std::stoi(command[2]), std::stoi(command[3]));
			QColor color(c);
			setPenColor(color);
		}
		
	}
	
	return;
}
