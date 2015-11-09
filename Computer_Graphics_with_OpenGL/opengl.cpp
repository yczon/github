#include "stdafx.h"
#include<GL/glut.h>
#include<iostream>

using namespace std;

typedef struct
{
	float x, y;
} wcPt2D;

wcPt2D dataPts[5];

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}


void lineSegment(void)
{
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(10);
	glLineStipple(1,0x0101);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);
	int k;
	glBegin(GL_LINES);
		glVertex2f(10, 10);
		glVertex2f(100, 100);
	glEnd();
	glFlush();
	glDisable(GL_LINE_STIPPLE);
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("An Example OpenGL Program");

	init();


	glutDisplayFunc(lineSegment);
	glutMainLoop();
}