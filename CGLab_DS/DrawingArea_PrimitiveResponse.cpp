#include "DrawingArea.h"

/*
 * 这是用来响应mainwindow中的“图元”下拉菜单中的对话框的函数定义部分
 * 
 */

void DrawingArea::inputTranslate(const int id, const int dx, const int dy, const time_t uid)
{
	// 首先要寻找给出的图元id是否存在
	for (auto &primitive : primitives)
	{
		if (primitive->id() == id) // 此时就找到了这个图元
		{
			// 下面对图元进行操作
			primitive->translate(dx, dy);
			refresh();
			emit dialogStatus(uid, true);
			return;
		}
	}

	// 如果执行到这里，则说明没有找到对应的图元
	QMessageBox::warning(this, tr("警告"), tr(("没有找到" + std::to_string(id) + "号图元").c_str()));

	return;
}
