// MyGLWidget.h
#include "LL4GLWidget.h"

class MyGLWidget : public LL4GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL4GLWidget(parent) {}
    ~MyGLWidget();

  public slots:
    void rotateCarLeft();
    void rotateCarRight();

  private:
    //initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    void initializeGL( );
    int printOglError(const char file[], int line, const char func[]);
    virtual void keyPressEvent (QKeyEvent *);

    //glm::vec3 posFocusF[3];
    GLuint isDefaultFocusLoc, posFocusFLoc,colFocusFLoc;

    int isDefaultFocus;
};
