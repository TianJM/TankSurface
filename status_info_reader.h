#ifndef STATUS_INFO_READER_H
#define STATUS_INFO_READER_H

#include <QObject>
#include <QTimerEvent>
class Status_Info_Reader : public QObject
{
    Q_OBJECT
private:
    int TimerId_FrontImg;
    int TimerId_BackImg;
    int TimerId_Status;
    bool GetFrontImg();
    bool GetBackImg();
    bool GetStatus();
    void timerEvent(QTimerEvent *event);
public:
    //----
    QImage *FrontImg;
    QImage *BackImg;
    //----
    double ChipTem;
    double BoardTem;
    double Engine0Tem;
    double Engine1Tem;
    double Engine2Tem;
    double Engine3Tem;
    double EnviTem;
    double load;
    //double TemList[8];
    //----
public:
    explicit Status_Info_Reader(QObject *parent = nullptr);
signals:
    void FrontImgReady();
    void BackImgReady();
    void StatusReady(double,double,double,double,double,double,double,double);
public slots:

};

#endif // STATUS_INFO_READER_H
