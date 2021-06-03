// MyGLWidget.cpp

#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;



void MyGLWidget::rotateCarLeft(){
  makeCurrent();
  angleCotxe -= float(M_PI)/4;
  update();
};

void MyGLWidget::rotateCarRight(){
  makeCurrent();
  angleCotxe += float(M_PI)/4;
  update();
}

// initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
void MyGLWidget::initializeGL( ){
  LL4GLWidget::initializeGL();

  posFocusFLoc = glGetUniformLocation (program->programId(), "posFocusF");
  glm::vec3 posFocusF[3] = {
    glm::vec3(-3.5, 10.0, -3.5),glm::vec3(3.5, 10.0, -3.5),glm::vec3(3.5, 10.0, 3.5)
  };
  glUniform3fv(posFocusFLoc,3,&posFocusF[0].x);


  colFocusFLoc = glGetUniformLocation (program->programId(), "colFocusF");
  glm::vec3 colFocusF[3] = {
    glm::vec3(0.9, 0.2, 0.2),glm::vec3(0.0, 1.0, 0.0),glm::vec3(0.2, 0.2, 0.9)
  };
  glUniform3fv(colFocusFLoc,3,&colFocusF[0].x);

  isDefaultFocusLoc  = glGetUniformLocation (program->programId(), "isDefaultFocus");
  isDefaultFocus = 1;
  glUniform1i(isDefaultFocusLoc,isDefaultFocus);

}

int MyGLWidget::printOglError(const char file[], int line, const char func[])
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502:
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {}

void MyGLWidget::keyPressEvent(QKeyEvent *e) {
    makeCurrent();
    switch (e->key()) {
        case Qt::Key_Left:
          rotateCarLeft();
          break;

        case Qt::Key_Right:
          rotateCarRight();
          break;

        case Qt::Key_F:
          isDefaultFocus = !isDefaultFocus;
          glUniform1i(isDefaultFocusLoc,isDefaultFocus);
          break;

        case Qt::Key_R:
          isDefaultFocus = 1;
          glUniform1i(isDefaultFocusLoc,isDefaultFocus);
          angleCotxe = float(M_PI)/4.0f;
          break;
        // no modifiqueu el següent comportament:
        default:
            LL4GLWidget::keyPressEvent(e);
    }
    update();
}
