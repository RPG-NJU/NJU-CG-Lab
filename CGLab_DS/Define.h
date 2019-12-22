#ifndef DEFINE_H
#define DEFINE_H

//#define PRINT_MOUSE_LOCATION
#define PRINT_MOUSE_EVENT
#define PRINT_PEN
#define PRINT_DRAW
#define PRINT_ACTION // 如果定义，则调试输出所有action触发
#define PRINT_FILE_OP // 如果定义，则调试输出文件读写的过程
//#define PRINT_PRIMITIVE


#define PI 3.141592653

#define BEZIER_DELTA 0.005
#define B_SPLINE_DELTA 0.001
#define B_SPLINE_K 3 // 代表三次B样条曲线


enum class DrawMode
{
	None, 
	Nature, 
	StraightLine,
	Circle,
	Ellipse,
	Polygon,
	Curve_Bezier,
	Curve_B_spline
};

enum class PrimitiveType
{
	/*
	 * 用于定义存储的图元的类型
	 */
	None,
	Nature,
	StraightLine,
	Ellipse,
	Polygon,
	Curve
};


enum class StraightLineAlgorithm
{
	DDA,
	Bresenham,
	None
};

enum class CurveAlgorithm
{
	Bezier,
	B_spline
};


enum class ClearToolBarCheckedMode // 定义了对于清除工具栏选中状态的模式
{
	DrawMode,
	All,
	Transform
};

enum class SetToolBarEnableMode
{
	DrawMode,
	All,
	Primitive,
	Transform
};


enum class ClipAlgorithm
{
	Cohen_Sutherland,
	Liang_Barsky
};


struct MyPoint
{
	int x;
	int y;
};

struct MyPoint_double
{
	double x;
	double y;
};

MyPoint_double operator+(const MyPoint_double left, const MyPoint_double right); // 用于两个浮点数坐标的相加
MyPoint_double operator*(const MyPoint_double left, const MyPoint_double right); // 
MyPoint_double operator*(const double left, const MyPoint_double right);
MyPoint_double operator*(const MyPoint left, const MyPoint_double right);
MyPoint_double operator*(const MyPoint left, const double right);
bool operator==(const MyPoint &left, const MyPoint &right);
bool operator!=(const MyPoint& left, const MyPoint& right);
bool operator==(const MyPoint_double& left, const MyPoint& right);
bool operator!=(const MyPoint_double& left, const MyPoint& right);
#endif // DEFINE_H