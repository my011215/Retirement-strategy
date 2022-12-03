#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    this->close();
    f1.show();
}

void Form::on_pushButton_2_clicked()
{
    this->close();
    l1.show();
}

void Form::on_pushButton_3_clicked()
{
    this->close();
    o1.show();
}

