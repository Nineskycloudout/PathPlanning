#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(ui->pushButton);  //QPainter对象
    painter.drawLine(QPointF(0, 0), QPointF(100, 100)); //注意：不包括工具栏，坐标就是窗口的起点
}
MainWindow::~MainWindow()
{
    delete ui;
}


