/****************************************************************************

example5.cpp

A GLUI program demonstrating subwindows, rotation controls,
translation controls, and listboxes

-----------------------------------------------------------------------

7/10/98 Paul Rademacher (rademach@cs.unc.edu)

****************************************************************************/
#include "stdafx.h"
#include <string.h>
#include <GL/glut.h>
#include <GL/glui.h>
#include<random>

using namespace std;

void myInit()
{
	glClearColor(1.0,1.0,1.0,0);
	glMatrixMode(GLUT_SINGLE | GLUT_RGB);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}
void myDisplay()
{
	default_random_engine e;
	uniform_int_distribution<int> u(0,640);
	int num = 10000;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glPointSize(4);
	glBegin(GL_POINTS);
	for (int i = 0; i < num; ++i) {
		glVertex2i(u(e),u(e));
	}
	glEnd();
	glFlush();
}
//------main------
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("The Famous Sinc Function");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}