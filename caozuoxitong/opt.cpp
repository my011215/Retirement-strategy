#include "opt.h"
#include "ui_opt.h"
#include "form.h"
#include <QDebug>
#include <QMessageBox>
#define max 100

extern QString blocknum;
QString optnum;
QStringList opt1;
extern QString s;

opt::opt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::opt)
{
    ui->setupUi(this);
}

opt::~opt()
{
    delete ui;
}

void opt::on_textEdit_textChanged()
{
    blocknum=ui->textEdit->toPlainText();
}

void opt::on_textEdit_2_textChanged()
{
    optnum=ui->textEdit_2->toPlainText();
}

void opt::on_textEdit_3_textChanged()
{
    s=ui->textEdit_3->toPlainText();
}

void opt::on_pushButton_clicked()
{
    QMessageBox button;
    button.setText("Successful!!!");
    button.setStandardButtons(QMessageBox::Yes);
    button.setButtonText (QMessageBox::Yes,QString("OK"));
    int res= button.exec();
    if(res ==QMessageBox::Yes)
    {
        QString str="\n";
        opt1=s.split(" ");
        int hit=0;  //命中次数
        QString block[blocknum.toInt()];    //数据大小为块数大小，用来存储每一次进入的页面
        block[0]=opt1[0];   //一开始第一个肯定为页面序列的第一个
        ui->textEdit_4->insertPlainText(block[0]+" ");           //输出第一轮页面结果
        ui->textEdit_4->insertPlainText(str);
        int x=1;
        for(int i=1;i<blocknum.toInt();i++) //从1开始循环，一直到存储每一次进入页面的数组空间满了跳出循环
        {
            int flag=0;     //标记
            for(int j=0;j<i;j++)    //判断现在页面的序号与之前存储好的页面序号是否相等
            {
                if(block[j]==opt1[i])   //相等，命中加1，标记为1
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
                block[i]=opt1[i];
                x++;
                for(int m=0;m<x;m++)
                {
                     ui->textEdit_4->insertPlainText(block[m]+" ");
                }
                break;
            }
             ui->textEdit_4->insertPlainText(str);
        }
        for(int i=blocknum.toInt();i<optnum.toInt();i++)//内存装满后开始循环，直到所有页面序号处理完跳出循环
        {
            int flag=0; //标记
            for(int j=0;j<blocknum.toInt();j++) //判断当前的页面序号和之前存入的页面序号有没有相同的
            {
                if(opt1[i]==block[j])   //相同时，标记为1
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
                int distance[optnum.toInt()];
                for(int h=0;h<blocknum.toInt();h++)
                {
                    int count=1;
                    int flag1=0;
                    for(int l=i;l<optnum.toInt();l++)
                    {
                        if(opt1[l]!=block[h])
                        {
                            count++;
                        }
                        else
                        {
                            flag1=1;
                            break;
                        }
                    }
                    if(flag1)
                    {
                        distance[h]=count;
                    }
                    else
                    {
                        distance[h]=max;
                    }
                }
                int x1=-1;
                int x2=-1;
                for(int kk=0;kk<blocknum.toInt();kk++)
                {
                    if(distance[kk]>x1)
                    {
                        x1=distance[kk];
                        x2=kk;
                    }
                }
                block[x2]=opt1[i];
                for(int m=0;m<blocknum.toInt();m++) //输出当前数组的页面序号
                {
                    ui->textEdit_4->insertPlainText(block[m]+" ");
                }
            }
             ui->textEdit_4->insertPlainText(str);
        }
        int misspage=optnum.toInt()-hit;
        QString str2;
        str2=QString::number(misspage);
        QString str1="缺页次数：";
        ui->textEdit_4->insertPlainText(str1+str2);
    }
}

void opt::on_pushButton_2_clicked()
{
    this->close();
    Form *f2=new Form();
    f2->show();
}
