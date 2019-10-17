﻿#ifndef DRAWINGAERA_H
#define DRAWINGAERA_H

#include <QWidget>
#include <QImage>

class DrawingArea : public QWidget
{
	Q_OBJECT
private:
	QImage paper; // 用于存储画布，作为当前显示的画面存储
	
public:
    DrawingArea(QWidget* parent = nullptr);
	void paintEvent(QPaintEvent* event) override; // 绘图事件函数重写
	void mouseMoveEvent(QMouseEvent* event) override; // 鼠标移动函数重写

signals:
	void newLocationStatus(const QString& location, int timeout = 0); // 传递给状态栏鼠标新的位置信息，第一个参数为要显示的字符，第二个参数为延迟
};

#endif // DRAWINGAERA_H
