#include "DrawingArea.h"
#include "GeneralMessageBox.h"

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
	/*QMessageBox::warning(this, tr("警告"), tr(("没有找到" + std::to_string(id) + "号图元").c_str()));*/
	GeneralMessageBox::NoSuchPrimitive(id, this);

	return;
}

void DrawingArea::inputScale(const int id, const int x0, const int y0, const double s, const time_t uid)
{
	for (auto &primitive : primitives)
	{
		if (primitive->id() == id)
		{
			primitive->scale(x0, y0, s);
			refresh();
			emit dialogStatus(uid, true);
			return;
		}
	}

	/*QMessageBox::warning(this, tr("警告"), tr(("没有找到" + std::to_string(id) + "号图元").c_str()));*/
	GeneralMessageBox::NoSuchPrimitive(id, this);
	
	return;
}

void DrawingArea::inputClip(const int id, const int x1, const int y1, const int x2, const int y2, const time_t uid)
{
	//for (auto& primitive : primitives)
	//{
	//	if (primitive->id() == id)
	//	{
	//		primitive->clip(x1, y1, x2, y2, ClipAlgorithm::Liang_Barsky); // 这里默认使用Liang-Barsky算法进行裁剪
	//		refresh();
	//		emit dialogStatus(uid, true);
	//		return;
	//	}
	//}
	for (auto primitive = primitives.begin(); primitive < primitives.end(); ++primitive)
	{
		if ((*primitive)->id() == id) // 这里不同于之前使用的范围遍历，使用的是迭代器的方法遍历
		{
			bool flag = (*primitive)->clip(x1, y1, x2, y2, ClipAlgorithm::Liang_Barsky);
			(*primitive)->print();
			if (!flag) // 此时需要删除图元
			{
				primitives.erase(primitive); // 删除
			}
			refresh();
			emit dialogStatus(uid, true);
			return;
		}
	}

	GeneralMessageBox::NoSuchPrimitive(id, this);

	return;
}

void DrawingArea::inputRotate(const int id, const int x0, const int y0, const int r, const time_t uid)
{
	for (auto& primitive : primitives)
	{
		if (primitive->id() == id)
		{
			primitive->rotate(x0, y0, r);
			refresh();
			emit dialogStatus(uid, true);
			return;
		}
	}

	GeneralMessageBox::NoSuchPrimitive(id, this);

	return;
}

