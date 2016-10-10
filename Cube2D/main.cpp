/*
Drawing a 2D cube

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
  gluOrtho2D(0 , 640 , 0 , 480);
}

void cube2d(int xy[][2]) {
    float color[][3] = {
        {1.0,1.0,0.0},
        {1.0,0.0,1.0},
        {0.0,1.0,1.0}
    };
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
        int i = 0, j = 0;
        while ((xy[i][0] != -1) && (j < 3)) {
            glColor3f(color[j][0],color[j][1],color[j][2]);
            //printf("%d - %f,%f,%f\n", j,color[j][0],color[j][1],color[j][2]);
            glVertex2i(xy[i][0],xy[i][1]);
            i++;
            if (i % 4 == 0)
                j++;
        }
    glEnd();
    glFlush();
}

void run() {
    /*
    This function is a driver to run the algorithm procedure.
    This is necessary because glutDisplayFunc() didn't support procedure with parameter.
    */
    static int points[][2] = {
        {100,100},{300,100},{300,300},{100,300},
        {100,300},{300,300},{350,350},{150,350},
        {300,100},{300,300},{350,350},{350,150}
    };
    cube2d(points);
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
    glutCreateWindow("2D Cube");
    /* Initialize drawing colors */
    init();
    /* Call the displaying function */
    glutDisplayFunc(run);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}

