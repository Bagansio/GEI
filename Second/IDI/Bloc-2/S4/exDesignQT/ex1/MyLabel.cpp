#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)
{
}


void MyLabel::changeSemaphoreStatus(bool open){
    QString rgb = "255,0,0";    //close red
    if(open) rgb = "0,255,0";   //open green
    
    setStyleSheet("background-color: rgba(" + rgb + ");");
}


void MyLabel::updateRecaudationCarMC(){
    ++recaudation;
    setText(QString("Total money: %1").arg(recaudation));
}

void MyLabel::updateRecaudationTruck(){
    recaudation += 4;
    setText(QString("Total money: %1").arg(recaudation));
}

void MyLabel::updateCar(){
    ++cars;
    setText(QString("Cars: %1").arg(cars));
}


void MyLabel::updateTruck(){
    ++trucks;
    setText(QString("Trucks: %1").arg(trucks));
}


void MyLabel::updateMC(){
    ++motorcycles;
    setText(QString("Motorcycles: %1").arg(motorcycles));
}


