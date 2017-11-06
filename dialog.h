#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
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


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

private:
   QPushButton *mybutton;
   QPushButton *gameover;
   QPushButton *pic1;
   QPushButton *pic2;
   QPushButton *pic3;
   QTimer *timer;
   QTimer *miss;
   QLabel *over;
   QLabel *choose;
private slots:
   void handleButton();
   void showButton();
   void TimeCount();
   void again();
   //void missmole();
   void pict1();
   void pict2();
   void pict3();
   void choosepic();

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
};

#endif // DIALOG_H
