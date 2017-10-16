#ifndef MYQLABEL_H
#define MYQLABEL_H
#include<qlabel.h>
#include <QSize>
#include <QPoint>
#include <QMouseEvent>
class MyQlabel:public QLabel
{
    Q_OBJECT

public:
    explicit MyQlabel(QWidget *parent = 0);
    QPoint DefaultPoint;
protected:
    //virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseDoubleClickEvent(QMouseEvent *ev);
private:
    QSize *MiniSize;
    QSize *LargeSize;


signals:
    void clicked();
};
#endif // MYQLABEL_H
