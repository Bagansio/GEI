#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;




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
  for(int i = -2; i < 3; ++i){
      for(int j = -2; j < 3; ++j){
          
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
