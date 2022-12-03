#ifndef DUIBI_H
#define DUIBI_H

#include <QWidget>

namespace Ui {
class duibi;
}

class duibi : public QWidget
{
    Q_OBJECT

public:
    explicit duibi(QWidget *parent = 0);
    ~duibi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::duibi *ui;
};

#endif // DUIBI_H
