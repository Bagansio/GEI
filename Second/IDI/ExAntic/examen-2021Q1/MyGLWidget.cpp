// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

void MyGLWidget::changeCamera(QString type){
  makeCurrent();
  if (type == "Perspectiva") camPlanta = false;
  else camPlanta = true;
  projectTransform();
  viewTransform();
  update();
}

void MyGLWidget::changePos(int pos){
    makeCurrent();
    switch(pos+1){
        case 1:
            angleP = 0;
            break;
        case 2:
            angleP = 2.0f*M_PI/3;
            break;
            
        case 3:
            angleP = 4.0f*M_PI/3;
            break;
    }
    update();
}
        
        

void MyGLWidget::changeToPerspective(){
  makeCurrent();
  camPlanta = false;
  projectTransform();
  viewTransform();
  update();
}

void MyGLWidget::changeToOrtho(){
  makeCurrent();
  camPlanta = true;
  projectTransform();
  viewTransform();
  update();
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

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::paintGL ()   // Mètode que has de modificar
{
  // En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
  // useu els paràmetres que considereu (els que hi ha són els de per defecte)
  //  glViewport (0, 0, ample, alt);

    // Esborrem el frame-buffer i el depth-buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Pintem el terra
    glBindVertexArray (VAO_Terra);
    modelTransformTerra ();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    if(paintPatricio){
      // Pintem el Patricio
      glBindVertexArray (VAO_Patr);
      modelTransformPatricio ();
      glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);
    }
    else {
      float angle = angleAux;
      float esc = 2.0;
      glBindVertexArray(VAO_Cub);
      for(int i = 0; i<3 ; ++i)
      {
        // Pintem el cub

        modelTransformCub (esc/0.5, angle);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        esc += 0.5;
        angle += 2.0f*M_PI/3;
      }
    }
    glBindVertexArray(0);
}

void MyGLWidget::modelTransformCub (float escala, float angle)
{
  TG = glm::mat4(1.f);

  TG = glm::rotate(TG, angle, glm::vec3(0,1,0));
  TG = glm::translate(TG, glm::vec3(5,0,0));
  TG = glm::scale(TG,glm::vec3(escala,escala,escala));




  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
  // En aquest mètode has de substituir aquest codi per construir la
  // transformació geomètrica (TG) del cub usant els paràmetres adientment
}

void MyGLWidget::modelTransformPatricio ()    // Mètode que has de modificar
{
  TG = glm::mat4(1.f);


  TG = glm::rotate(TG, angleP+angleAux, glm::vec3(0,1,0));
  TG = glm::translate(TG, glm::vec3(5,0,0));
  TG = glm::scale(TG, glm::vec3 (2*escala, 2*escala, 2*escala));
  TG = glm::rotate(TG, -float(M_PI/2.0f), glm::vec3(0,1,0));
  TG = glm::translate(TG, -centreBasePat);



  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::viewTransform ()    // Mètode que has de modificar
{
  if (!camPlanta)
    ExamGLWidget::viewTransform();
  else
  {
    View = glm::lookAt(glm::vec3(0,15,0),glm::vec3(0,0,0),glm::vec3(1,0,0));

    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
  }
}

void MyGLWidget::projectTransform ()
{
  if (!camPlanta)
    ExamGLWidget::projectTransform();
  else
  {
    glm::mat4 Proj;  // Matriu de projecció
    if(ra > 1) Proj = glm::ortho(-15.0f*ra,15.0f*ra,-15.0f,15.0f,5.0f,20.0f);
    else Proj = glm::ortho(-15.0f,15.0f,-15.0f/ra,15.0f/ra,5.0f,20.0f);
    glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
  }
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
  case Qt::Key_V: {
      paintPatricio = ! paintPatricio;
    break;
	}
  case Qt::Key_1: {
      angleP = 0;
      emit sendText("1");
    break;
	}
  case Qt::Key_2: {
      angleP = 2.0f*M_PI/3;
      emit sendText("2");
    break;
	}
  case Qt::Key_3: {
      angleP = 4.0f*M_PI/3;
      emit sendText("3");
    break;
	}
  case Qt::Key_F: {
      isColFocusWhite = !isColFocusWhite;
      if(isColFocusWhite){
        colFoc = glm::vec3(1,1,1);
      }
      else colFoc = glm::vec3(1,1,0);
      enviaColFocus();
    break;
	}
  case Qt::Key_C: {
      camPlanta = !camPlanta;
      if(camPlanta) emit sendText("Ortogonal");
      else emit sendText("Perspectiva");
      projectTransform();
      viewTransform();
    break;
	}
  case Qt::Key_Right: {
      angleAux += 2.0f*M_PI/3;
    break;
	}
  case Qt::Key_Left: {
      angleAux -= 2.0f*M_PI/3;
    break;
	}
  case Qt::Key_R: {
      angleAux = 0;
      angleP = 0;
      emit sendText("Perspectiva");
      emit sendText("1");
      isColFocusWhite = true;
      paintPatricio = false;
      camPlanta = false;
      colFoc = glm::vec3(1,1,1);
      enviaColFocus();
      projectTransform();
      viewTransform();
      ExamGLWidget::iniCamera();
      
    break;
	}
  default: ExamGLWidget::keyPressEvent(event); break;
  }
  update();
}
