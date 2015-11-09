#include"stdafx.h"
#include<GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	int p1[] = { 20,30 };
	int p2[] = { 30,10 };
	int p3[] = { 50,10 };
	int p4[] = { 60,30 };
	int p5[] = { 50,50 };
	int p6[] = { 30,50 };

	glColor3f(0.2, 0.5, 0.3);

	glBegin(GL_POLYGON);
	glVertex2iv(p1);
	glVertex2iv(p2);
	glVertex2iv(p3);
	glVertex2iv(p4);
	glVertex2iv(p5);
	glVertex2iv(p6);
	glEnd();

	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Title");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}