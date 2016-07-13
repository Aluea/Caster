#include "mainwindow.h"
#include <QDebug>
#include "ui_mainwindow.h"
#define ti 5
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),dq(0),tfang(0),jip(false),tdf(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tu[0]=new QPixmap(":/A1");
   tu[1]=new QPixmap(":/A2");
   tu[2]=new QPixmap(":/A3");
   tu[3]=new QPixmap(":/A4");
   tu_peo_left=new QPixmap(":/r_l");
   tuq[0]=new QRect(0,0,800,250);
   tuq[1]=new QRect(800,0,800,250);
   tuq[2]=new QRect(0,0,800,250);
   tuq[3]=new QRect(0,0,800,250);

    jishi =new QTimer(this);
     connect( jishi,SIGNAL(timeout()),this,SLOT(yidong()));


   tuq_peo=new QRect(300,175,50,75);

}
void MainWindow::paintEvent (QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(*tuq[dq],*tu[dq]);
    painter.drawPixmap(*tuq[dq+1],*tu[dq+1]);
    painter.drawPixmap(*tuq_peo,*tu_peo_left);
}
void MainWindow::keyPressEvent( QKeyEvent *event){
    char ch;
    ch=event->key();
      switch(ch){
      case 'a':
      case 'A':if(jip==false){
              tfang=-1;
              jishi->start(ti);
              jip=true;
          }break;
      case 'W':
      case 'w':rfang=0;break;
      case 'd':
      case 'D':if(jip==false){
              tfang=1;
              jishi->start(ti);
              jip=true;
          }break;

      }



}
 void MainWindow::keyReleaseEvent( QKeyEvent *event){
     if(event->isAutoRepeat()==false){
         if(event->key()=='A'||event->key()=='a'||event->key()=='d'||event->key()=='D'){
  qDebug("%c\n",event->key());
    jishi->stop();
    tfang=0;
    jip=false;
         }
     }
}

void MainWindow::yidong(){


    int bu=5;//每键位移量

    int width1,height1;
    int width = tuq[dq]->width ();
    int height=tuq[dq]->height();
    if(dq<4){ width1 = tuq[dq+1]->width ();
     height1=tuq[dq+1]->height();}

    switch(tfang){
    case -1:tuq[dq]->setX(tuq[dq]->x()+2);tuq[dq+1]->setX(tuq[dq+1]->x()+2);break;
    case 1:tuq[dq]->setX(tuq[dq]->x()-2);tuq[dq+1]->setX(tuq[dq+1]->x()-2);break;


    }

    if(tfang==-1){
        if(tuq[dq]->x()>=0&&dq>0){
            dq--;
            tuq[dq]->setX(-796);
            //~
        }
    }
    if(tfang==1){
        if(tuq[dq]->x()+800<=0&&dq<4){
            dq++;
            tuq[dq+1]->setX(796);
        }
    }
    tuq[dq]->setWidth (width);
     tuq[dq]->setHeight(height);
    if(dq<4){ tuq[dq+1]->setWidth (width1);
      tuq[dq+1]->setHeight(height1);}
    move_peo();
    update();
}

void MainWindow::move_peo(){
    int width=tu_peo_left->width();
    int height=tu_peo_left->height();
    if(rfang==1){

    }else if(rfang==-1){

    }else if(rfang==0){

    }
    tuq_peo->setX(400);
    tuq_peo->setWidth(width);
    tuq_peo->setHeight(height);
    //update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
