// MyGLWidget.h
#include "BL2GLWidget.h"
#include "Model.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    
    virtual void carregaShaders();
    
    virtual void creaBuffers ();
    
    virtual void keyPressEvent (QKeyEvent *event);
    
    virtual void resizeGL (int width, int height);
    
  private:
    int printOglError(const char file[], int line, const char func[]);
    
    void projectTransform(float FOV, float ra, float znear, float zfar);
    void viewTransform();
    void ini_camera();
    void modelTransform ();
    void floorTransform();
    void calculateAttributes();
    
    GLuint projLoc;
    GLuint viewLoc;
    
    GLuint VAO_Homer, VAO_Floor;
    
    Model m;
    
    glm::vec3 OBS,VRP,up, Pmin, Pmax;
    float FOV,ra,znear,zfar, rotate,  distance,radi;
};
