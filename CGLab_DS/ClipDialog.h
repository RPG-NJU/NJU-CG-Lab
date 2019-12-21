#ifndef CLIPDIALOG_H
#define CLIPDIALOG_H

#include <QDialog>

namespace Ui {
class ClipDialog;
}

class ClipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClipDialog(time_t uid, QWidget *parent = nullptr);
    ~ClipDialog();

	void accept() override;
	void receive(const time_t uid, bool flag);

signals:
	void clip_data(const int id, const int x1, const int y1, const int x2, const int y2, const time_t uid);

private:
    Ui::ClipDialog *ui;
	time_t uid;
};

#endif // CLIPDIALOG_H
