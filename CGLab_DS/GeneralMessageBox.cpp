#include "GeneralMessageBox.h"

GeneralMessageBox::GeneralMessageBox()
{

}

void GeneralMessageBox::NoSuchPrimitive(const int id, QWidget* parent)
{
	QMessageBox::warning(parent, QObject::tr("警告"), QObject::tr(("没有找到" + std::to_string(id) + "号图元").c_str()));
}


