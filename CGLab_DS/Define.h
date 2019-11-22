#ifndef DEFINE_H
#define DEFINE_H

//#define PRINT_MOUSE_LOCATION
#define PRINT_MOUSE_EVENT
#define PRINT_PEN
#define PRINT_DRAW
#define PRINT_ACTION // 如果定义，则调试输出所有action触发
#define PRINT_FILE_OP // 如果定义，则调试输出文件读写的过程



enum class DrawMode
{
	None, 
	Nature, 
	StraightLine,
	Circle,
	Ellipse
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
	Polygon
};


enum class StraightLineAlgorithm
{
	DDA,
	Bresenham,
	None
};


enum class ClearToolBarCheckedMode // 定义了对于清除工具栏选中状态的模式
{
	DrawMode,
	All
};


struct MyPoint
{
	int x;
	int y;
};


#endif // DEFINE_H