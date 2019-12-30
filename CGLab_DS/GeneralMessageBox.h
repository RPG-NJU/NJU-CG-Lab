#ifndef GENERALMESSAGEBOX_H
#define GENERALMESSAGEBOX_H

#include <QObject>
#include <QWidget>
#include <QMessageBox>
#include <QString>

class GeneralMessageBox
{
public:
    GeneralMessageBox();
	static void NoSuchPrimitive(const int id, QWidget *parent = nullptr);
	static void NotCompleteArg(QWidget* parent = nullptr);
};

#endif // GENERALMESSAGEBOX_H
