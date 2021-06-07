#include <QLabel>

class MyLabel:public QLabel
{
    Q_OBJECT    //important!
public:
    MyLabel(QWidget *parent);
    //bool checked = false;
    int recaudation = 0;
    int cars = 0;
    int motorcycles = 0;
    int trucks = 0;

public slots:   //important!
    void changeSemaphoreStatus(bool open);
    
    void updateRecaudationCarMC();
    void updateRecaudationTruck();
    void updateCar();
    void updateMC();
    void updateTruck();
};
