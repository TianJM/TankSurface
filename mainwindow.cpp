#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280,800);
    SI_Reader = new Status_Info_Reader();

    MainTabWidget = new QTabWidget(this);
    MainTabWidget->resize(1280,800);
    Widget1 = new QWidget(this);
    Widget2 = new QWidget(this);
    Widget3 = new QWidget(this);

    //FrontImgLabel = new MyQlabel(Widget1);
    //BackImgLabel = new MyQlabel(Widget1);
    //FrontImgLabel->move(15,10);
    //FrontImgLabel->DefaultPoint = FrontImgLabel->pos();
    //BackImgLabel->move(360,10);
    //BackImgLabel->DefaultPoint = BackImgLabel->pos();
    //connect(FrontImgLabel,SIGNAL(clicked()),this,SLOT(Tab1MyLabelDoubleClicked()));
    //connect(BackImgLabel,SIGNAL(clicked()),this,SLOT(Tab1MyLabelDoubleClicked()));
    MainImgWidget = new MyTwoImgLabel(Widget1);

    DMap = new MyDynamicMap(Widget3);
    connect(SI_Reader,SIGNAL(StatusReady(double,double,double,double,double,double,double,double))
            ,DMap,SLOT(Flush(double,double,double,double,double,double,double,double)));
    this->MainTabWidget->addTab(Widget1,tr("Real-time Info"));
    this->MainTabWidget->addTab(Widget2,tr("Log && Mission"));
    this->MainTabWidget->addTab(Widget3,tr("Count Info"));
}
/*
void MainWindow::Tab1MyLabelDoubleClicked()
{
    if(sender() == FrontImgLabel)
    {
        //BackImgLabel->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");
        if(!(BackImgLabel->isHidden()))
        {
            BackImgLabel->close();
        }else BackImgLabel->show();
    }
    if(sender() == BackImgLabel)
    {
        //FrontImgLabel->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");
        if(!(FrontImgLabel->isHidden()))
        {
            FrontImgLabel->close();
        }else FrontImgLabel->show();
    }
}
*/
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        tempoint = event->pos();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        int ss = MainTabWidget->currentIndex();
        if(tempoint.x() - event->pos().x() >= 50)
        {
            //qDebug()<<"left";
            if(ss<2)
            {
                MainTabWidget->setCurrentIndex(++ss);
            }
        }
        else if(event->pos().x() == tempoint.x())
        {

        }
        else if(event->pos().x() - tempoint.x() >= 50 )
        {
            //qDebug()<<"right";
            if(ss>0)
            {
                MainTabWidget->setCurrentIndex(--ss);
            }
        }
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}
MainWindow::~MainWindow()
{
    delete ui;
}
