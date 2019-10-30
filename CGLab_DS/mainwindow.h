#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QImage>
#include <QColorDialog>
#include <QIcon>

#include "DrawingArea.h"
#include "Define.h"
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

    void on_actionChooseNature_triggered(); // 用户选择了 “自然线条”

    void on_actionStraightLine_triggered(); // 用户选择了 “直线”

    void on_actionOpenFile_triggered();

    void on_actionSaveFile_triggered();

    void on_actionPalette_triggered(); // 用户选择了调色板

	void clearToolBarChecked(ClearToolBarCheckedMode mode); // 用于清除


    void on_actionCircle_triggered(); // 用户选择了圆形绘制

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
