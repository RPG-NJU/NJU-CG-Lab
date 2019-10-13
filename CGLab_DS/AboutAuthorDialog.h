#ifndef ABOUTAUTHORDIALOG_H
#define ABOUTAUTHORDIALOG_H

#include <QDialog>

namespace Ui {
class AboutAuthorDialog;
}

class AboutAuthorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutAuthorDialog(QWidget *parent = nullptr);
    ~AboutAuthorDialog();

private:
    Ui::AboutAuthorDialog *ui;
    void gotoMain();
};

#endif // ABOUTAUTHORDIALOG_H
