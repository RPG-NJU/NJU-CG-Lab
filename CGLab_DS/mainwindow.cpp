//#include <QMessageBox>
#include <QObject>

#include <windows.h>
#include <shellapi.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AboutAuthorDialog.h"
#include "AboutSoftwareDialog.h"

//#include "ui_mainwindow.h"






// reply of the requery

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // 这个语句是分析代码之后建立UI部分的部分代码
	QObject::connect(ui->drawingArea, &DrawingArea::newLocationStatus, ui->statusBar, &QStatusBar::showMessage);
	QObject::connect(ui->drawingArea, &DrawingArea::mouseLeave, ui->statusBar, &QStatusBar::clearMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAboutAuthor_triggered()
/*
 * 在当前所有的项目文件中，并找不到connect函数来连接此槽函数和相关信号
 * 与代码直接编写的信号槽机制不同，如这个函数所示的，是通过Qt Designer直接形成函数框架的
 * <<所以注意，不要自己更改函数名>>
 * 实际上，相关的定义和代码在Build目录中的moc_*.cpp中
 * 这是Qt编译和生成项目的时候，自己创建和维护的文件内容，即使不在项目文件目录中，也不影响项目的生成和编译
 * 事实上，由Qt Designer设计的页面的部分代码生成，基本上都由ui->setupUi(this);生成
 */
{
    QDialog* about_author_dialog = new AboutAuthorDialog();
    about_author_dialog->exec();
    return;
}


void MainWindow::on_actionAboutSoftware_triggered()
{
	QDialog* about_software_dialog = new AboutSoftwareDialog();
	about_software_dialog->exec();
	return;
}

void MainWindow::on_actionReleaseHistory_triggered()
{
	ShellExecute(nullptr, L"open", L"https://github.com/HELLORPG/RPG-DrawingSoftware/releases", nullptr, nullptr, SW_SHOWMAXIMIZED);
	return;
}

void MainWindow::on_actionUpgrade_triggered()
{
    ShellExecute(nullptr, L"open", L"https://github.com/HELLORPG/RPG-DrawingSoftware/releases/latest", nullptr, nullptr, SW_SHOWMAXIMIZED);
    return;
}

void MainWindow::on_actionChooseNature_triggered()
{
	ui->drawingArea->changePenMode(DrawMode::Nature);
	clearToolBarChecked(ClearToolBarCheckedMode::DrawMode);
	ui->actionChooseNature->setChecked(true);
	//ui->drawingArea->setPaperSize(1000, 1000);
	//ui->scrollAreaWidgetContents->setMinimumSize(1000, 1000);
	return;
}

void MainWindow::on_actionStraightLine_triggered()
{
    ui->drawingArea->changePenMode(DrawMode::StraightLine);
	clearToolBarChecked(ClearToolBarCheckedMode::DrawMode);
	ui->actionStraightLine->setChecked(true);
    return;
}

void MainWindow::on_actionOpenFile_triggered()
{
#ifdef PRINT_ACTION
	qDebug() << "<< ACTION >>    打开文件" << endl;
#endif
	QString file_path = QFileDialog::getOpenFileName(this,
		tr("\xe6\x89\x93\xe5\xbc\x80\xe6\x96\x87\xe4\xbb\xb6"), /*打开文件*/
		".",
		tr("\xe6\x8c\x87\xe4\xbb\xa4\xe6\x96\x87\xe4\xbb\xb6(*.txt);; \
			\xe5\x9b\xbe\xe5\x83\x8f\xe6\x96\x87\xe4\xbb\xb6(*.bmp)")/*指令文件 & 图像文件*/);

	if (file_path.isEmpty()) // 如果获取到的文件名为空
	{
		/*QMessageBox::warning(this, tr("Path"),
			tr("You did not select any file."));*/
		// 当前的设计中不需要这个提示，因为用户可能就是单纯的关闭了对话框放弃了文件的选择而已

		return;
	}

	auto end_of_name = file_path.end();
	--end_of_name;
	if (*end_of_name == 't') // 此时文件的后缀名为 .txt，为指令文件
	{
		//qDebug() << "command file" << endl;
		/*QFile file(file_path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QMessageBox::warning(this, tr("Read File"),
				tr("Cannot open file:\n%1").arg(file_path));
			return;
		}
		QTextStream in(&file);
		QTextEdit *textEdit = new QTextEdit(this);
		qDebug() << "new edit" << endl;
		textEdit->setText(in.readAll());
		file.close();*/
		ui->drawingArea->openCommandFile(file_path);
	}
	else // 此时为图像文件
	{
		
	}

	return;
}

void MainWindow::on_actionSaveFile_triggered()
{
	QString file_path = QFileDialog::getSaveFileName(this,
		tr("Save Picture"),
		".",
		tr("Picture(*.bmp)"));

	if (file_path.isEmpty()) // 如果没有选择任何的文件路径
	{
		return;
	}


	// 此时就是保存文件的操作了

	QImage picture = ui->drawingArea->getPaper();
	if (picture.save(file_path)) // 此时是已经保存成功了
	{
#ifdef PRINT_FILE_OP
		qDebug() << "[图片保存在了" << file_path << "]" << endl;
#endif
	}
	else // 文件保存失败
	{
		QMessageBox::warning(this, tr("Save Wrong!"),
			tr("\xe5\x9b\xbe\xe5\x83\x8f\xe4\xbf\x9d\xe5\xad\x98\xe5\xa4\xb1\xe8\xb4\xa5:\n%1").arg(file_path));
		
	}

	return;
}

void MainWindow::on_actionPalette_triggered()
{
	QColorDialog* palette = new QColorDialog(this);
	palette->setWindowTitle(tr("\xe8\xb0\x83\xe8\x89\xb2\xe6\x9d\xbf"/*调色板*/));
	palette->setWindowIcon(QIcon(":/MainWindow/Palette"));
	palette->show(); // 使用非拥塞可以方便操作

	QObject::connect(palette, &QColorDialog::colorSelected, ui->drawingArea, &DrawingArea::setPenColor);
	
	return;
}


void MainWindow::clearToolBarChecked(ClearToolBarCheckedMode mode)
{
	switch (mode)
	{
	case ClearToolBarCheckedMode::DrawMode:
		{
		ui->actionChooseNature->setChecked(false);
		ui->actionStraightLine->setChecked(false);
		break;
		}
	case ClearToolBarCheckedMode::All:
		{
		clearToolBarChecked(ClearToolBarCheckedMode::DrawMode);
		ui->actionPalette->setChecked(false);
		break;
		}
	}
}
