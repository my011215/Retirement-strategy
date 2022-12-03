#include "duibi.h"
#include "ui_duibi.h"
#include <QChar>
#include <QCharRef>
#include <QtChart>
using namespace QtCharts;

duibi::duibi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::duibi)
{
    ui->setupUi(this);
}

duibi::~duibi()
{
    delete ui;
}

void duibi::on_pushButton_clicked()
{chart = new QChart();
    //创建3个条线数据
    QBarSet *set0 = new QBarSet("零食");
    QBarSet *set1 = new QBarSet("水果");
    QBarSet *set2 = new QBarSet("主食");

    *set0 << 158 << 685 << 458 << 260 << 354;    //向零食数据添加这4个月的销售数据
    *set1 << 350 << 725 << 602 << 523 << 458;
    *set2 << 222 << 350 << 598 << 480 << 687;

    set0->setLabelColor(QColor(0,0,255));       //设置条形数据颜色
    set1->setLabelColor(QColor(0,0,255));
    set2->setLabelColor(QColor(0,0,255));

    QBarSeries *series = new QBarSeries();

    //series->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    //series->setLabelsVisible(true);

    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->setVisible(true);
    series->setLabelsVisible(true);

    chart->setTheme(QChart::ChartThemeLight);//设置白色主题
    chart->setDropShadowEnabled(true);//背景阴影
    chart->addSeries(series);//添加系列到QChart上

    chart->setTitleBrush(QBrush(QColor(0,0,255)));//设置标题Brush
    chart->setTitleFont(QFont("微软雅黑"));//设置标题字体
    chart->setTitle("超市销售条形图");

    //创建X轴和Y轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append("一月");
    axisX->append("二月");
    axisX->append("三月");
    axisX->append("四月");
    axisX->append("五月");
    axisX->setLabelsColor(QColor(7,28,96));

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0,1000);   //改为setRange(0,1);则表示坐标为动态计算大小的
    axisY->setTitleText("价格");
    axisY->setLabelFormat("%d$");

    chart->setAxisX(axisX,series);
    chart->setAxisY(axisY,series);

    //修改说明样式
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);//底部对齐
    chart->legend()->setBackgroundVisible(true);//设置背景是否可视
    chart->legend()->setAutoFillBackground(true);//设置背景自动填充
    chart->legend()->setColor(QColor(222,233,251));//设置颜色
    chart->legend()->setLabelColor(QColor(0,100,255));//设置标签颜色
    chart->legend()->setMaximumHeight(50);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *pVLayout = new QVBoxLayout(this);
    pVLayout->addWidget(chartView);
    ui->gridLayout->addWidget(chartView, 1, 0);
    m_charts << chartView;
    setLayout(ui->gridLayout);

}
