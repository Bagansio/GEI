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
    
    m.load("../../models/HomerProves.obj");
    creaBuffers();
    ini_camera();
    
}

void MyGLWidget::carregaShaders(){
    BL2GLWidget::carregaShaders();
    projLoc = glGetUniformLocation(program->programId(),"proj");
    viewLoc = glGetUniformLocation(program->programId(),"view");
}

void MyGLWidget::ini_camera(){
    //view
    OBS = glm::vec3(0,0,1);
    VRP = glm::vec3(0,0,0);
    up = glm::vec3(0,1,0); //default 0,1,0
    //project
    FOV = float(M_PI)/2.0f;
    ra = 1.0f;
    znear = 0.4f;
    zfar = 3.0f;
    
    projectTransform();
    viewTransform();
}

void MyGLWidget::modelTransform() 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(escala));
  transform = glm::rotate(transform, rotate, glm::vec3(0.0,1.0,0.0));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::floorTransform() 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::projectTransform() {
    //glm::perspective ( FOV en radians, ra window, znear, zfar)
    glm::mat4 Proj = glm::perspective(FOV,ra,znear,zfar);
    glUniformMatrix4fv(projLoc,1,GL_FALSE,&Proj[0][0]);
}

void MyGLWidget::viewTransform() {
    //glm::lookAt(OBS,VRP,UP)
    glm::mat4 View = glm::lookAt(OBS,VRP,up);
    glUniformMatrix4fv (viewLoc,1,GL_FALSE,&View[0][0]);
}

void MyGLWidget::creaBuffers(){
    
    
    glGenVertexArrays(1, &VAO_Homer);
    glBindVertexArray(VAO_Homer);
    
    GLuint VBO_Homer[2];
    glGenBuffers(2,VBO_Homer);
    glBindBuffer(GL_ARRAY_BUFFER,VBO_Homer[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_vertices(), GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO_Homer[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_matdiff(), GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(colorLoc,3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);
    
    glBindVertexArray(0);
    
    glm::vec3 pos[6] = {
        glm::vec3(-2.0,-1.0,-2.0),
        glm::vec3(-2.0,-1.0,2.0),
        glm::vec3(2.0,-1.0,2.0),
        glm::vec3(2.0,-1.0,2.0),
        glm::vec3(-2.0,-1.0,-2.0),
        glm::vec3(2.0,-1.0,-2.0)
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

  // Activem el VAO per a pintar la Homer 
  glBindVertexArray (VAO_Homer);

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
