#ifndef DRAWINGAERA_H
#define DRAWINGAERA_H

#include <QWidget>
#include <QImage>
#include <QRgb>
#include <QPoint>
#include <QPen>
#include <QString>
#include <QFile>
#include <QTextEdit>
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QColor>
#include <QRubberBand> // 用于实现矩形选择框

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <io.h>
#include <ctime>

using std::vector;
using std::swap;
using std::string;
using std::stringstream;

#include "Define.h"
#include "Primitive.h"
#include "OpFile.h"

class DrawingArea : public QWidget
{
	Q_OBJECT
private:
	// 所需要的数据成员

	// ----------状态区----------
	bool isDrawing = false; // 用于表示是否正在作图
	bool isSelect = false; // 表示是否进行选择状态
	// ----------状态区----------
	
	DrawMode drawMode = DrawMode::StraightLine; // 用于表示当前画笔的状态
	

	// ----------图层区----------
	QImage paper; // 用于存储画布，作为当前显示的画面存储
	QImage tempPaper; // 用于存储临时画布，作为画布的临时存储
	QImage temptempPaper; // 只用于曲线的绘制中的多缓冲
	// ----------图层区----------
	
	QRgb paperBackground;
	QPen pen; // 绘图笔
	QPoint begin_point, end_point; // 鼠标绘图事件中的鼠标起始点和终点


	string output_path = "";
	// END of DATA

	QString penModeToQString(DrawMode mode);

	// ----------图元部分----------
	vector<Primitive*> primitives; // 使用指针变量，可以使用父类统一所有的子类
	int now_primitive_num = 0;
	Primitive* temp_primitive = nullptr; // 临时图元，用于进行鼠标绘制的时候操作
	Primitive* temptemp_primitive = nullptr; // 临时的临时图元
	// ----------图元部分----------
	
	

	//QTextEdit* show_command_text;
	vector<vector<string> > commands;
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
	void drawCircle(QImage& thisPaper, const QPoint begin, const QPoint end);
	void drawEllipse(QImage& thisPaper, const QPoint begin, const QPoint end);

	// 2019.12.5 打算重新构建整体的鼠标绘图逻辑
	// 更改为从图元出发，设置一个临时图元，对此进行操作就可以了
	// 本次新增的部分都使用mouse作为前缀，类似于，mouseDraw函数，用于与之前的draw函数进行区分，以此规定为命名规则
	void mouseDraw(QImage& thisPaper); // 鼠标调用的绘图函数
	void mouseDrawAdd(QImage& thisPaper); // 鼠标调用的增加信息函数
	void mouseDrawStraightLine(QImage& thisPaper, const StraightLineAlgorithm algorithm);
	void mouseDrawCircle(QImage& thisPaper);
	void mouseDrawEllipse(QImage& thisPaper);
	void mouseDrawPolygon(QImage& thisPaper, const StraightLineAlgorithm algorithm);
	void mouseDrawCurve_Bezier(QImage& thisPaper);
	void mouseDrawCurve_B_spline(QImage& thisPaper);
	void mouseDrawPolygonAddPoint(QImage& thisPaper);
	void mouseDrawCurveAddPoint(QImage& thisPaper);


	// 通过输入框来进行图元平移的响应函数
	void inputTranslate(const int id, const int dx, const int dy, const time_t uid);
	void inputScale(const int id, const int x0, const int y0, const double s, const time_t uid);
	void inputClip(const int id, const int x1, const int y1, const int x2, const int y2, const time_t uid);
	void inputRotate(const int id, const int x0, const int y0, const int r, const time_t uid);
	

	// 重构框架部分结束 2019.12.5

	vector<MyPoint> createStraightLine(int x1, int y1, int x2, int y2, StraightLineAlgorithm algorithm);
	vector<MyPoint> createStraightLineByNone(int x1, int x2, int y1, int y2);
	vector<MyPoint> createStraightLineByDDA(int x1, int y1, int x2, int y2);
	vector<MyPoint> createStraightLineByBresenham(int x1, int y1, int x2, int y2);
	vector<MyPoint> createEllipse(int x0, int y0, int rx, int ry); // 绘制椭圆的算法（整合了绘制圆的算法）
	vector<MyPoint> createPolygon(const vector<MyPoint> &vertices, StraightLineAlgorithm algorithm);
	vector<MyPoint> createCurve(const vector<MyPoint>& fixed_points, CurveAlgorithm algorithm);
	vector<MyPoint> createCurveByBezier(const vector<MyPoint>& fixed_points);
	vector<MyPoint> createCurveByB_spline(const vector<MyPoint>& fixed_points);

	MyPoint_double Bezier_P(const vector<MyPoint>& fixed_points, int i, int r, double u); // 用于迭代计算贝塞尔曲线
	MyPoint_double B_spline_3(const vector<MyPoint> p_points, double u); // 用于计算三次B样条曲线
	

	void appendPrimitiveByMouseEvent(); // 在鼠标事件中，向容器中添加新的图元信息

	// 下面是所有的图元压入队列的调用函数
	void appendStraightLinePrimitive(int x1, int y1, int x2, int y2, int p_num, QPen pen, StraightLineAlgorithm algorithm);
	void appendEllipsePrimitive(int x0, int y0, int rx, int ry, int p_num, QPen pen);
	void appendPolygonPrimitive(vector<MyPoint> vertices, int p_num, QPen pen, StraightLineAlgorithm algorithm);
	void appendCurvePrimitive(vector<MyPoint> fixed_points, int p_num, QPen pen, CurveAlgorithm algorithm);


	// 文件系统
	bool openCommandFile(QString file_path);
	bool dirExist(const string dir_path); // 判断给出的路径是否是存在的
	//bool newDir(const string dir_path);
	string formatDirPath(string dir_path); // 集成了判断和新建给定路径的文件夹的操作 // 当前没有新建文件夹的功能


	// 对外接口
	QImage getPaper() const;
	void setPenColor(QColor color);
	void setPaperSize(int x, int y);

	void drawAll(); // 用于绘制所有图元
	void drawPrimitive(Primitive* primitive, QImage &thisPaper); // 用于绘制某个特定的图元
	void drawVirtualPrimitive(Primitive* primitive, QImage& thisPaper); // 用于虚线绘制某个特定的图元
	void clearPaper(bool save_primitives); // 用于清除所有内容
	void refresh(); // 用于刷新整个画布
	
	void beginSelect(); // 开始进行选择操作
	void endSelect(); // 结束选择操作

	int getXsize() const { return this->geometry().width(); }
	int getYsize() const { return this->geometry().height(); }
	DrawMode getDrawMode() const { return drawMode; }

	void setOutputPath(string dir_path);
	// 命令接口
	void runCommand();
	
signals:
	void newLocationStatus(const QString& location, int timeout = 0); // 传递给状态栏鼠标新的位置信息，第一个参数为要显示的字符，第二个参数为延迟
	void mouseLeave(); // 传递给状态栏用于清空信息的信号，代表鼠标已经移出了当前的窗口
	void setPaperSizeSignal(int x, int y);
	void dialogStatus(time_t uid, bool flag);
};

#endif // DRAWINGAERA_H
