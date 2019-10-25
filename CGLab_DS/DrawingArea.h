#ifndef DRAWINGAERA_H
#define DRAWINGAERA_H

#include <QWidget>
#include <QImage>
#include <QRgb>
#include <QPoint>
#include <QPen>

#include <vector>

using std::vector;

#include "Define.h"

class DrawingArea : public QWidget
{
	Q_OBJECT
private:
	// 所需要的数据成员
	bool isDrawing = false; // 用于表示是否正在作图
	
	DrawMode penMode = DrawMode::None; // 用于表示当前画笔的状态
	
	
	QImage paper; // 用于存储画布，作为当前显示的画面存储
	QImage tempPaper; // 用于存储临时画布，作为画布的临时存储

	QPen pen; // 绘图笔

	QPoint begin_point, end_point; // 鼠标绘图事件中的鼠标起始点和终点
	
	// END of DATA

	QString penModeToQString(DrawMode mode);
	
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

	vector<MyPoint> createStraightLineByNone(int x1, int x2, int y1, int y2);
	
signals:
	void newLocationStatus(const QString& location, int timeout = 0); // 传递给状态栏鼠标新的位置信息，第一个参数为要显示的字符，第二个参数为延迟
	void mouseLeave(); // 传递给状态栏用于清空信息的信号，代表鼠标已经移出了当前的窗口
};

#endif // DRAWINGAERA_H
