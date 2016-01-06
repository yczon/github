/****************************************************************************

example5.cpp

A GLUI program demonstrating subwindows, rotation controls,
translation controls, and listboxes

-----------------------------------------------------------------------

7/10/98 Paul Rademacher (rademach@cs.unc.edu)

****************************************************************************/
#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;

typedef vector<GLPoint> Polygon;
typedef vector<Polygon> PolyLines;
PolyLines dimo;

//<<<<<<<<<<<<<<<<<< setWindow >>>>>>>>>>>>>>>>>>>
void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left,right,bottom,top);
}

//<<<<<<<<<<<<<<<<<< setViewport >>>>>>>>>>>>>>>>>>>
void setViewport(GLint left, GLdouble right, GLdouble bottom, GLdouble top)
{
	glViewport(left,bottom,right-left,top-bottom);
}

// <<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	int x = 100;
	int y = 100;
	int w = 1;
	int h = 1;
	int center_x = w / 2;
	int center_y = h / 2;

	for (int i = 1; i < 10; i++) {
		for (long a = 0; a < 200000000; a++) {}
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 0, 0);
		w = 640 / i;
		h = 480 / i;
		center_x = w / 2;
		center_y = h / 2;
		setWindow(0, w, 0, h);
		glBegin(GL_LINE_LOOP);
			glVertex2i(center_x-10, center_y-10);
			glVertex2i(center_x+10, center_y-10);
			glVertex2i(center_x+10, center_y+10);
			glVertex2i(center_x-10, center_y+10);
		glEnd();
		glFlush();
	}
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	setWindow(0,640,0,480);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("MyDimo");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}