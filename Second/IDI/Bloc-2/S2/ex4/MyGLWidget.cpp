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

void MyGLWidget::initializeGL ( ){
    BL2GLWidget::initializeGL();
    
    rotate = 0.0f;
    glEnable(GL_DEPTH_TEST);
    
    m.load("../../models/Patricio.obj");
    creaBuffers();
    
    
    calculateModelBox();
    calculateSceneBox();
    
    
    ini_camera();
    
}

void MyGLWidget::carregaShaders(){
    BL2GLWidget::carregaShaders();
    projLoc = glGetUniformLocation(program->programId(),"proj");
    viewLoc = glGetUniformLocation(program->programId(),"view");
}

void MyGLWidget::calculateModelBox(){
  float min[3],max[3];
  // 0 = x  1 = y    2 = z
  min[0] = max[0] = m.vertices()[0];
  min[1] = max[1] = m.vertices()[1];
  min[2] = max[2] = m.vertices()[2];
  for(unsigned int i = 3; i < m.vertices().size(); ++i){
      if(m.vertices()[i] > max[i%3]) max[i%3] = m.vertices()[i];
      if(m.vertices()[i] < min[i%3]) min[i%3] = m.vertices()[i];
  }
  modelScale = 4.0f/(max[1]-min[1]);
  modelCenter = glm::vec3((min[0]+max[0])/2,min[1],(min[2]+max[2])/2);
  Pmax.y = 4;
}

void MyGLWidget::calculateSceneBox(){
    Pmax.x = 2.5;
    Pmax.z = 2.5;
    
    Pmin = glm::vec3(-2.5,0.0,-2.5);
}

void MyGLWidget::ini_camera(){
    //view
    
    calculateAttributes();
    
    projectTransform(FOV,ra,znear,zfar);
    viewTransform();
}

void MyGLWidget::calculateAttributes(){
    up = glm::vec3(0,1,0);
    ra = 1.0f;
    VRP = glm::vec3((Pmin[0]+Pmax[0])/2,(Pmin[1]+Pmax[1])/2,(Pmin[2]+Pmax[2])/2); //(Pmin+Pmax)/2; center
    
    radi = sqrt((Pmax[0]-Pmin[0])*(Pmax[1]-Pmin[1])*(Pmax[2]-Pmin[2]))/2.0f;
    distance = radi*3.0;//glm::vec3(radi[0]*3,radi[1]*3,radi[2]*3);//radi * 3;
    
    OBS = VRP + glm::vec3(0,0,distance);//glm::vec3(VRP[0],VRP[1],VRP[2]+distance);
    FOV = 3.0f * asin(radi/distance);
    znear = distance - radi;
    zfar = distance + radi;
}

void MyGLWidget::modelTransform() 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform, rotate, glm::vec3(0.0,1.0,0.0));
  
  transform = glm::scale(transform, glm::vec3(escala));
  transform = glm::scale(transform, glm::vec3(modelScale));
  
  transform = glm::translate(transform, -modelCenter);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::floorTransform() 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::projectTransform(float FOV, float ra, float znear, float zfar) {
    //glm::perspective ( FOV en radians, ra window, znear, zfar)
    glm::mat4 Proj = glm::perspective(FOV,ra,znear,zfar);
    glUniformMatrix4fv(projLoc,1,GL_FALSE,&Proj[0][0]);
}

void MyGLWidget::viewTransform() {
    //glm::lookAt(OBS,VRP,UP)
    glm::mat4 View = glm::lookAt(OBS,VRP,up);
    glUniformMatrix4fv (viewLoc,1,GL_FALSE,&View[0][0]);
}

void MyGLWidget::resizeGL(int width, int height){
    glViewport(0,0,width,height);
    ra = float(width)/float(height);
    if(ra < 1) projectTransform(2.0f * atan(tan(FOV/2.0)/ra),ra,znear,zfar); //ample < alt
    else projectTransform(FOV,ra,znear,zfar); //ample >= alt
}
        
    

void MyGLWidget::creaBuffers(){
    
    
    glGenVertexArrays(1, &VAO_Patricio);
    glBindVertexArray(VAO_Patricio);
    
    GLuint VBO_Patricio[2];
    glGenBuffers(2,VBO_Patricio);
    glBindBuffer(GL_ARRAY_BUFFER,VBO_Patricio[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_vertices(), GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO_Patricio[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_matdiff(), GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(colorLoc,3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);
    
    glBindVertexArray(0);
    
    glm::vec3 pos[6] = {
        glm::vec3(-2.5,0.0,-2.5),
        glm::vec3(-2.5,0.0,2.5),
        glm::vec3(2.5,0.0,2.5),
        glm::vec3(2.5,0.0,2.5),
        glm::vec3(-2.5,0.0,-2.5),
        glm::vec3(2.5,0.0,-2.5)
    };
    
    glm::vec3 color[6] = {
        glm::vec3(0.5f, 0.35f, 0.05f),
        glm::vec3(0.5f, 0.35f, 0.05f),
        glm::vec3(0.5f, 0.35f, 0.05f),
        glm::vec3(0.5f, 0.35f, 0.05f),
        glm::vec3(0.5f, 0.35f, 0.05f),
        glm::vec3(0.5f, 0.35f, 0.05f),
    };
    
    glGenVertexArrays(1, &VAO_Floor);
    glBindVertexArray(VAO_Floor);
    
    GLuint VBO_Floor[2];
    glGenBuffers(2,VBO_Floor);
    glBindBuffer(GL_ARRAY_BUFFER,VBO_Floor[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pos), pos, GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO_Floor[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color), color , GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(colorLoc,3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);
    
    glBindVertexArray(0);
    
    
}
  
void MyGLWidget::paintGL(){
    // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT);

  // Carreguem la transformació de model
  modelTransform();

  // Activem el VAO per a pintar Patricio 
  glBindVertexArray (VAO_Patricio);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, m.faces().size()*3);

  glBindVertexArray (0);
  
  floorTransform();
  
  // Activem el VAO per a pintar la Terra 
  glBindVertexArray (VAO_Floor);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 6);

  glBindVertexArray (0);
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      escala += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      escala -= 0.05;
      break;
    }
    case Qt::Key_R: {
        rotate += (float)M_PI/4;
        break;
    }
    default: event->ignore(); break;
  }
  update();
}
