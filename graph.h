#ifndef GRAPH_H
#define GRAPH_H
#include <QVector>
#include<QPoint>


class zgraph
{
public:
    zgraph();
    zgraph(int n){pointnum=n;};
    zgraph(const zgraph& exmple){pointnum=exmple.pointnum;pointdata.append(exmple.pointdata);};

    int graphnum;//障碍物总数
    QVector<QPoint> pointdata;//障碍物图形中的点数据
    int pointnum;//障碍物图形中的点的数量
    //void data();
};




class graph:public zgraph
{
public:
    graph();
    graph(int n){graphnum=n;};
    QVector<zgraph> xgrapgh;//数组存储一幅图中障碍物图形
    int graphnum;//障碍物图形的数量
};



#endif // GRAPH_H
