#ifndef TRANSLATEDIALOG_H
#define TRANSLATEDIALOG_H

#include <QDialog>
#include <ctime>

namespace Ui {
class TranslateDialog;
}

class TranslateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TranslateDialog(time_t uid, QWidget *parent = nullptr);
    ~TranslateDialog();
	void accept() override; // 点击确定之后的操作重载
	void receive(const time_t uid, bool flag);

signals:
	void translate_data(const int id, const int dx, const int dy, const time_t uid); // 该信号用于传递平移的操作信息

private:
    Ui::TranslateDialog *ui;
	time_t uid;
};

#endif // TRANSLATEDIALOG_H
