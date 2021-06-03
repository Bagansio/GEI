#include <QLabel>

class MyLabel:public QLabel
{
    Q_OBJECT    //important!
public:
    MyLabel(QWidget *parent);

    bool value = 0;


public slots:   //important!
    void incValue();
    void reset();

signals:
    void sendCarry();
};
