#ifndef ROTATEDIALOG_H
#define ROTATEDIALOG_H

#include <QDialog>

namespace Ui {
class RotateDialog;
}

class RotateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RotateDialog(QWidget *parent = nullptr);
    ~RotateDialog();

private:
    Ui::RotateDialog *ui;
};

#endif // ROTATEDIALOG_H
