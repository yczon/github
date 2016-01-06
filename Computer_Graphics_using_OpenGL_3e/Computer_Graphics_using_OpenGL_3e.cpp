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

//<<<<<<<<<<<<<<<<< hexSwirl >>>>>>>>>>>>>>>>>>>>
void hexSwirl() {

	const double radPerDeg = 0.017453393f;

	double x, y, cx, cy;
	double length = 10.0f;
	double scale = 0.1f;
	double theta = 0.0f;

	for (int i = 0; i < 50; i++) {

		x = y = 0.0f;

		x -= 11.18034f * sin(radPerDeg * 30.0f);
		y -= 11.18034f * cos(radPerDeg * 30.0f);

		glPushMatrix();

		glTranslatef(300.0f, 200.0f, 0.0f);
		glScalef(scale, scale, scale);
		glRotatef(theta, 0, 0, 1);

		theta += 1.5f;
		scale += 0.7f;

		glBegin(GL_LINE_LOOP);

		for (int c = 0; c < 6; c++) {

			glVertex2f(x, y);

			x += (length * cos(radPerDeg * (c * 60.0f)));
			y += (length * sin(radPerDeg * (c * 60.0f)));

		}

		glEnd();

		glPopMatrix();
	}
}

// <<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	setWindow(-0.6, 0.6, -0.6, -0.6);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			int L = 80;
			//setViewport(i*L,L+i*L,j*L,L+j*L);
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(1, 0, 0);
			glBegin(GL_LINE_LOOP);
			glVertex2i(10, 10);
			glVertex2i(100, 10);
			glVertex2i(100, 100);
			glVertex2i(10, 100);
			glEnd();
			glFlush();
		}
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