#ifndef FIFO_H
#define FIFO_H
#pragma once
#include <QWidget>

class fifo;
namespace Ui {
class fifo;
}

class fifo : public QWidget
{
    Q_OBJECT

public:
    explicit fifo(QWidget *parent = 0);
    ~fifo();
private slots:
    void on_textEdit_textChanged();

    void on_textEdit_2_textChanged();

    void on_textEdit_3_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::fifo *ui;
};

#endif // FIFO_H
