#include <QLCDNumber>

class MyLCDNumber:public QLCDNumber
{
    Q_OBJECT    //important!
public:
    MyLCDNumber(QWidget *parent);

    int units = 0;
    int tens = 0;


public slots:   //important!
    void incValue();
    void reset();

};
