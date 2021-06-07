#include <QLabel>

class MyLabel:public QLabel
{
    Q_OBJECT    //important!
public:
    MyLabel(QWidget *parent);

public slots:   //important!
    void setTextMajuscules(QString s);
};
