#include "stdafx.h"
#include<GL/glut.h>
#include<iostream>

using namespace std;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0);
	glColor3f(0.0, 0.4, 0.2);

	glBegin(GL_POINTS);
	glVertex2i(25,60);
	glEnd();

	glPointSize(20.0);
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_POINTS);
	glVertex2i(50,100);
	glEnd();

	glFlush();
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