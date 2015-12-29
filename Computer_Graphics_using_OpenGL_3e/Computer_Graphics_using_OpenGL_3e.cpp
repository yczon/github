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


class GLintPoint {
public:
	GLint x, y;
};

class Point2 {
public:
	float x, y;
	void set(float dx, float dy) {
		x = dx;
		y = dy;
	}
	void set(Point2 &p) {
		x = p.x; y = p.y;
	}
	Point2(float xx, float yy) {
		x = xx;
		y = yy;
	}
	Point2() {
		x = y = 0;
	}
};

Point2 currPos;
Point2 CP;
void moveTo(Point2 p) 
{
	CP.set(p);
}

void lineTo(Point2 p)
{
	glBegin(GL_LINES);
	glVertex2f(CP.x,CP.y);
	glVertex2f(p.x,p.y);
	glEnd();
	glFlush();
	CP.set(p);
}
void rosette(int N, float radius)
{
	Point2 *pointlist = new Point2[N];
	GLfloat theta = (2.0f * pi) / N;
	for (int c = 0; c < N; c++) {
		pointlist[c].set(radius*sin(theta*c), radius*cos(theta*c));
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			moveTo(pointlist[i]);
			lineTo(pointlist[j]);
		}
	}
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(10,10,640,480);
	rosette(5,0.66f);
	glFlush();
}
//<<<<<<<myInit>>>>>>>>>>>>>>>
void myInit(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,0.0,0.0,0.0);
	glColor3f(0.0f, 0.0f, 1.0f);
}

//------main------
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("The Famous Sinc Function");
	glutDisplayFunc(render);
	myInit();
	glutMainLoop();
}