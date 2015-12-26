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

const float pi = 3.1415926535358979;

//<<<<<<<<<<< setWindow >>>>>>>>>>>>>>
void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

//<<<<<<<<<<<<<< setViewport >>>>>>>>>>>>>>>
void setViewport(GLint left, GLint right, GLint bottom, GLint top)
{
	glViewport(left,bottom,right-left,top-bottom);
}

//<<<<<<<<<<<<<myDispaly >>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_LINE_STRIP);
	for (float x = -4.0; x < 4.0; x += 0.1) {
		if (x == 0.0)
			glVertex2f(0.0, 1.0);
		else
			glVertex2f(x,sin(3.14159*x)/(3.14159*x));
	}
	glEnd();
	glFlush();
}

//<<<<<<<myInit>>>>>>>>>>>>>>>
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glLineWidth(2.0);
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
	setWindow(-0.5,5.0,-0.3,1.0);
	setViewport(0,640,0,480);
	glutMainLoop();
}