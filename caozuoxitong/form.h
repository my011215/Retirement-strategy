#ifndef FORM_H
#define FORM_H
#include <QWidget>
#include "fifo.h"
#include "lru.h"
#include "opt.h"


namespace Ui {
class Form;

}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Form *ui;
    fifo f1;
    lru l1;
    opt o1;
};

#endif // FORM_H
