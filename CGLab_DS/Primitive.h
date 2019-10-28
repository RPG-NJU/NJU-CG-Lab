#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QPen>

#include "Define.h"

/*
 * 这个类的设想是用来完成图元的定义
 * 只有定义了图元，才能够在线性存储中存储图元
 * 这样子可以把图像进行一定的模块化管理，而不是一成不变
 */

struct StraightLinePrimitive
{
	int begin_x;
	int begin_y;
	int end_x;
	int end_y;

	void setData(int x1, int y1, int x2, int y2);
};


class Primitive
{
private:
	PrimitiveType type; // 图元的类型
	int p_num; // 用于代表图元编号，primitive number

	// 图元信息存储
	QPen pen_in_use;
	StraightLinePrimitive straight_line;
	// END of 图元信息存储
	
public:
    Primitive(int p_num);
	bool setStraightLine(int x1, int y1, int x2, int y2, QPen pen);
};

#endif // PRIMITIVE_H
