#ifndef SCALEDIALOG_H
#define SCALEDIALOG_H

#include <QDialog>

namespace Ui {
class ScaleDialog;
}

class ScaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScaleDialog(time_t uid, QWidget *parent = nullptr);
    ~ScaleDialog();

	void accept() override;
	void receive(const time_t uid, bool flag);

signals:
	void scale_data(const int id, const int x0, const int y0, const double s, const time_t uid);
private:
    Ui::ScaleDialog *ui;
	time_t uid;
};

#endif // SCALEDIALOG_H
