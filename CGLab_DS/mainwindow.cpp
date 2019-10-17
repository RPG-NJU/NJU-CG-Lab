#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AboutAuthorDialog.h"
#include "AboutSoftwareDialog.h"
//#include <QMessageBox>
#include <QObject>

#include <windows.h>
#include <shellapi.h>
//#include "ui_mainwindow.h"



// reply of the requery

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // 这个语句是分析代码之后建立UI部分的部分代码
	QObject::connect(ui->drawingArea, &DrawingArea::newLocationStatus, ui->statusBar, &QStatusBar::showMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAboutAuthor_triggered()
/*
 * 在当前所有的项目文件中，并找不到connect函数来连接此槽函数和相关信号
 * 与代码直接编写的信号槽机制不同，如这个函数所示的，是通过Qt Designer直接形成函数框架的
 * <<所以注意，不要自己更改函数名>>
 * 实际上，相关的定义和代码在Build目录中的moc_*.cpp中
 * 这是Qt编译和生成项目的时候，自己创建和维护的文件内容，即使不在项目文件目录中，也不影响项目的生成和编译
 * 事实上，由Qt Designer设计的页面的部分代码生成，基本上都由ui->setupUi(this);生成
 */
{
    QDialog* about_author_dialog = new AboutAuthorDialog();
    about_author_dialog->exec();
    return;
}


void MainWindow::on_actionAboutSoftware_triggered()
{
	QDialog* about_software_dialog = new AboutSoftwareDialog();
	about_software_dialog->exec();
	return;
}

void MainWindow::on_actionReleaseHistory_triggered()
{
	ShellExecute(nullptr, L"open", L"https://github.com/HELLORPG/RPG-DrawingSoftware/releases", nullptr, nullptr, SW_SHOWMAXIMIZED);
	return;
}

void MainWindow::on_actionUpgrade_triggered()
{
    ShellExecute(nullptr, L"open", L"https://github.com/HELLORPG/RPG-DrawingSoftware/releases/latest", nullptr, nullptr, SW_SHOWMAXIMIZED);
    return;
}
