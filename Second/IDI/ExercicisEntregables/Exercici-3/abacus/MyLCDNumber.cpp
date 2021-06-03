#include "MyLCDNumber.h"

MyLCDNumber::MyLCDNumber(QWidget *parent=0):QLCDNumber(parent)
{
	tens = units = 0;
}

void MyLCDNumber::incValue(){
  //units = (++units)%8;  //warning por undefined
  units = (units + 1)%8;  

  if(units == 0)
    tens = (tens+1)%8;

  int res = units + tens*10;
  display(res);
}

void MyLCDNumber::reset(){
  tens = units = 0;
  display(0);
}
