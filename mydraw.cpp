#include "mydraw.h"
#include "ui_mydraw.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
mydraw::mydraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mydraw)
{
    ui->setupUi(this);
}

mydraw::~mydraw()
{
    delete ui;
}
void mydraw::mouseReleaseEvent(QMouseEvent *event)
{
    x2 = event->x();
    y2 = event->y();
    update();
}

void mydraw::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"myLabel::mousePressEvent";

    x1 = event->x();
    y1 = event->y();
    qDebug()<<"myLabel::mousePressEvent" << x1 << y1;

}

void mydraw::paintEvent(QPaintEvent *event)
{
    qDebug()<<"myLabel::paintEvent";

    QWidget::paintEvent(event);

    QPainter painter(this);
    QPen pen;       //设置画笔，颜色、宽度
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
//    if(x1>0)
//    {
//        int xxxx=1;
//    }
    painter.drawRect(QRect(x1, y1, x2 - x1, y2 - y1));
    //int xxx=1;
}

