#ifndef LRU_H
#define LRU_H
#include <QWidget>

namespace Ui {
class lru;
}

class lru : public QWidget
{
    Q_OBJECT

public:
    explicit lru(QWidget *parent = 0);
    ~lru();

private slots:
    void on_textEdit_textChanged();

    void on_textEdit_2_textChanged();

    void on_textEdit_3_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::lru *ui;
};

#endif // LRU_H
