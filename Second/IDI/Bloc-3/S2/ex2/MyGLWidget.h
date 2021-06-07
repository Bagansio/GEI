// MyGLWidget.h
#include "BL3GLWidget.h"

class MyGLWidget : public BL3GLWidget {
  Q_OBJECT
  public:
    MyGLWidget(QWidget *parent=0) : BL3GLWidget(parent) {}
    ~MyGLWidget();
  protected:
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent* event);

    void iniLight();
    virtual void iniMaterialTerra();
    virtual void initializeGL ();
    virtual void paintGL ( );

    //uniform light
    GLuint posFocusLoc, colFocusLoc, llumAmbientLoc, normalMatrixLoc;

    glm::vec3 colFocus, posFocus, llumAmbient;
    glm::mat3 normalMatrix;
  private:
    int printOglError(const char file[], int line, const char func[]);
};
