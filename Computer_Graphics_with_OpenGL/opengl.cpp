#include "stdafx.h"
#include<GL/glut.h>
#include<iostream>

using namespace std;

typedef GLint vertex3[3];
vertex3 pt[8] = {
	{0,0,0},
	{0,100,0},
	{100,0,0},
	{100,100,0},
	{0,0,100},
	{0,100,100},
	{100,0,100},
	{100,100,100},
};
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void quad(GLint n1, GLint n2, GLint n3, GLint n4)
{
	glBegin(GL_QUADS);
	glVertex3iv(pt[n1]);
	glVertex3iv(pt[n2]);
	glVertex3iv(pt[n3]);
	glVertex3iv(pt[n4]);
	glEnd();
}

void cube()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.4, 0.2);

	quad(6,2,3,7);
	quad(5,1,0,4);
	quad(7,3,0,4);
	quad(4,0,2,6);
	quad(2,0,1,3);
	quad(7,5,4,6);

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


	glutDisplayFunc(cube);
	glutMainLoop();
}