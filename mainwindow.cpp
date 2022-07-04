#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include<qpoint.h>
#include"graph.h"
#include"graph.cpp"
#include <QDebug>
#include<vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::mousePressEvent(QMouseEvent *e)
{

    //将当前点坐标显示在按钮中
  // ui->pushButton->setText(tr("(%1, %2)").arg(e->x()).arg(e->y()));


/*


    //左键两下收集点坐标，右键更新画图
   if(e->button() == Qt::LeftButton){
           this->press1 = true;
       }
   if(e->buttons() & Qt::LeftButton)
      {
          if(this->press1)     //只有鼠标被按下的时候才记录坐标
          {
              point1 = e->pos();       //记录坐标
              point_list1.append(point1);   //记录每一次移动的坐标

              update();                   //更新，让画笔画画
          }
      }
   if(e->button() == Qt::RightButton){
           this->press2 = true;
       }
   if(e->buttons() & Qt::RightButton)
      {
          if(this->press2)     //只有鼠标被按下的时候才记录坐标
          {
              point1 = e->pos();       //记录坐标
              point_list2.append(point2);   //记录每一次移动的坐标

              update();                   //更新，让画笔画画
          }
      }


*/


}
bool f=0;

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(2);
    painter.setPen(pen);
/*
    //左键两下收集点坐标，右键更新画图
    QPen mypen;                     //创建画笔
        mypen.setWidth(4);             //点的大小
        mypen.setColor(Qt::black);      //点的颜色
        painter.setPen(mypen);          //画板设置画笔

        int i = 0;                      //把每一次鼠标移动的地方进行画点
        int j = 0;
        while(point_list1.size()!=0 && i != point_list1.size()&&point_list2.size()!=0 && j != point_list2.size())
        {
            painter.drawPoint(point_list1.at(i));
            painter.drawPoint(point_list2.at(j));
            QPoint opx=point_list1.at(i);
            QPoint opy=point_list1.at(i+1);

            painter.drawLine(opx,opy);
            i+=2;
            j++;
        }
*/
    //生成障碍物图
   if (f==1){
    zgraph a1(4),a2(3),a3(4),a4(4),a5(4),a6(4),a7(4),a8(3);
    QPoint aop11(36,85), aop12(162,84), aop13(179,184), aop14(39,129);
    QPoint aop21(224,83),aop22(247,178),aop23(378,83);
    QPoint aop31(356,160),aop32(536,77),aop33(523,261),aop34(359,210);
    QPoint aop41(274,237),aop42(536,297),aop43(556,367),aop44(298,426);
    QPoint aop51(39,200),aop52(193,246),aop53(222,501),aop54(48,481);
    QPoint aop61(297,477),aop62(613,427),aop63(590,537),aop64(296,530);
    QPoint aop71(630,128),aop72(707,161),aop73(659,358),aop74(595,310);
    QPoint aop81(734,246),aop82(765,554),aop83(675,542);

       a1.pointdata.append(aop11); a1.pointdata.append(aop12); a1.pointdata.append(aop13); a1.pointdata.append(aop14);
       a2.pointdata.append(aop21); a2.pointdata.append(aop22); a2.pointdata.append(aop23);
       a3.pointdata.append(aop31); a3.pointdata.append(aop32); a3.pointdata.append(aop33); a3.pointdata.append(aop34);
       a4.pointdata.append(aop41); a4.pointdata.append(aop42); a4.pointdata.append(aop43); a4.pointdata.append(aop44);
       a5.pointdata.append(aop51); a5.pointdata.append(aop52); a5.pointdata.append(aop53); a5.pointdata.append(aop54);
       a6.pointdata.append(aop61); a6.pointdata.append(aop62); a6.pointdata.append(aop63); a6.pointdata.append(aop64);
       a7.pointdata.append(aop71); a7.pointdata.append(aop72); a7.pointdata.append(aop73); a7.pointdata.append(aop74);
       a8.pointdata.append(aop81); a8.pointdata.append(aop82); a8.pointdata.append(aop83);

       graph m1;
       m1.xgrapgh.push_back(a1); m1.xgrapgh.push_back(a2); m1.xgrapgh.push_back(a3); m1.xgrapgh.push_back(a4); m1.xgrapgh.push_back(a5); m1.xgrapgh.push_back(a6); m1.xgrapgh.push_back(a7); m1.xgrapgh.push_back(a8);


            for(int j=0;j<8;j++){

                  for(int i=0;i< m1.xgrapgh[j].pointnum;i++)
                 {
                    if(i==m1.xgrapgh[j].pointdata.size()-1){
                         painter.drawLine(m1.xgrapgh[j].pointdata[i],m1.xgrapgh[j].pointdata[0]);
                       }
                       else{
                      painter.drawLine(m1.xgrapgh[j].pointdata[i],m1.xgrapgh[j].pointdata[i+1]);
                      }
                  }

          }
   }
}

void MainWindow::on_pushButton_clicked()
{
    f=1;
    update();
}
