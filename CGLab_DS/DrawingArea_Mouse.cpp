#include "DrawingArea.h"

/*
 * 这个文件重新构建了鼠标绘制图像的事件
 * 独立出来文件表示重构信息
 */

void DrawingArea::mouseDraw(QImage& thisPaper)
{
	switch (drawMode)
	{
	case DrawMode::None: break;	// 此时是不做图模式
	case DrawMode::Nature: break;	// 自然绘图模式当前没有实现
	case DrawMode::StraightLine: mouseDrawStraightLine(thisPaper, StraightLineAlgorithm::Bresenham); break;	// 默认使用Bresenham算法进行绘制
	case DrawMode::Circle: mouseDrawCircle(thisPaper); break;
	case DrawMode::Ellipse: mouseDrawEllipse(thisPaper); break;
	}

	return;
}


void DrawingArea::mouseDrawCircle(QImage& thisPaper)
{
	
}

void DrawingArea::mouseDrawEllipse(QImage& thisPaper)
{
	
}

void DrawingArea::mouseDrawPolygon(QImage& thisPaper, const StraightLineAlgorithm algorithm)
{
	
}

void DrawingArea::mouseDrawStraightLine(QImage& thisPaper, const StraightLineAlgorithm algorithm)
{
	
}



