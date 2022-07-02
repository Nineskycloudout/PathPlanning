#ifndef MYDRAW_H
#define MYDRAW_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class myDraw;
}

class myDraw : public QWidget
{
    Q_OBJECT

public:
    explicit myDraw(QWidget *parent = nullptr);
    ~myDraw();

    void paintEvent(QPaintEvent *event);
private:
    Ui::myDraw *ui;
};

#endif // MYDRAW_H
