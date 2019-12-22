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
#include "SetPaperSizeDialog.h"
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
	void setToolBarEnable(const bool enable, const SetToolBarEnableMode mode);

	void selectBegin(); // 开启选择模式，选择模式下绘图模式将会被屏蔽
	void selectEnd(); // 结束选择模式，恢复绘图模式
	void selectAreaEnd(); // 选择框结束

    void on_actionCircle_triggered(); // 用户选择了圆形绘制

    void on_actionEllipse_triggered();

    void on_actionRedrawAll_triggered();

    void on_actionClearPaper_triggered();

    void on_actionSetPaperSize_triggered(); // 用户要设置画布大小


    void on_actionPolygon_triggered();

    void on_actionCurveBezier_triggered();

    void on_actionCurveB_spline_triggered();

    void on_actionInputTranslate_triggered();

    void on_actionInputRotate_triggered();

    void on_actionInputScale_triggered();

    void on_actionInputClip_triggered();

    void on_actionSelect_triggered();

    void on_actionCancelSelect_triggered();

    void on_actionMouseTranslate_triggered();

    void on_actionMouseRotate_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
