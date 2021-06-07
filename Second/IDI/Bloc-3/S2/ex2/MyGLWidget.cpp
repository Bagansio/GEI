// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

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

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  makeCurrent();
  // Aqui cal que es calculi i s'apliqui la rotacio o el zoom com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotació
    angleY += (e->x() - xClick) * M_PI / ample;
    viewTransform ();
  }

  xClick = e->x();
  yClick = e->y();

  update ();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {

    case Qt::Key_K:
      if(posFocus.x >= -2){
        --posFocus.x;
        glUniform3fv(posFocusLoc, 1, &posFocus[0]);
      }
      break;

    case Qt::Key_L:
      if(posFocus.x <= 2){
        ++posFocus.x;
        glUniform3fv(posFocusLoc, 1, &posFocus[0]);
      }
      break;

    default: BL3GLWidget::keyPressEvent(event); break;
  }
  update();
}

void MyGLWidget::iniMaterialTerra ()
{
  // Donem valors al material del terra
  amb = glm::vec3(0.2,0,0.2);
  diff = glm::vec3(0,0,0.8);
  spec = glm::vec3(0,1,0);
  shin = 128;
}




void MyGLWidget::iniLight()
{
  // Obtenim identificador per a l'atribut "posFocus"” del vertex shader
  posFocusLoc = glGetUniformLocation (program->programId(), "posFocus");

  // Obtenim identificador per a l'atribut "llumAmbient"” del vertex shader
  llumAmbientLoc = glGetUniformLocation (program->programId(), "llumAmbient");

  // Obtenim identificador per a l'atribut colFocus” del vertex shader
  colFocusLoc = glGetUniformLocation (program->programId(), "colFocus");

  normalMatrixLoc = glGetUniformLocation (program->programId(), "NormalMatrix");

  colFocus = glm::vec3(0.8, 0.8, 0.8);
  posFocus = glm::vec3(0, 0, 0);
  llumAmbient = glm::vec3(0.2, 0.2, 0.2);


  glUniform3fv(colFocusLoc, 1, &colFocus[0]);
  glUniform3fv(posFocusLoc, 1, &posFocus[0]);
  glUniform3fv(llumAmbientLoc, 1, &llumAmbient[0]);
}

void MyGLWidget::initializeGL(){

  BL3GLWidget::initializeGL();
  iniLight();
}

void MyGLWidget::paintGL ()
{
  // En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
  // useu els paràmetres que considereu (els que hi ha són els de per defecte)
  // glViewport (0, 0, ample, alt);

  // Esborrem el frame-buffer i el depth-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Activem el VAO per a pintar el terra
  glBindVertexArray (VAO_Terra);

  modelTransformTerra ();
  normalMatrix = glm::inverse(glm::transpose(glm::mat3(View*TG)));
  glUniformMatrix3fv(normalMatrixLoc, 1,GL_FALSE, &normalMatrix[0][0]);
  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 12);

  // Activem el VAO per a pintar el Patricio
  glBindVertexArray (VAO_Patr);

  modelTransformPatricio ();
  normalMatrix = glm::inverse(glm::transpose(glm::mat3(View*TG)));
  glUniformMatrix3fv(normalMatrixLoc, 1,GL_FALSE, &normalMatrix[0][0]);
  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);

  glBindVertexArray(0);
}
