// MyGLWidget.h
#include "BL2GLWidget.h"
#include <QMouseEvent>
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
    
    
    virtual void mouseMoveEvent (QMouseEvent *event);
    
    virtual void resizeGL (int width, int height);
    
  private:
    int printOglError(const char file[], int line, const char func[]);
    
    void projectTransform();
    void viewTransform();
    void ini_camera();
    void modelTransform ();
    void floorTransform();
    void calculateAttributes();
    
    void calculateModelBox();
    void calculateSceneBox();
    void calculateSceneCenter();
    
    GLuint projLoc;
    GLuint viewLoc;
    
    GLuint VAO_Patricio, VAO_Floor;
    
    Model m;
    bool isPerspective;
    glm::vec3 OBS,VRP,up, Pmin, Pmax, modelCenter;
    
    float FOV,FOVini,ra,znear,zfar, rotate,  distance,radi, modelScale, rav, theta, psi;
    
    //mouse 
    int posX, posY;
    float delta;
};
