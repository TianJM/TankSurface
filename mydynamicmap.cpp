#include "mydynamicmap.h"
#include <time.h>
#include <QDebug>
MyDynamicMap::MyDynamicMap(QWidget *parent) : QWidget(parent)
{
    //srand((unsigned)time(NULL));
    Title = new QLabel(this);
    DynamicMap = new QCustomPlot(this);
    DynamicMap->move(0,12);
    DynamicMap->resize(1280,600);
    this->resize(1280,800);

    ChipTemBox = new QCheckBox(this);
    BoardTemBox = new QCheckBox(this);
    Engine0TemBox = new QCheckBox(this);
    Engine1TemBox = new QCheckBox(this);
    Engine2TemBox = new QCheckBox(this);
    Engine3TemBox = new QCheckBox(this);
    EnviTemBox = new QCheckBox(this);
    LoadBox = new QCheckBox(this);
    ChipTemBox->resize(120,40);
    ChipTemBox->move(40,670);
    ChipTemBox->setText("ChipTem");
    ChipTemBox->setChecked(true);
    BoardTemBox->resize(120,40);
    BoardTemBox->move(180,670);
    BoardTemBox->setText("BoardTem");
    Engine0TemBox->resize(120,40);
    Engine0TemBox->move(340,670);
    Engine0TemBox->setText("Engine0Tem");
    Engine1TemBox->resize(120,40);
    Engine1TemBox->move(500,670);
    Engine1TemBox->setText("Engine1Tem");
    Engine2TemBox->resize(120,40);
    Engine2TemBox->move(660,670);
    Engine2TemBox->setText("Engine2Tem");
    Engine3TemBox->resize(120,40);
    Engine3TemBox->move(820,670);
    Engine3TemBox->setText("Engine3Tem");
    EnviTemBox->resize(120,40);
    EnviTemBox->move(980,670);
    EnviTemBox->setText("EnviTem");
    LoadBox->resize(120,40);
    LoadBox->move(1160,670);
    LoadBox->setText("Load(%)");
    /*
    ChipTemBox->resize(67.5,40);
    ChipTemBox->move(10,510);
    ChipTemBox->setText("ChipTem");
    ChipTemBox->setChecked(true);
    BoardTemBox->resize(67.5,40);
    BoardTemBox->move(97.5,510);
    BoardTemBox->setText("BoardTem");
    Engine0TemBox->resize(67.5,40);
    Engine0TemBox->move(185,510);
    Engine0TemBox->setText("Engine0Tem");
    Engine1TemBox->resize(67.5,40);
    Engine1TemBox->move(272.5,510);
    Engine1TemBox->setText("Engine1Tem");
    Engine2TemBox->resize(67.5,40);
    Engine2TemBox->move(360,510);
    Engine2TemBox->setText("Engine2Tem");
    Engine3TemBox->resize(67.5,40);
    Engine3TemBox->move(447.5,510);
    Engine3TemBox->setText("Engine3Tem");
    EnviTemBox->resize(67.5,40);
    EnviTemBox->move(535,510);
    EnviTemBox->setText("EnviTem");
    LoadBox->resize(67.5,40);
    LoadBox->move(622.5,510);
    LoadBox->setText("Load(%)");
    */
    Title->setText("Count History");
    DynamicMap->xAxis->setRange(-180,25);
    DynamicMap->yAxis->setRange(-30,250);
    DynamicMap->xAxis->setLabel("Time(s)");
    DynamicMap->yAxis->setLabel("Temperture(℃)/Load(%)");
    DynamicMap->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                         QCP::iSelectLegend | QCP::iSelectPlottables);

    DynamicMap->addGraph()->setName("ChipTem");//0
    DynamicMap->addGraph()->setName("BoardTem");//1
    DynamicMap->addGraph()->setName("Engine0Tem");//2
    DynamicMap->addGraph()->setName("Engine1Tem");//3
    DynamicMap->addGraph()->setName("Engine2Tem");//4
    DynamicMap->addGraph()->setName("Engine3Tem");//5
    DynamicMap->addGraph()->setName("EnviTem");//6
    DynamicMap->addGraph()->setName("Load");//6
    DynamicMap->graph(0)->setPen(QPen(Qt::red));
    DynamicMap->graph(1)->setPen(QPen(Qt::yellow));
    DynamicMap->graph(2)->setPen(QPen(Qt::blue));
    DynamicMap->graph(3)->setPen(QPen(Qt::green));
    DynamicMap->graph(4)->setPen(QPen(Qt::black));
    DynamicMap->graph(5)->setPen(QPen(QColor(120,44,8)));
    DynamicMap->graph(6)->setPen(QPen(QColor(33,77,199)));
    DynamicMap->graph(7)->setPen(QPen(QColor(255,77,199)));
    DynamicMap->legend->setVisible(true);
    DynamicMap->legend->setFont(QFont("Helvetica",9));
    //DynamicMap->graph(0)->setVisible(false);
    //DynamicMap->graph(0)->setVisible(true);
    //---init QVector
    for(int ss =0;ss <=600;ss++)
    {
        ChipTemV.append(0);
        BoardTemV.append(0);
        Engine0TemV.append(0);
        Engine1TemV.append(0);
        Engine2TemV.append(0);
        Engine3TemV.append(0);
        EnviTemV.append(0);
        Load.append(0);
    }
    for(int ss =0;ss <=600;ss++)
    {
        X.append(ss-600);
    }
    this->startTimer(300);
}
void MyDynamicMap::UpdateVector(double NowTem,int flag)
{
    if(flag == 0)
    {
        ChipTemV.erase(ChipTemV.begin());
        ChipTemV.append(NowTem);
    }
    if(flag == 1)
    {
        BoardTemV.erase(BoardTemV.begin());
        BoardTemV.append(NowTem);
    }
    if(flag == 2)
    {
        Engine0TemV.erase(Engine0TemV.begin());
        Engine0TemV.append(NowTem);
    }
    if(flag == 3)
    {
        Engine1TemV.erase(Engine1TemV.begin());
        Engine1TemV.append(NowTem);
    }
    if(flag == 4)
    {
        Engine2TemV.erase(Engine2TemV.begin());
        Engine2TemV.append(NowTem);
    }
    if(flag == 5)
    {
        Engine3TemV.erase(Engine3TemV.begin());
        Engine3TemV.append(NowTem);
    }
    if(flag == 6)
    {
        EnviTemV.erase(EnviTemV.begin());
        EnviTemV.append(NowTem);
    }
    if(flag == 7)
    {
        Load.erase(Load.begin());
        Load.append(NowTem);
    }
}
void MyDynamicMap::ShowValue()
{
    DynamicMap->graph(0)->setData(X,ChipTemV);
    DynamicMap->graph(1)->setData(X,BoardTemV);
    DynamicMap->graph(2)->setData(X,Engine0TemV);
    DynamicMap->graph(3)->setData(X,Engine1TemV);
    DynamicMap->graph(4)->setData(X,Engine2TemV);
    DynamicMap->graph(5)->setData(X,Engine3TemV);
    DynamicMap->graph(6)->setData(X,EnviTemV);
    DynamicMap->graph(7)->setData(X,Load);
}
void MyDynamicMap::SShowValue()
{
    DynamicMap->replot();
    double Tem1 = (rand()%180+100);
    double Tem2 = (rand()%100+70);
    double Tem3 = (rand()%130+90);
    double Tem4 = (rand()%80+30);
    double Tem5 = (rand()%50+10);
    double Tem6 = (rand()%30-10);
    double Tem7 = (rand()%10-30);
    double Tem8 = (rand()%5-30);
    //qDebug()<<ChipTemss;
    UpdateVector(Tem1,0);
    UpdateVector(Tem2,1);
    UpdateVector(Tem3,2);
    UpdateVector(Tem4,3);
    UpdateVector(Tem5,4);
    UpdateVector(Tem6,5);
    UpdateVector(Tem7,6);
    UpdateVector(Tem8,7);
    ShowValue();
}
void MyDynamicMap::Flush(double ChipTemS,
                         double BoardTemS,
                         double Engine0TemS,
                         double Engine1TemS,
                         double Engine2TemS,
                         double Engine3TemS,
                         double EnviTemS,
                         double loadS)
{
    DynamicMap->replot();
    UpdateVector(ChipTemS,0);
    UpdateVector(BoardTemS,1);
    UpdateVector(Engine0TemS,2);
    UpdateVector(Engine1TemS,3);
    UpdateVector(Engine2TemS,4);
    UpdateVector(Engine3TemS,5);
    UpdateVector(EnviTemS,6);
    UpdateVector(loadS,7);
    ShowValue();
}
void MyDynamicMap::timerEvent(QTimerEvent *event)
{
    if(ChipTemBox->isChecked())
    {
        DynamicMap->graph(0)->setVisible(true);
    }else DynamicMap->graph(0)->setVisible(false);
    if(BoardTemBox->isChecked())
    {
        DynamicMap->graph(1)->setVisible(true);
    }else DynamicMap->graph(1)->setVisible(false);
    if(Engine0TemBox->isChecked())
    {
        DynamicMap->graph(2)->setVisible(true);
    }else DynamicMap->graph(2)->setVisible(false);
    if(Engine1TemBox->isChecked())
    {
        DynamicMap->graph(3)->setVisible(true);
    }else DynamicMap->graph(3)->setVisible(false);
    if(Engine2TemBox->isChecked())
    {
        DynamicMap->graph(4)->setVisible(true);
    }else DynamicMap->graph(4)->setVisible(false);
    if(Engine3TemBox->isChecked())
    {
        DynamicMap->graph(5)->setVisible(true);
    }else DynamicMap->graph(5)->setVisible(false);
    if(EnviTemBox->isChecked())
    {
        DynamicMap->graph(6)->setVisible(true);
    }else DynamicMap->graph(6)->setVisible(false);
    if(LoadBox->isChecked())
    {
        DynamicMap->graph(7)->setVisible(true);
    }else DynamicMap->graph(7)->setVisible(false);
}
