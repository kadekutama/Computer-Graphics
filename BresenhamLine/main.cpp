/*
Drawing a line using Bresenham algorithm

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

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int d1 = 2*dy;
    int d2 = 2*(dx-dy);
    int p = d1-dx;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        for (int i = 0; i < dx-1; i++) {
            if (p >= 0) {
                p -= d2;
                y1++;
            } else {
                p += d1;
            }
            x1++;
            glVertex2i(x1,y1);
        }
    glEnd();
    glFlush();
}

void run() {
    /*
    This function is a driver to run the algorithm procedure.
    This is necessary because glutDisplayFunc() didn't support procedure with parameter.
    */
    bresenham(100,100,200,200);
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
    glutCreateWindow("Bresenham_Line");
    /* Initialize drawing colors */
    init();
    /* Call the displaying function */
    glutDisplayFunc(run);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}

