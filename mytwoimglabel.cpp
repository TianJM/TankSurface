#include "mytwoimglabel.h"

MyTwoImgLabel::MyTwoImgLabel(QWidget *parent) : QWidget(parent)
{
    this->resize(1280,505);
    this->move(0,0);

    ImgLabelTitle1 = new QLabel(this);
    ImgLabelTitle2 = new QLabel(this);
    ImgLabelTitle1->setText(tr("FrontCamera"));
    ImgLabelTitle2->setText(tr("BackCamera"));
    ImgLabelTitle1->resize(640,20);
    ImgLabelTitle1->move(0,0);
    ImgLabelTitle2->resize(640,20);
    ImgLabelTitle2->move(640,0);
    ImgLabel1 = new QLabel(this);
    ImgLabel2 = new QLabel(this);
    ImgLabel1->resize(640,480);
    ImgLabel2->resize(640,480);
    ImgLabel1->move(-1,25);
    ImgLabel2->move(638,25);
    ImgLabel1->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");
    ImgLabel2->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");
}
