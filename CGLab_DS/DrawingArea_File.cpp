#include "DrawingArea.h"


// 文件部分
bool DrawingArea::openCommandFile(QString file_path)
{
	QFile command_file(file_path);
	if (!command_file.open(QIODevice::ReadOnly | QIODevice::Text)) // 如果文件打开失败
	{
		QMessageBox::warning(this, tr("Wrong to Read File"), tr("Can't open file:\n%1").arg(file_path));
		return false; // 文件读取失败
	}

	
	// 下面的操作都基于，文件打开成功的情况
	QTextStream command_in(&command_file);

	//vector<string> command_lines;
	/*vector<vector<string> > commands;*/

	while (!command_in.atEnd())
	{
		//command_lines.push_back(command_in.readLine().toStdString());
		stringstream command_line;
		string word;
		vector<string> command;
		command_line << command_in.readLine().toStdString();
		while (command_line)
		{
			//string word;
			word.clear();
			command_line >> word;
			if (!word.empty()) // 否则可能会传入空的string
				command.push_back(word);
		}
		commands.push_back(command);
		command.clear();
	}

#ifdef PRINT_FILE_OP
	/*for (auto line : command_lines)
	{
		qDebug() << QString::fromStdString(line) << endl;
	}*/
	for (const auto a_command : commands)
	{
		QString output;
		for (const auto command_word : a_command)
		{
			output = output + "[" + QString::fromStdString(command_word) + "] ";
		}
		qDebug() << output;
	}
#endif

	command_file.close(); // 关闭文件，数据已经完全读取

	return true;
}

bool DrawingArea::dirExist(const string dir_path)
{
	int ftyp = _access(dir_path.c_str(), 0);
	if (ftyp == 0)
		return true; // 文件夹存在
	else
		return false; // 文件夹不存在
}

//bool DrawingArea::newDir(const string dir_path)
//{
//	string command;
//	command = "mkdir -p " + dir_path;
//	system(command.c_str());
//	return true;
//}


string DrawingArea::formatDirPath(string dir_path)
{
	if (!dirExist(dir_path)) // 此时应该是判断不存在的情况做出相应的处理，现在的处理只是简单的更改为当前目录
	{
		return "./";
	}

	if (dir_path[dir_path.length() - 1] != '\\' && dir_path[dir_path.length() - 1] != '/')
	{
		dir_path += "/";
	}

	return dir_path;
}
