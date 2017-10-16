#include "status_info_reader.h"
#include <time.h>
Status_Info_Reader::Status_Info_Reader(QObject *parent) : QObject(parent)
{
    srand((unsigned)time(NULL));
    //FrontImg = new QImage();
    //BackImg = new QImage();
    ChipTem=0;
    BoardTem=0;
    Engine0Tem=0;
    Engine1Tem=0;
    Engine2Tem=0;
    Engine3Tem=0;
    EnviTem=0;
    load=0;

    //TimerId_FrontImg=this->startTimer(20);
    //TimerId_BackImg=this->startTimer(20);
    TimerId_Status=this->startTimer(1000);
}

void Status_Info_Reader::timerEvent(QTimerEvent *event)
{
    /*
    if (event->timerId() == TimerId_BackImg)
    {

    }
    if (event->timerId() == TimerId_FrontImg)
    {

    }
    */
    if (event->timerId() == TimerId_Status)
    {
        GetStatus();
        emit StatusReady(ChipTem,
                BoardTem,
                Engine0Tem,
                Engine1Tem,
                Engine2Tem,
                Engine3Tem,
                EnviTem,
                load);
    }
}
bool Status_Info_Reader::GetFrontImg()
{
    return true;
}
bool Status_Info_Reader::GetBackImg()
{
    return true;
}
bool Status_Info_Reader::GetStatus()
{
    //----get Status
    double Tem1 = (rand()%180+100);
    double Tem2 = (rand()%100+70);
    double Tem3 = (rand()%130+90);
    double Tem4 = (rand()%80+30);
    double Tem5 = (rand()%50+10);
    double Tem6 = (rand()%30-10);
    double Tem7 = (rand()%10-30);
    double Tem8 = (rand()%5-30);
    this->ChipTem = Tem1;
    this->BoardTem = Tem2;
    this->Engine0Tem = Tem3;
    this->Engine1Tem = Tem4;
    this->Engine2Tem = Tem5;
    this->Engine3Tem = Tem6;
    this->EnviTem = Tem7;
    this->load = Tem8;
    //----
    return true;
}
