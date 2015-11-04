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

	glColor3f(0.0, 0.4, 0.2);
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145);
	glEnd();

	glFlush();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.4, 0.2);
	GLubyte bitShape[20] = {
		0x1c,0x00,0x1c,0x00,0x1c,0x00,0x1c,0x00,0x1c,0x00,
		0xff,0x80,0x7f,0x00,0x3e,0x00,0x1c,0x00,0x08,0x00
	};

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2i(30, 40);
	glBitmap(9, 10, 0.0, 0.0, 20.0, 15.0, bitShape);
	glFlush();
}
void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,300);
	glutCreateWindow("An Example OpenGL Program");

	init();


	glutDisplayFunc(draw);
	glutMainLoop();
}