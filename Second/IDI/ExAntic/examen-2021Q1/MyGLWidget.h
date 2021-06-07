#include "ExamGLWidget.h"

class MyGLWidget:public ExamGLWidget
{
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : ExamGLWidget(parent) {}
    ~MyGLWidget();

  public slots:
    void changeToPerspective();
    void changeToOrtho();
    void changeCamera(QString text);
    
    void changePos(int pos);
    
    
  signals:
      void sendText(QString text);
      
  protected:
    virtual void paintGL ();
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void modelTransformCub (float escala, float angle);
    virtual void modelTransformPatricio ();
    virtual void projectTransform ();
    virtual void viewTransform ();

  private:
    int printOglError(const char file[], int line, const char func[]);


    bool paintPatricio = false;
    bool isColFocusWhite = true;
    float angleP = 0;
    float angleAux = 0;

};
