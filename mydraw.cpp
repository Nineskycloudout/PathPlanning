#include "mydraw.h"
#include "ui_mydraw.h"
#include "bounding.h"

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
    QPoint Point1(36,85);
    QPoint Point2(162,84);
    QPoint Point3(179,184);
    QPoint Point4(39,129);
    QPoint Point5(16,90);
    QVector<QPoint> points;
    QPainter painter(this);
    points.push_back(Point1);
    points.push_back(Point2);
    points.push_back(Point3);
    points.push_back(Point4);
    points.push_back(Point5);
    painter.drawLine(Point1,Point5);
    painter.drawLine(Point1,Point2);
    painter.drawLine(Point2,Point3);
    painter.drawLine(Point3,Point4);
    painter.drawLine(Point4,Point5);

    QPen pen(QColor(0,0,255));
    painter.setPen(pen);
    bounding B(points);
    B.buildBounding();
    QVector<QPoint> boundBox = B.getPoints();
    for(int i = 0;i<boundBox.length()-1;i++)
        painter.drawLine(boundBox[i],boundBox[i+1]);
    painter.drawLine(boundBox[0],boundBox[boundBox.length()-1]);
}
