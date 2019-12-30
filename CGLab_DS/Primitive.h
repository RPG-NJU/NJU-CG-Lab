#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QPen>
#include <QPoint>
#include <QDebug>

#include <vector>
#include <cmath>
using std::vector;
using std::round;

#include "Define.h"

/*
 * 这个类的设想是用来完成图元的定义
 * 只有定义了图元，才能够在线性存储中存储图元
 * 这样子可以把图像进行一定的模块化管理，而不是一成不变
 */

class Primitive
{
protected:
	PrimitiveType type; // 图元的类型
	int p_num; // 用于代表图元编号，primitive number

	QPen pen_in_use; // 描述当前图元使用的画笔是什么

public:
	Primitive(int p_num = 0, QPen pen = QPen(), PrimitiveType type = PrimitiveType::None) :
		pen_in_use(pen), p_num(p_num), type(type) { }
	~Primitive() { }
	virtual void print() const; // 在调试输出中输出当前图元信息
	virtual void translate(const int dx, const int dy) = 0; // 平移函数，在这里是一个纯虚函数，不可以被调用
	virtual void rotate(const int x, const int y, const int r) = 0; // 旋转函数，在这里是一个纯虚函数，不可以被调用
	virtual void scale(const int x, const int y, const double s) = 0; // 缩放函数，同上
	virtual bool clip(const int x1, const int y1, const int x2, const int y2, ClipAlgorithm algorithm) = 0; // 裁剪函数，同上，其中返回值为false的时候，删除该图元
	virtual bool clipByCohen_Sutherland(const int x1, const int y1, const int x2, const int y2) = 0;
	virtual bool clipByLiang_Barsky(const int x1, const int y1, const int x2, const int y2) = 0;
	// 以上分别为两种裁剪的算法虚函数
	
	static int rotate_x(int x, int x0, int y, int y0, int r); // 其中，x为要求的旋转点，x0为旋转中心
	static int rotate_y(int y, int y0, int x, int x0, int r); // 其中，同上

	static int scale_t(int t, int t0, double s);
	
	QPen _pen() const { return pen_in_use; }
	PrimitiveType _type() const { return type; }

	int id() const { return p_num; } // 返回图元的ID
};


class StraightLine : public Primitive
{
private:
	int begin_x;
	int begin_y;
	int end_x;
	int end_y;
	StraightLineAlgorithm algorithm;

public:
	StraightLine(int x1, int y1, int x2, int y2, int p_num, QPen pen, StraightLineAlgorithm algorithm) :
		Primitive(p_num, pen, PrimitiveType::StraightLine), begin_x(x1), begin_y(y1), end_x(x2), end_y(y2), algorithm(algorithm) { }
	StraightLine() :
		Primitive(), begin_x(0), begin_y(0), end_x(0), end_y(0), algorithm(StraightLineAlgorithm::Bresenham) { }
	StraightLine(QPoint begin, QPoint end, QPen pen, int p_num, StraightLineAlgorithm algorithm = StraightLineAlgorithm::Bresenham) :
		Primitive(p_num, pen, PrimitiveType::StraightLine), begin_x(begin.x()), begin_y(begin.y()), end_x(end.x()), end_y(end.y()), algorithm(algorithm) { }
	StraightLine(const StraightLine &straight_line) :
		Primitive(straight_line.p_num, straight_line.pen_in_use, straight_line.type), begin_x(straight_line.begin_x), begin_y(straight_line.begin_y), end_x(straight_line.end_x), end_y(straight_line.end_y), algorithm(straight_line.algorithm) { }
	bool setDataByMouseEvent(int p_num, QPen pen, QPoint begin_xy, QPoint end_xy);
	
	void print() const override;
	void translate(const int dx, const int dy) override;
	void rotate(const int x, const int y, const int r) override;
	void scale(const int x, const int y, const double s) override;
	bool clip(const int x1, const int y1, const int x2, const int y2, ClipAlgorithm algorithm) override;
	bool clipByCohen_Sutherland(const int x1, const int y1, const int x2, const int y2) override;
	bool clipByLiang_Barsky(const int x1, const int y1, const int x2, const int y2) override;
	// 当前只有直线有裁剪算法的实现

	
	int x1() const { return begin_x; }
	int x2() const { return end_x; }
	int y1() const { return begin_y; }
	int y2() const { return end_y; }
	StraightLineAlgorithm _algorithm() const { return algorithm; }
};


class Ellipse : public Primitive
{
private:
	int x0;
	int y0;
	int rx;
	int ry;

public:
	Ellipse(int x0 = 0, int y0 = 0 , int rx = 0, int ry = 0, int p_num = 0, QPen pen = QPen()) :
		Primitive(p_num, pen, PrimitiveType::Ellipse), x0(x0), y0(y0), rx(rx), ry(ry) { }
	Ellipse(QPoint begin, QPoint end, QPen pen, int p_num);
	Ellipse(const Ellipse& ellipse) :
		Primitive(ellipse.p_num, ellipse.pen_in_use, ellipse.type), x0(ellipse.x0), y0(ellipse.y0), rx(ellipse.rx), ry(ellipse.ry) { }
	void print() const override;
	void translate(const int dx, const int dy) override;
	void rotate(const int x, const int y, const int r) override;
	void scale(const int x, const int y, const double s) override;
	bool clip(const int x1, const int y1, const int x2, const int y2, ClipAlgorithm algorithm) override;
	bool clipByCohen_Sutherland(const int x1, const int y1, const int x2, const int y2) override;
	bool clipByLiang_Barsky(const int x1, const int y1, const int x2, const int y2) override;

	
	int _x0() const { return x0; }
	int _y0() const { return y0; }
	int _rx() const { return rx; }
	int _ry() const { return ry; }
	
};

class Polygon : public Primitive
{
private:
	vector<MyPoint> vertices; // 用于记录所有的顶点信息，有多少个顶点就有多少个项，其中终点和起点进行连接，得到全部图形
	StraightLineAlgorithm algorithm;
	
public:
	Polygon(vector<MyPoint> vertices, int p_num, QPen pen = QPen(), StraightLineAlgorithm algorithm = StraightLineAlgorithm::Bresenham) :
		Primitive(p_num, pen, PrimitiveType::Polygon), vertices(vertices), algorithm(algorithm) { }
	Polygon(const Polygon &polygon) :
		Primitive(polygon.p_num, polygon.pen_in_use, polygon.type), algorithm(polygon.algorithm) {
		vertices.assign(polygon.vertices.begin(), polygon.vertices.end());
	}
	void print() const override;
	void translate(const int dx, const int dy) override;
	void rotate(const int x, const int y, const int r) override;
	void scale(const int x, const int y, const double s) override;
	bool clip(const int x1, const int y1, const int x2, const int y2, ClipAlgorithm algorithm) override;
	bool clipByCohen_Sutherland(const int x1, const int y1, const int x2, const int y2) override;
	bool clipByLiang_Barsky(const int x1, const int y1, const int x2, const int y2) override;

	void setTail(const int x, const int y) { vertices[vertices.size() - 1].x = x; vertices[vertices.size() - 1].y = y; return; } // 用于设置末尾点的坐标
	void addPoint();

	
	vector<MyPoint> _vertices() const { return vertices; }
	StraightLineAlgorithm _algorithm() const { return algorithm; }
};



class Curve : public Primitive
{
private:
	vector<MyPoint> fixed_points; // 用于记录所有的定点坐标信息
	CurveAlgorithm algorithm;
	
public:
	Curve(vector<MyPoint> fixed_points, int p_num, QPen pen, CurveAlgorithm algorithm) :
		Primitive(p_num, pen, PrimitiveType::Curve), fixed_points(fixed_points), algorithm(algorithm) { }
	Curve(const Curve& curve);
	void print() const override;
	void translate(const int dx, const int dy) override;
	void rotate(const int x, const int y, const int r) override;
	void scale(const int x, const int y, const double s) override;
	bool clip(const int x1, const int y1, const int x2, const int y2, ClipAlgorithm algorithm) override;
	bool clipByCohen_Sutherland(const int x1, const int y1, const int x2, const int y2) override;
	bool clipByLiang_Barsky(const int x1, const int y1, const int x2, const int y2) override;

	void setTail(const int x, const int y) { fixed_points[fixed_points.size() - 1].x = x; fixed_points[fixed_points.size() - 1].y = y; return; } // 用于设置末尾点的坐标
	void addPoint();

	CurveAlgorithm _algorithm() const { return algorithm; }
	vector<MyPoint> _fixed_points() const { return fixed_points; }
	
};


#endif // PRIMITIVE_H
