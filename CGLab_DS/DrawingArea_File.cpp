#include "DrawingArea.h"


// 文件部分
void DrawingArea::openCommandFile(QString file_path)
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
}