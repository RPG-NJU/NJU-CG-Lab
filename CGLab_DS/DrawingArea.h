#ifndef DRAWINGAERA_H
#define DRAWINGAERA_H

#include <QWidget>
#include <QImage>
#include <QRgb>
#include <QPoint>
#include <QPen>
#include <QString>
#include <QFile>
#include <QTextEdit>
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QColor>

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <io.h>

using std::vector;
using std::swap;
using std::string;
using std::stringstream;

#include "Define.h"
#include "Primitive.h"
#include "OpFile.h"

class DrawingArea : public QWidget
{
	Q_OBJECT
private:
	// 所需要的数据成员
	bool isDrawing = false; // 用于表示是否正在作图
	
	DrawMode drawMode = DrawMode::StraightLine; // 用于表示当前画笔的状态
	
	
	QImage paper; // 用于存储画布，作为当前显示的画面存储
	QImage tempPaper; // 用于存储临时画布，作为画布的临时存储
	QRgb paperBackground;
	QPen pen; // 绘图笔
	QPoint begin_point, end_point; // 鼠标绘图事件中的鼠标起始点和终点


	string output_path = "";
	// END of DATA

	QString penModeToQString(DrawMode mode);

	vector<Primitive*> primitives; // 使用指针变量，可以使用父类统一所有的子类
	int now_primitive_num = 0;

	//QTextEdit* show_command_text;
	vector<vector<string> > commands;
public:
    DrawingArea(QWidget* parent = nullptr);
	void paintEvent(QPaintEvent* event) override; // 绘图事件函数重写
	void mouseMoveEvent(QMouseEvent* event) override; // 鼠标移动函数重写
	void leaveEvent(QEvent* event) override; // 移出当前组件的重写
	void enterEvent(QEvent* event) override; // 移入当前组件的重写
	void mousePressEvent(QMouseEvent* event) override; // 鼠标点击的函数重写
	void mouseReleaseEvent(QMouseEvent* event) override; // 鼠标释放的函数重写

	void draw(QImage& thisPaper); // 绘图函数
	void changePenMode(const DrawMode new_mode); // 用于响应画笔的更改
	void drawStraightLine(QImage& thisPaper, const QPoint line_begin, const QPoint line_end, const StraightLineAlgorithm algorithm);
	void drawCircle(QImage& thisPaper, const QPoint begin, const QPoint end);
	void drawEllipse(QImage& thisPaper, const QPoint begin, const QPoint end);
	
	vector<MyPoint> createStraightLineByNone(int x1, int x2, int y1, int y2);
	vector<MyPoint> createStraightLineByDDA(int x1, int y1, int x2, int y2);
	vector<MyPoint> createStraightLineByBresenham(int x1, int y1, int x2, int y2);
	vector<MyPoint> createEllipse(int x0, int y0, int rx, int ry); // 绘制椭圆的算法（整合了绘制圆的算法）
	vector<MyPoint> createPolygon(const vector<MyPoint> &vertices, StraightLineAlgorithm algorithm);

	void appendPrimitiveByMouseEvent(); // 在鼠标事件中，向容器中添加新的图元信息

	// 下面是所有的图元构造函数
	void appendStraightLinePrimitive(int x1, int y1, int x2, int y2, int p_num, QPen pen, StraightLineAlgorithm algorithm);
	void appendEllipsePrimitive(int x0, int y0, int rx, int ry, int p_num, QPen pen);
	


	// 文件系统
	bool openCommandFile(QString file_path);
	bool dirExist(const string dir_path); // 判断给出的路径是否是存在的
	//bool newDir(const string dir_path);
	string formatDirPath(string dir_path); // 集成了判断和新建给定路径的文件夹的操作 // 当前没有新建文件夹的功能


	// 对外接口
	QImage getPaper() const;
	void setPenColor(QColor color);
	void setPaperSize(int x, int y);

	void drawAll(); // 用于绘制所有图元
	void clearPaper(bool save_primitives); // 用于清除所有内容

	int getXsize() const { return this->geometry().width(); }
	int getYsize() const { return this->geometry().height(); }

	void setOutputPath(string dir_path);
	// 命令接口
	void runCommand();
	
signals:
	void newLocationStatus(const QString& location, int timeout = 0); // 传递给状态栏鼠标新的位置信息，第一个参数为要显示的字符，第二个参数为延迟
	void mouseLeave(); // 传递给状态栏用于清空信息的信号，代表鼠标已经移出了当前的窗口
	void setPaperSizeSignal(int x, int y);
};

#endif // DRAWINGAERA_H
