#ifndef MYTWOIMGLABEL_H
#define MYTWOIMGLABEL_H

#include <QWidget>
#include <QLabel>
class MyTwoImgLabel : public QWidget
{
    Q_OBJECT
private:
    QLabel *ImgLabelTitle1;
    QLabel *ImgLabelTitle2;
    QLabel *ImgLabel1;
    QLabel *ImgLabel2;
public:
    explicit MyTwoImgLabel(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MYTWOIMGLABEL_H
