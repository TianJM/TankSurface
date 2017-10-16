#ifndef MYDYNAMICMAP_H
#define MYDYNAMICMAP_H

//#include <QObject>
#include <QWidget>
#include "qcustomplot.h"
#include <QLabel>
#include <QVector>
#include <QCheckBox>
#include <QTimerEvent>
class MyDynamicMap : public QWidget
{
    Q_OBJECT
private:
    QVector<double> EnviTemV,ChipTemV,BoardTemV,Engine0TemV,Engine1TemV,Engine2TemV,Engine3TemV,Load;
    QVector<double> X;
    QCheckBox *ChipTemBox;
    QCheckBox *BoardTemBox;
    QCheckBox *Engine0TemBox;
    QCheckBox *Engine1TemBox;
    QCheckBox *Engine2TemBox;
    QCheckBox *Engine3TemBox;
    QCheckBox *EnviTemBox;
    QCheckBox *LoadBox;
    virtual void timerEvent(QTimerEvent *event);
public:
    void UpdateVector(double NowTem,int flag);
    explicit MyDynamicMap(QWidget *parent = nullptr);
    QLabel *Title;
    QCustomPlot *DynamicMap;
    void ShowValue();
signals:

public slots:
    void SShowValue();
    void Flush(double ChipTemS,
    double BoardTemS,
    double Engine0TemS,
    double Engine1TemS,
    double Engine2TemS,
    double Engine3TemS,
    double EnviTemS,
    double loadS);
};

#endif // MYDYNAMICMAP_H
