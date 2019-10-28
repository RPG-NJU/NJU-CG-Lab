#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		
	}
	else
	{
		QApplication app(argc, argv);
		MainWindow window;
		window.show();
		return app.exec();
	}
}
