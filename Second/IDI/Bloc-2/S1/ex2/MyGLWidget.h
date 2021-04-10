// MyGLWidget.h
#include "BL2GLWidget.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    virtual void carregaShaders();
    
  private:
    int printOglError(const char file[], int line, const char func[]);
    
    void projectTransform();
    void viewTransform();
    void ini_camera();
    
    GLuint projLoc;
    GLuint viewLoc;
    
    glm::vec3 OBS,VRP,up;
    float FOV,ra,znear,zfar;
};
