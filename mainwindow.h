#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "myqlabel.h"
//#include "qcustomplot.h"
#include "mydynamicmap.h"
#include "status_info_reader.h"
#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QVector>
#include "mytwoimglabel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    //---------tem
    QPoint tempoint;

    //---------
    Ui::MainWindow *ui;
    QTabWidget *MainTabWidget;
    QWidget *Widget1;
    QWidget *Widget2;
    QWidget *Widget3;

    //QLabel *FrontImgTitleLabel;
    //MyQlabel *FrontImgLabel;
    //QLabel *BackImgTitleLabel;
    //MyQlabel *BackImgLabel;

    MyTwoImgLabel *MainImgWidget;

    QLabel *EnviTemTitleLabel;
    QLabel *EnviTemValueLabel;
    QLabel *HumilityTitleLabel;
    QLabel *HumilityValueLabel;
    QLabel *IntensityOfLightTitleLabel;
    QLabel *IntensityOfLightValueLabel;
    QLabel *EngineTemTitleLabel;
    QLabel *EngineTemValueLabel0;
    QLabel *EngineTemValueLabel1;
    QLabel *EngineTemValueLabel2;
    QLabel *EngineTemValueLabel3;
    QLabel *ChipTemTitleLabel;
    QLabel *ChipTemValueLabel;
    QLabel *BoardTemTitleLabel;
    QLabel *BoardTemValueLabel;

    MyDynamicMap *DMap;

    Status_Info_Reader *SI_Reader;

    //QCustomPlot *MainCustomPlot;

    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
public slots:
    //void Tab1MyLabelDoubleClicked();

};

#endif // MAINWINDOW_H
