#ifndef OPT_H
#define OPT_H
#include <QWidget>

namespace Ui {
class opt;
}

class opt : public QWidget
{
    Q_OBJECT

public:
    explicit opt(QWidget *parent = 0);
    ~opt();

private slots:
    void on_textEdit_textChanged();

    void on_textEdit_2_textChanged();

    void on_textEdit_3_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::opt *ui;
};

#endif // OPT_H
