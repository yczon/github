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
#include<vector>
#include<fstream>
#include<cmath>

const double FAI = (1 + sqrt(5)) / 2;

using namespace std;

void myDisplay(void)
{
	int x = 100;
	int y = 200;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	glPointSize(1);
	y = FAI * x;
	for (int i = 0;i < 2;++i) {
		glBegin(GL_LINE_LOOP);
		glVertex2i(10,10);
		glVertex2i(x+10,10);
		glVertex2i(x+10,y+10);
		glVertex2i(10,y+10);
		glEnd();
		y = y - x;
	}
	glFlush();
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
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