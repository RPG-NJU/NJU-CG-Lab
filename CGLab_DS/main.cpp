#include "mainwindow.h"

#include <QApplication>

#include <iostream>
//#include <Windows.h>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		//AllocConsole();
		//freopen("CONOUT$", "w+t", stdout);
		///*
		// * https://blog.csdn.net/lwwl12/article/details/79816739
		// */
		/*cout << "[命令行模式启动] 参数列表为" << endl;
		cout << argv[1] << endl;
		cout << argv[2] << endl;*/ // 这段代码是无法输出的，因为没有控制台的存在
		DrawingArea drawingArea(nullptr); // 其实可以不必要传参数，因为默认参数就是nullptr，这里只是为了规范体现
	}
	else
	{
		QApplication app(argc, argv);
		MainWindow window;
		window.show();
		return app.exec();
	}
}
