#ifndef DRAWINGAERA_H
#define DRAWINGAERA_H

#include <QWidget>
#include <QImage>

#include "Define.h"

class DrawingArea : public QWidget
{
	Q_OBJECT
private:
	// 所需要的数据成员

	// END of DATA
	
	QImage paper; // 用于存储画布，作为当前显示的画面存储
	PaintMode penMode; // 用于表示当前画笔的状态


	QString penModeToQString(PaintMode mode);
	
public:
    DrawingArea(QWidget* parent = nullptr);
	void paintEvent(QPaintEvent* event) override; // 绘图事件函数重写
	void mouseMoveEvent(QMouseEvent* event) override; // 鼠标移动函数重写
	void leaveEvent(QEvent* event) override; // 移出当前组件的重写
	void enterEvent(QEvent* event) override; // 移入当前组件的重写
	void mousePressEvent(QMouseEvent* event) override; // 鼠标点击的函数重写
	void mouseReleaseEvent(QMouseEvent* event) override; // 鼠标释放的函数重写

	void draw(QImage& thisPaper); // 绘图函数
	void changePenMode(const PaintMode new_mode); // 用于响应画笔的更改
signals:
	void newLocationStatus(const QString& location, int timeout = 0); // 传递给状态栏鼠标新的位置信息，第一个参数为要显示的字符，第二个参数为延迟
	void mouseLeave(); // 传递给状态栏用于清空信息的信号，代表鼠标已经移出了当前的窗口
};

#endif // DRAWINGAERA_H
