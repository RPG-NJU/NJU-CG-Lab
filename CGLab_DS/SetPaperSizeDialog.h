#ifndef SETPAPERSIZEDIALOG_H
#define SETPAPERSIZEDIALOG_H

#include <QDialog>

namespace Ui {
class SetPaperSizeDialog;
}

class SetPaperSizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetPaperSizeDialog(QWidget *parent = nullptr);
    ~SetPaperSizeDialog();
	void setXinput(int x);
	void setYinput(int y);

	int _x() const;
	int _y() const;

private:
    Ui::SetPaperSizeDialog *ui;
};

#endif // SETPAPERSIZEDIALOG_H
