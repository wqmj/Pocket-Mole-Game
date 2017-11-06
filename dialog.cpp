#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QImage>
#include <QPixmap>
#include <QRgb>
#include <QPushButton>
#include <QSize>
#include <Qlabel>
#include <QtGlobal>
#include <Qdebug>
#include <QTimer>
#include <QFont>
#include <QPixmap>



static int score = 0;
static int position_x[18] = {25,100,175,250,315,385,25,100,175,250,315,385,25,100,175,250,315,385};
static int position_y[9] = {55,100,155,55,100,155,55,100,155};
static int end_flag = 0;
static int remainT = 30;
static int hit = 0;
static int pic = 0;
static int aaa = 0;

QTimer *run = new QTimer();
QTimer *miss = new QTimer();


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //scene = new QGraphicsScene(this);
    //ui ->graphicsView ->setScene(scene);

    QPixmap pix = QPixmap("/Users/xogoss/Desktop/535projectnew/untitled/frame.jpg");
    pix = pix.scaled(480,240);
    QPalette palette;
    palette.setBrush(QPalette::Background,pix);
    this->setPalette(palette);

    mybutton = new QPushButton(this);
    gameover = new QPushButton(this);
    over = new QLabel(this);
    choose = new QLabel(this);
    //run ->singleShot(1000,this,SLOT(TimeCount()));
    choosepic();
    //showButton();
    connect(mybutton, SIGNAL (released()), this, SLOT (handleButton()));
    connect(gameover, SIGNAL (released()), this, SLOT (again()));

    gameover->hide();
    over ->hide();

}

void Dialog::choosepic(){

    QString ha = "Please choose a mole";
    choose -> setText(ha);
    //choose -> setFont(font);
    choose -> setAutoFillBackground(Qt::red);
    choose ->setGeometry(170,50,130,20);
    choose ->show();
    mybutton->setVisible(false);
    //qDebug() << aaa;
    if(aaa == 0){
        pic = 0;
        pic1 = new QPushButton(this);
        pic2 = new QPushButton(this);
        pic3 = new QPushButton(this);
        QPixmap mole1("/Users/xogoss/Desktop/EC535PocketMole/mole1.png");
        QPixmap mole2("/Users/xogoss/Desktop/EC535PocketMole/mole.png");
        QPixmap mole3("/Users/xogoss/Desktop/EC535PocketMole/afterduang.png");
        QIcon ButtonIcon1(mole1);
        QIcon ButtonIcon2(mole2);
        QIcon ButtonIcon3(mole3);
        pic1 -> setIcon(ButtonIcon1);
        pic2 -> setIcon(ButtonIcon2);
        pic3 -> setIcon(ButtonIcon3);
        pic1 -> setIconSize(QSize(50,50));
        pic2 -> setIconSize(QSize(50,50));
        pic3 -> setIconSize(QSize(50,50));
        pic1 -> setGeometry(100,100,50,50);
        pic2 -> setGeometry(200,100,50,50);
        pic3 -> setGeometry(300,100,50,50);
        connect(pic1, SIGNAL (released()), this, SLOT (pict1()));
        connect(pic2, SIGNAL (released()), this, SLOT (pict2()));
        connect(pic3, SIGNAL (released()), this, SLOT (pict3()));
    }
    else{
        pic1 -> setVisible(true);
        pic2 -> setVisible(true);
        pic3 -> setVisible(true);
    }

}

void Dialog::pict1(){
    pic = 1;
    pic1 ->setVisible(false);
    pic2 ->setVisible(false);
    pic3 ->setVisible(false);
    run ->singleShot(1000,this,SLOT(TimeCount()));
    choose->hide();
    showButton();
}

void Dialog::pict2(){
    pic = 2;
    pic1 ->setVisible(false);
    pic2 ->setVisible(false);
    pic3 ->setVisible(false);
    run ->singleShot(1000,this,SLOT(TimeCount()));
    choose->hide();
    showButton();
}

void Dialog::pict3(){
    pic = 3;
    pic1 ->setVisible(false);
    pic2 ->setVisible(false);
    pic3 ->setVisible(false);
    run ->singleShot(1000,this,SLOT(TimeCount()));
    choose->hide();
    showButton();
}

void Dialog::showButton(){
    //ui->setPalette(palette);
    mybutton ->setVisible(true);
    if(end_flag == 0){

        hit = 0;
        int x = qrand()%18;
        int y = qrand()%9;

        if(pic == 1){
            QPixmap mole("/Users/xogoss/Desktop/EC535PocketMole/mole1.png");
            QIcon ButtonIcon(mole);
            mybutton -> setIcon(ButtonIcon);
            mybutton -> setIconSize(QSize(50,50));
            mybutton -> setGeometry(position_x[x],position_y[y],50,50);
            mybutton ->setFlat(true);
            //mybutton ->setAutoFillBackground(false);
        }
        else if(pic == 2){
            QPixmap mole("/Users/xogoss/Desktop/EC535PocketMole/mole.png");
            QIcon ButtonIcon(mole);
            mybutton -> setIcon(ButtonIcon);
            mybutton -> setIconSize(QSize(50,50));
            mybutton -> setGeometry(position_x[x],position_y[y],50,50);
            mybutton ->setFlat(true);
        }
        else if(pic == 3){
            QPixmap mole("/Users/xogoss/Desktop/EC535PocketMole/afterduang.png");
            QIcon ButtonIcon(mole);
            mybutton -> setIcon(ButtonIcon);
            mybutton -> setIconSize(QSize(50,50));
            mybutton -> setGeometry(position_x[x],position_y[y],50,50);
            mybutton ->setFlat(true);
        }

        QCursor cursor;
        QPixmap pixmap("/Users/xogoss/Desktop/EC535PocketMole/hammer.png");
        QPixmap scaled = pixmap.scaled(QSize(37,31));
        cursor=QCursor(scaled,-1,-1);
        setCursor(cursor);

        //miss->singleShot(1000,this,SLOT(missmole()));
    }

}
void Dialog::TimeCount(){
    if (remainT>0){
        remainT--;
        run->singleShot(1000,this,SLOT(TimeCount()));
        setWindowTitle("whack-a-mole     time："+QString::number(remainT)+"        score:"+QString::number(score)+"");
    }

    else{
        mybutton ->setVisible(false);
        QFont font = this->gameover->font();
        font.setPointSize(8);
        gameover ->setText("AGAIN!");
        gameover ->setFont(font);
        gameover ->setGeometry(200,150,75,25);
        gameover ->show();

        QString end = "         Game Over\n \n    Your Score is:   ";
        over -> setText(end + QString::number(score));
        over -> setFont(font);
        over -> setAutoFillBackground(true);
        over ->setGeometry(190,100,90,50);
        over->show();

        end_flag = 1;
    }
}


void Dialog::handleButton(){
    hit = 1;
    score++;
    //interval = interval-1;
    if(pic == 1){
        QPixmap mole("/Users/xogoss/Desktop/EC535PocketMole/afterduang.png");
        QIcon ButtonIcon(mole);
        mybutton -> setIcon(ButtonIcon);
        mybutton -> setIconSize(QSize(50,50));
    }
    else if(pic == 2){
        QPixmap mole("/Users/xogoss/Desktop/EC535PocketMole/afterduang.png");
        QIcon ButtonIcon(mole);
        mybutton -> setIcon(ButtonIcon);
        mybutton -> setIconSize(QSize(50,50));
    }
    else if(pic == 3){
        QPixmap mole("/Users/xogoss/Desktop/EC535PocketMole/afterduang.png");
        QIcon ButtonIcon(mole);
        mybutton -> setIcon(ButtonIcon);
        mybutton -> setIconSize(QSize(50,50));
    }
    QTimer::singleShot(800,this,SLOT(showButton()));
}
/*
void Dialog::missmole(){
    //score--;
    //qDebug()<<hit;
    if(hit == 0 && remainT > 0)
        showButton();
    else
        hit = 0;
}
*/

void Dialog::again(){
    gameover->hide();
    over ->hide();
     end_flag = 0;
     remainT = 30;
     score = 0;
     //run->singleShot(1000,this,SLOT(TimeCount()));

     aaa = 1;
     choosepic();
}
Dialog::~Dialog()
{
    delete ui;
}
