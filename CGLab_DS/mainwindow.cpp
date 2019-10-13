#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AboutAuthorDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_MainWindow_openAboutAuthorDialog()
//{
//    QDialog* about_author_dialog = new AboutAuthorDialog();
//    about_author_dialog->exec();
//    return;
//}

void MainWindow::on_actionAboutAuthor_triggered()
{
    QDialog* about_author_dialog = new AboutAuthorDialog();
    about_author_dialog->exec();
    return;
}
