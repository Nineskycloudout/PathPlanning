#ifndef BOUNDING_H
#define BOUNDING_H
#include <QPoint>
#include <QLine>
#include <QVector>
#include <QPolygon>
#include <QtMath>
#include <QLineF>
#include <QPointF>

class bounding
{
private:
    QVector<QPoint> orPoints; //初始障碍物顶点
    QVector<QLine> lines; // 包围盒顶点连成的线
    QVector<QPoint> points; //包围盒顶点
    QPoint getCross(QLine line1,QLine line2); //求两条线交点   
    int computS(QPolygon QP); //计算包围盒面积大小
    int S = 0; //四边形包围盒面积
public:
    bounding(QVector<QPoint> origPoints);
    QVector<QLine> getLines(); // 获取包围盒的线
    QVector<QPoint> getPoints(); // 获取包围盒的顶点
    void buildBounding(); // 生成包围盒
    int getS();

};

#endif // BOUNDING_H
