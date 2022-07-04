#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include"graph.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


    /*
    bool press1;
    bool press2;
    QPoint point1;
    QPoint point2;
    QList<QPoint> point_list1;
    QList<QPoint> point_list2;
*/
};




#endif // MAINWINDOW_H
