#include "DrawingArea.h"


// 文件部分
bool DrawingArea::openCommandFile(QString file_path)
{
	//QFile file(file_path);
	//if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
	//	QMessageBox::warning(this, tr("Read File"),
	//		tr("Cannot open file:\n%1").arg(file_path));
	//	return;
	//}
	//QTextStream in(&file);
	//
	//qDebug() << in.readLine() << endl;
	////QTextEdit *textEdit = new QTextEdit(this);
	//
	////show_command_text->setText(in.readAll());
	////while (!in.atEnd())
	////{
	//QTextEdit* show_command_text = new QTextEdit(this);
	//	show_command_text->append(in.readLine());
	////}
	//qDebug() << "new edit" << endl;
	//file.close();
	QFile command_file(file_path);
	if (!command_file.open(QIODevice::ReadOnly | QIODevice::Text)) // 如果文件打开失败
	{
		QMessageBox::warning(this, tr("Wrong to Read File"), tr("Can't open file:\n%1").arg(file_path));
		return false; // 文件读取失败
	}

	
	// 下面的操作都基于，文件打开成功的情况
	QTextStream command_in(&command_file);

	vector<string> command_lines;

	while (!command_in.atEnd())
	{
		command_lines.push_back(command_in.readLine().toStdString());
	}

#ifdef PRINT_FILE_OP
	for (auto line : command_lines)
	{
		qDebug() << QString::fromStdString(line) << endl;
	}
#endif

	command_file.close(); // 关闭文件，数据已经完全读取
}