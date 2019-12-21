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
    explicit RotateDialog(time_t uid, QWidget *parent = nullptr);
    ~RotateDialog();
	void accept() override;
	void receive(const time_t uid, bool flag);

signals:
	void rotate_data(const int id, const int x0, const int y0, const int r, const time_t uid);

private:
    Ui::RotateDialog *ui;
	time_t uid;
};

#endif // ROTATEDIALOG_H
