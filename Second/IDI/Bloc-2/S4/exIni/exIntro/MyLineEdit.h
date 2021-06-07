#include <QLineEdit>

class MyLineEdit:public QLineEdit
{
    Q_OBJECT    //important!
public:
    MyLineEdit(QWidget *parent);

public slots:   //important!
    void tractaReturn();
    
signals:
    void enviaText(const QString &s);
};
