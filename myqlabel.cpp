#include "myqlabel.h"
MyQlabel::MyQlabel(QWidget *parent) : QLabel(parent)
{
    this->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");
    MiniSize = new QSize(320,240);
    LargeSize = new QSize(640,480);
    //DefaultPoint = new QPoint();
    this->resize(*MiniSize);
}
/*
void MyQlabel::mouseReleaseEvent(QMouseEvent *ev)
{

}*/
void MyQlabel::mouseDoubleClickEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
    Q_UNUSED(ev);
    if(this->size() == *MiniSize)
    {
        this->resize(*LargeSize);
    }
    else if(this->size() == *LargeSize)
    {
        this->resize(*MiniSize);
    }

    if(this->pos() == DefaultPoint)
    {
        this->move(30,40);
    }else
    {
        this->move(DefaultPoint);
    }
    emit clicked();
    this->setFrameShape(QFrame::Box);
    //this->setStyleSheet("border-width: 3px;border-style: solid;border-color: rgb(255, 170, 0);");
    }
}
