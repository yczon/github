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
	glLineWidth(10);
	glPolygonMode(GL_FRONT,GL_LINE);
	glColor3f(0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glVertex2i(50,50);
		glVertex2i(150, 50);
		glVertex2i(75, 150);
	glEnd();
	glPolygonMode(GL_FRONT,GL_FILL);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2i(50,50);
		glVertex2i(150, 50);
		glVertex2i(75, 150);
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