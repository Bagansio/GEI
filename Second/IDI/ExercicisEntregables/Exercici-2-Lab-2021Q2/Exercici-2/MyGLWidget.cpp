#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

#define MINPOS_HOMER -3
#define MAXPOS_HOMER 4

void MyGLWidget::moveHomer(int i){

    xH += deltai[i-1];
    zH += deltaj[i-1];
    bool canMove = true;
    
    if (xH < MINPOS_HOMER or xH > MAXPOS_HOMER or zH < MINPOS_HOMER or zH > MAXPOS_HOMER){
        xH -= deltai[i-1];
        zH -= deltaj[i-1];
        canMove = false;
    }

    if(canMove){
        
        if(xH == MINPOS_HOMER) angleH = M_PI / 2; // 90 X Positive 
        else if( xH == MAXPOS_HOMER) angleH = M_PI / 2 + M_PI; // 180 + 90 = 270 X Negative
        else if(zH == MINPOS_HOMER) angleH = 0; //0 Z Positive 360
        else if(zH == MAXPOS_HOMER) angleH = M_PI; //180  Z negative
        
        else if(i == 1 or i == 8) angleH = M_PI; //180  Z negative
        else if(i == 2 or i == 3) angleH = M_PI / 2 + M_PI; // 180 + 90 = 270 X Negative
        else if(i == 4 or i == 5) angleH = 0; //0 Z Positive 360
        else angleH = M_PI / 2; // 90 X Positive
    }
}

void MyGLWidget::restart(){
    
    xH = zH = 0.0f;
    angleH = 0.0f;
    
    iniCamera();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
      
      case Qt::Key_C: {
          changeCamera();
          break;
      }
      
      case Qt::Key_R: {
          restart();
          break;
      }
      
      case Qt::Key_1: {
          moveHomer(1);
          break;
      }
      case Qt::Key_2: {
          moveHomer(2);
          break;
      }
      case Qt::Key_3: {
          moveHomer(3);
          break;
      }
      case Qt::Key_4: {
          moveHomer(4);
          break;
      }
      case Qt::Key_5: {
          moveHomer(5);
          break;
      }
      case Qt::Key_6: {
          moveHomer(6);
          break;
      }
      case Qt::Key_7: {
          moveHomer(7);
          break;
      }
      case Qt::Key_8: {
          moveHomer(8);
          break;
      }
          
    default: event->ignore(); break;
  }
  update();
}


void MyGLWidget::changeCamera(){
    
    isPerspective = ! isPerspective;
    
    if(isPerspective){
        obs = glm::vec3(0.5, 2, 12);
        up = glm::vec3(0, 1, 0);
  
        //Theta = 0.0; deja la camara en pos original
    }
    else {
        obs = glm::vec3(0.5, 12, 0);
        up = glm::vec3(0, 0, 1);
  
        //Theta = float(M_PI/2.0);
    }

    viewTransform();
    projectTransform();
}

void MyGLWidget::viewTransform ()
{
  // Matriu de posició i orientació de l'observador
  glm::mat4 View(1.0f);
  View = glm::lookAt (obs, vrp, up);
  
  //View = glm::rotate(View, Theta, glm::vec3 (1., 0., 0.));

  
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::projectTransform ()
{
  glm::mat4 Proj(1.0f);
  if(isPerspective)Proj = glm::perspective (fov, ra, znear, zfar);
  else Proj = glm::ortho(-radius*rav, radius*rav,-radius/raw,radius/raw,znear,zfar);
  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}


void MyGLWidget::iniCamera(){
  
  isPerspective = true;
  
  obs = glm::vec3(0.5, 2, 12);
  vrp = glm::vec3(0.5, 0, 0.5);
  up = glm::vec3(0, 1, 0);
  
  ra = raw = rav = 1.0;
  
  Pmin = glm::vec3(-4.0,-0.5,-4.0);
  Pmax = glm::vec3(4.0,0.5,4.0);

  radius = glm::distance(Pmax,Pmin)/2.0f;

  distance = radius * 2.0; 
  znear =  distance - radius;
  zfar  = distance + radius;
  fovini = 2.0f * asin(radius/distance);
  fov = fovini;
  viewTransform();
  projectTransform();
}

void MyGLWidget::resizeGL (int w, int h) 
{
// Aquest codi és necessari únicament per a MACs amb pantalla retina.
#ifdef __APPLE__
  GLint vp[4];
  glGetIntegerv (GL_VIEWPORT, vp);
  ample = vp[2];
  alt = vp[3];
#else
  ample = w;
  alt = h;
#endif
  ra = float(ample)/float(alt);
  if(isPerspective){
        if(ra < 1) fov = 2.0f * atan(tan(fovini/2.0)/ra); //ample < alt
        else fov = fovini; //ample >= alt
  }
  else{
      if(ra < 1){
          raw = ra;
          rav = 1.0f;
      }
      else{
          rav = ra;
          raw = 1.0f;
      }
  }
  projectTransform();
}

void MyGLWidget::paintGL ()
{
  // descomentar per canviar paràmetres
  // glViewport (0, 0, ample, alt);

  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Homer
  homerTransform(xH, zH);
  glBindVertexArray (VAO_Homer);
  glUniform1i(indexColorLoc, 2);  // color = 2 -- color per vèrtex
  glDrawArrays(GL_TRIANGLES, 0, homer.faces().size()*3);
  glBindVertexArray (0);

  // Escac
  for(int i = -3; i <= 4; ++i){
      for(int j = -3; j <= 4; ++j){
          
        escacTransform(i, j);
        glBindVertexArray (VAO_Escac);
        glUniform1i(indexColorLoc, (j+i)%2);  // color = 1 -- color escac blanc (0.8, 0.8, 0.8)
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray (0);
    }
  }
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

MyGLWidget::~MyGLWidget()
{

}
