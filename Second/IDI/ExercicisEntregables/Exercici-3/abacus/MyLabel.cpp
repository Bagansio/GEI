#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)
{
  value = 0;
}


void MyLabel::incValue(){
    value = ! value;
    QString rgb = "255,255,0"; //yellow = 1

    if(! value){ //carry = 0
        emit sendCarry();
        rgb = "0,255,0"; //green = 0
    }
    setStyleSheet("background-color: rgba(" + rgb + ");");
    setText(QString("%1").arg(value));
}

void MyLabel::reset(){
  value = 0;
  setStyleSheet("background-color: rgba(0,255,0);"); //green
  setText(QString("%1").arg(value));
}
