#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <form.h>
#include <fifo.h>
#include <QDebug>
#include "QTextCodec"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
