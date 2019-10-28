#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QPen>
#include <QPoint>

#include "Define.h"

/*
 * 这个类的设想是用来完成图元的定义
 * 只有定义了图元，才能够在线性存储中存储图元
 * 这样子可以把图像进行一定的模块化管理，而不是一成不变
 */

 //struct StraightLinePrimitive
 //{
 //	int begin_x;
 //	int begin_y;
 //	int end_x;
 //	int end_y;
 //
 //	void setData(int x1, int y1, int x2, int y2);
 //};


class Primitive
{

protected:
	PrimitiveType type; // 图元的类型
	int p_num; // 用于代表图元编号，primitive number

	QPen pen_in_use; // 描述当前图元使用的画笔是什么

public:
	Primitive(int p_num = 0, QPen pen = QPen(), PrimitiveType type = PrimitiveType::None) :
		pen_in_use(pen), p_num(p_num), type(type) { }
	//Primitive(QPen pen) : pen_in_use(pen) { }
	//Primitive() :
	//	type(PrimitiveType::None), p_num(0) { }

};


class StraightLinePrimtive : public Primitive
{
private:
	int begin_x;
	int begin_y;
	int end_x;
	int end_y;

public:
	StraightLinePrimtive(int x1, int y1, int x2, int y2, int p_num, QPen pen) :
		Primitive(p_num, pen, PrimitiveType::StraightLine), begin_x(x1), begin_y(y1), end_x(x2), end_y(y2) { }
	StraightLinePrimtive() :
		Primitive(), begin_x(0), begin_y(0), end_x(0), end_y(0) { }
	StraightLinePrimtive(QPoint begin, QPoint end, QPen pen, int p_num) :
		begin_x(begin.x()), begin_y(begin.y()), end_x(end.x()), end_y(end.y()), Primitive(p_num, pen, PrimitiveType::StraightLine) { }
	bool setDataByMouseEvent(int p_num, QPen pen, QPoint begin_xy, QPoint end_xy);
};
#endif // PRIMITIVE_H
