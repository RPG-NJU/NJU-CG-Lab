#ifndef ABOUTSOFTWAREDIALOG_H
#define ABOUTSOFTWAREDIALOG_H

#include <QDialog>

namespace Ui {
class AboutSoftwareDialog;
}

class AboutSoftwareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutSoftwareDialog(QWidget *parent = nullptr);
    ~AboutSoftwareDialog();

private slots:
    void on_buttonUserMenu_clicked(); // 

    void on_buttonProjectPage_clicked();

private:
    Ui::AboutSoftwareDialog *ui;
};

#endif // ABOUTSOFTWAREDIALOG_H
