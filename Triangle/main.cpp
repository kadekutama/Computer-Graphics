/*
Drawing a triangle

Kadek Dwi Budi Utama
github.com/kadekutama
*/

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(0 , 640 , 0 , 480);
}

void triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glVertex2i(x3,y3);
    glEnd();
    glFlush();
}

void run() {
    /*
    This function is a driver to run the algorithm procedure.
    This is necessary because glutDisplayFunc() didn't support procedure with parameter.
    */
    triangle(200,125,100,375,300,375);
}

int main() {
    /* Initialise GLUT library */
    //glutInit(&argc,argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("triangle");
    /* Initialize drawing colors */
    init();
    /* Call the displaying function */
    glutDisplayFunc(run);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}

