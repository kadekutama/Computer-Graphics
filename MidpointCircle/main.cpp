/*
Drawing a circle using Midpoint algorithm

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

void midpoint(int x1, int y1, int r) {
    int p = 1-r;
    int x = 0;
    int y = r;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        while (x < y) {
            glVertex2i(x+x1,y+y1);
            glVertex2i(-x+x1,y+y1);
            glVertex2i(x+x1,-y+y1);
            glVertex2i(-x+x1,-y+y1);
            glVertex2i(y+x1,x+y1);
            glVertex2i(y+x1,-x+y1);
            glVertex2i(-y+x1,x+y1);
            glVertex2i(-y+x1,-x+y1);
            x++;
            if (p < 0)
                p += (2*x) + 1;
            else {
                y--;
                p += (2*x) + 1 - (2*y);
            }
        }
    glEnd();
    glFlush();
}

void run() {
    /*
    This function is a driver to run the algorithm procedure.
    This is necessary because glutDisplayFunc() didn't support procedure with parameter.
    */
    midpoint(200,200,50);
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
    glutCreateWindow("Midpoint_Line");
    /* Initialize drawing colors */
    init();
    /* Call the displaying function */
    glutDisplayFunc(run);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}

