#include "bounding.h"

bounding::bounding(QVector<QPoint> origPoints)
{
    orPoints = origPoints;
}

QPoint bounding::getCross(QLine line1, QLine line2)
{
    QPointF crossF(0,0); //交点
    QPointF pointf1(line1.x1(),line1.y1());
    QPointF pointf2(line1.x2(),line1.y2());
    QPointF pointf3(line2.x1(),line2.y1());
    QPointF pointf4(line2.x2(),line2.y2());
    QLineF linef1(pointf1,pointf2);
    QLineF linef2(pointf3,pointf4);
    QLineF::IntersectType type = linef1.intersects(linef2,&crossF);
    if (type != 1 && type!=2)
        crossF = QPointF(0,0);
    QPoint cross(crossF.x(),crossF.y());
    return cross;
}

int bounding::computS(QPolygon QP)
{
    QLineF line1 = QLineF(QP[0],QP[2]);
    QLineF line2 = QLineF(QP[1],QP[3]); // 两条对角线
    S = 0.5*line1.length()*line2.length()*sin(line1.angleTo(line2));
    return S;
}

QVector<QLine> bounding::getLines()
{
    return lines;
}

QVector<QPoint> bounding::getPoints()
{
    return points;
}

void bounding::buildBounding()
{
    QPolygon minPoly; // 最小四边形包围盒
    int minS = INT_MAX;  // 初始化最小面积
    int currentS; // 当前多边形面积
    QVector<QLine> orLines; //原始图形线段
    for(int i = 0; i < orPoints.length()-1; i++)
    {
        orLines.push_back(QLine(orPoints[i],orPoints[i+1]));
    }
    orLines.push_back(QLine(orPoints[orPoints.length()-1],orPoints[0]));

    QLine inLine = QLine(orPoints[0],orPoints[2]); //原始图形内部一条对角线
    QPoint inPoint = inLine.center(); //原始图形内部的一点，用于判断生成的四边形是否合法

    if(orLines.length()>4)
        for(int i = 0; i < orLines.length() - 3; i++)
            for(int j = i + 1; j < orLines.length() - 2; j++)
                for(int k = j + 1; k < orLines.length() - 1; k++)
                    for(int l = k + 1; l < orLines.length(); l++)
                    {
                        QVector<QPoint> crossPoints;
                        // 得到四条直线的交点
                        crossPoints.push_back(getCross(orLines[i],orLines[j]));
                        crossPoints.push_back(getCross(orLines[j],orLines[k]));
                        crossPoints.push_back(getCross(orLines[k],orLines[l]));
                        crossPoints.push_back(getCross(orLines[l],orLines[i]));
                        if(crossPoints[0] == QPoint(0,0)||crossPoints[1] == QPoint(0,0)||crossPoints[2] == QPoint(0,0)||crossPoints[3] == QPoint(0,0))
                            break; //如果多边形不符合包围盒条件，跳过
                        QPolygon crossPolygon(crossPoints); // 交点多边形
                        if(crossPolygon.containsPoint(inPoint,Qt::OddEvenFill))
                        {
                            currentS = computS(crossPolygon);
                            if(currentS<minS)
                                minPoly = crossPolygon;
                        }
                    }
    for(int i = 0;i<minPoly.length();i++)
        points.push_back(minPoly[i]);
}

int bounding::getS()
{
    return S;
}
