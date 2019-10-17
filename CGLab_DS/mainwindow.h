#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "DrawingArea.h"
//#include <QStatusBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	

private slots:
    void on_actionAboutAuthor_triggered(); // 用户点击了 “关于作者”

    void on_actionAboutSoftware_triggered(); // 用户点击了 “关于软件”

    void on_actionReleaseHistory_triggered(); // 用户点击了 “历史版本”

    void on_actionUpgrade_triggered(); // 用户点击了 “更新”

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
