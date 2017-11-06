#include "dialog.h"
#include <QApplication>
#include <QApplication>
#include <QString>
#include <QTimer>
#include <QPalette>
#include <QBrush>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    //w.setStyleSheet("background-image: ./Users/xogoss/Desktop/EC535PocketMole/frame.jpg");

    w.setWindowTitle("whack-a-mole     time：30       score：0");
    w.setFixedSize(480,240);
    w.show();

    return a.exec();
}
