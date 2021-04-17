#include "LL2GLWidget.h"

#include "model.h"

class MyGLWidget : public LL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL2GLWidget(parent) {}
    ~MyGLWidget();

  private:
    int printOglError(const char file[], int line, const char func[]);
    void paintGL();
    void iniCamera();
    void projectTransform ();
    void viewTransform ();
    void keyPressEvent (QKeyEvent *event);
    
    void changeCamera();
    void moveHomer(int i);
    void resizeGL (int width, int height);
    void restart();
    
    bool isPerspective;
    float fov,fovini, ra, znear, zfar, distance, radius , raw, rav; //Theta
    glm::vec3 Pmin,Pmax;
};
