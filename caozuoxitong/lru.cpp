#include "ui_lru.h"
#include "form.h"
#include <QDebug>
#include <QMessageBox>
#define max 100

extern QString blocknum;
QString lrunum;
QStringList lru1;
extern QString s;

lru::lru(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lru)
{
    ui->setupUi(this);
}

lru::~lru()
{
    delete ui;
}

void lru::on_textEdit_textChanged()
{
    blocknum=ui->textEdit->toPlainText();
}

void lru::on_textEdit_2_textChanged()
{
    lrunum=ui->textEdit_2->toPlainText();
}

void lru::on_textEdit_3_textChanged()
{
    s=ui->textEdit_3->toPlainText();
}

void lru::on_pushButton_clicked()
{
    QMessageBox button;
    button.setText("Successful!!!");
    button.setStandardButtons(QMessageBox::Yes);
    button.setButtonText (QMessageBox::Yes,QString("OK"));
    int res= button.exec();
    if(res ==QMessageBox::Yes)
    {
        QString str="\n";
        lru1=s.split(" ");
        int hit=0;
        int y=1;
        QString block[blocknum.toInt()];
        block[0]=lru1[0];
        ui->textEdit_4->insertPlainText(block[0]+" ");           //输出第一轮页面结果
        ui->textEdit_4->insertPlainText(str);
        for(int i=1;i<blocknum.toInt();i++)
        {
            int flag=0;
            for(int m=0;m<i;m++)
            {
                if(block[m]==lru1[i])
                {
                    hit++;
                    flag=1;
                    QString z=block[m];
                    for(int f=m+1;f<i;f++)
                    {
                        block[f-1]=block[f];
                    }
                    block[i-1]=z;
                    break;
                }
            }
            while(flag)
            {
                for(int j=0;j<i;j++)
                {
                   ui->textEdit_4->insertPlainText(block[j]+" ");
                }
                break;
            }
            while(!flag)
            {
                block[i]=lru1[i];
                y++;
                for(int j=0;j<y;j++)
                {
                    ui->textEdit_4->insertPlainText(block[j]+" ");
                }
                break;
            }
            ui->textEdit_4->insertPlainText(str);
        }
        int x=0;
        for(int i=blocknum.toInt();i<lrunum.toInt();i++)
        {
            int flag=0;
            for(int j=0;j<blocknum.toInt();j++)
            {
                if(lru1[i]==block[j])
                {
                    flag=1;
                    x++;
                    QString z=block[j];
                    for(int f=j+1;f<blocknum.toInt();f++)
                    {
                        block[f-1]=block[f];
                    }
                    block[blocknum.toInt()-1]=z;
                    break;
                }
            }
            if(flag)
            {
                for(int m=0;m<blocknum.toInt();m++)
                {
                    ui->textEdit_4->insertPlainText(block[m]+" ");
                }
            }
            else
            {
                for(int h=1;h<blocknum.toInt();h++)
                {
                    block[h-1]=block[h];
                }
                block[blocknum.toInt()-1]=lru1[i];
                for(int m=0;m<blocknum.toInt();m++)
                {
                    ui->textEdit_4->insertPlainText(block[m]+" ");
                }
            }
            ui->textEdit_4->insertPlainText(str);
        }
        int misspage=lrunum.toInt()-x-hit;
        QString str2;
        str2=QString::number(misspage);
        QString str1="缺页次数：";
        ui->textEdit_4->insertPlainText(str1+str2);
    }
}

void lru::on_pushButton_2_clicked()
{
    this->close();
    Form *f2=new Form();
    f2->show();

}
