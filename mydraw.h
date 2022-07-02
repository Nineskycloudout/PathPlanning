#ifndef MYDRAW_H
#define MYDRAW_H

#include <QWidget>
#include <QObject>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPoint>

namespace Ui {
class mydraw;
}

class mydraw : public QWidget
{
    Q_OBJECT

public:
    explicit mydraw(QWidget *parent = nullptr);
    ~mydraw();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    int x1, y1, x2, y2;

private:
    Ui::mydraw *ui;
};

#endif // MYDRAW_H
