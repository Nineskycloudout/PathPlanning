#include "mydraw.h"
#include "ui_mydraw.h"

myDraw::myDraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myDraw)
{
    ui->setupUi(this);
}

myDraw::~myDraw()
{
    delete ui;
}

void myDraw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(QPoint(10,10),QPoint(50,50));
}
