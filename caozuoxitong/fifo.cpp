#include "form.h"
#include "ui_fifo.h"
#include   <QDebug>
#include <QMessageBox>
#define max 100

QString blocknum;
QString fifonum;
QStringList fifo1;
QString s;

fifo::fifo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fifo)
{
    ui->setupUi(this);

}

fifo::~fifo()
{
    delete ui;
}

void fifo::on_textEdit_textChanged()
{
    blocknum=ui->textEdit->toPlainText();
}

void fifo::on_textEdit_2_textChanged()
{
    fifonum=ui->textEdit_2->toPlainText();
}

void fifo::on_textEdit_3_textChanged()
{
   s=ui->textEdit_3->toPlainText();
}



void fifo::on_pushButton_clicked()
{
    QMessageBox button;
    button.setText("Successful!!!");
    button.setStandardButtons(QMessageBox::Yes);
    button.setButtonText (QMessageBox::Yes,QString("OK"));
    int res= button.exec();
    if(res ==QMessageBox::Yes)
    {
        QString str="\n";
        fifo1=s.split(" ");
        int hit=0;  //命中次数
        QString block[blocknum.toInt()];    //数据大小为块数大小，用来存储每一次进入的页面
        block[0]=fifo1[0];   //一开始第一个肯定为页面序列的第一个
        ui->textEdit_4->insertPlainText(block[0]+" ");           //输出第一轮页面结果
        ui->textEdit_4->insertPlainText(str);
        int x=1;
        for(int i=1;i<blocknum.toInt();i++) //从1开始循环，一直到存储每一次进入页面的数组空间满了跳出循环
        {
            int flag=0;     //标记
            for(int j=0;j<i;j++)    //判断现在页面的序号与之前存储好的页面序号是否相等
            {
                if(block[j]==fifo1[i])   //相等，命中加1，标记为1
                {
                    hit++;
                    flag=1;
                }
            }
            while(flag) //当标记为1 ，表示当前命中，不需要重新放入页面号，只需要输出当前排好的页面
            {
                for(int m=0;m<x;m++)
                {
                    ui->textEdit_4->insertPlainText(block[m]+" ");
                }
                break;
            }
            while(!flag)    //当标记为0，表示当前未命中并且块数没满，需要重新放入页面号，然后输出当前排好的页面
            {
                block[i]=fifo1[i];
                x++;
                for(int m=0;m<x;m++)
                {
                    ui->textEdit_4->insertPlainText(block[m]+" ");
                }
                break;
            }
            ui->textEdit_4->insertPlainText(str);
        }
        int s=0;
        for(int i=blocknum.toInt();i<fifonum.toInt();i++)//内存装满后开始循环，直到所有页面序号处理完跳出循环
        {
            int flag=0; //标记
            for(int j=0;j<blocknum.toInt();j++) //判断当前的页面序号和之前存入的页面序号有没有相同的
            {
                if(fifo1[i]==block[j])   //相同时，标记为1
                {
                    flag=1;
                    hit++;  //命中+1
                }
            }
            if(flag)    //如果命中
            {
                for(int m=0;m<blocknum.toInt();m++) //输出当前数组的页面序号
                {
                    ui->textEdit_4->insertPlainText(block[m]+" ");
                }
            }
            else    //如果未命中，替换掉最开始的(从0开始，并且替换后+1）
            {
                block[s]=fifo1[i];
                s++;
                if(s==blocknum.toInt()) //当达到块数后，变为最初始的
                {
                    s=0;
                }
                for(int m=0;m<blocknum.toInt();m++) //输出当前数组的页面序号
                {
                    ui->textEdit_4->insertPlainText(block[m]+" ");
                }
            }
            ui->textEdit_4->insertPlainText(str);
        }
        int misspage=fifonum.toInt()-hit;
        QString str2;
        str2=QString::number(misspage);
        QString str1="缺页次数：";
        ui->textEdit_4->insertPlainText(str1+str2);
    }
}




void fifo::on_pushButton_2_clicked()
{
    this->close();
    Form *f2=new Form();
    f2->show();

}
