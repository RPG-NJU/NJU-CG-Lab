#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QPen>
#include <QPoint>
#include <QDebug>

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
	virtual void print() const;
	QPen _pen() const { return pen_in_use; }
	PrimitiveType _type() const { return type; }
};


class StraightLinePrimitive : public Primitive
{
private:
	int begin_x;
	int begin_y;
	int end_x;
	int end_y;
	StraightLineAlgorithm algorithm;

public:
	StraightLinePrimitive(int x1, int y1, int x2, int y2, int p_num, QPen pen, StraightLineAlgorithm algorithm) :
		Primitive(p_num, pen, PrimitiveType::StraightLine), begin_x(x1), begin_y(y1), end_x(x2), end_y(y2), algorithm(algorithm) { }
	StraightLinePrimitive() :
		Primitive(), begin_x(0), begin_y(0), end_x(0), end_y(0), algorithm(StraightLineAlgorithm::Bresenham) { }
	StraightLinePrimitive(QPoint begin, QPoint end, QPen pen, int p_num, StraightLineAlgorithm algorithm = StraightLineAlgorithm::Bresenham) :
		Primitive(p_num, pen, PrimitiveType::StraightLine), begin_x(begin.x()), begin_y(begin.y()), end_x(end.x()), end_y(end.y()), algorithm(algorithm) { }
	bool setDataByMouseEvent(int p_num, QPen pen, QPoint begin_xy, QPoint end_xy);
	void print() const override;
	int x1() const { return begin_x; }
	int x2() const { return end_x; }
	int y1() const { return begin_y; }
	int y2() const { return end_y; }
};


class EllipsePrimitive : public Primitive
{
private:
	int x0;
	int y0;
	int rx;
	int ry;

public:
	EllipsePrimitive(int x0 = 0, int y0 = 0 , int rx = 0, int ry = 0, int p_num = 0, QPen pen = QPen()) :
		Primitive(p_num, pen, PrimitiveType::Ellipse), x0(x0), y0(y0), rx(rx), ry(ry) { }
	EllipsePrimitive(QPoint begin, QPoint end, QPen pen, int p_num);
	void print() const override;
	int _x0() const { return x0; }
	int _y0() const { return y0; }
	int _rx() const { return rx; }
	int _ry() const { return ry; }
	
};
#endif // PRIMITIVE_H
