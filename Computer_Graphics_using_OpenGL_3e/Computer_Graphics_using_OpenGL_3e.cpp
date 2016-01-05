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
#include<iostream>

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
	unsigned long x = 1;
	unsigned long y = 1;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glPointSize(1);
	glBegin(GL_POINTS);
	for (int i = 0; i < 2000; ++i) {
		y = x;
		x = 40 * (1 + 2 * 3) - y + x - 3 * 40;
		glVertex2i(x,y);
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