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

void cube()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.4, 0.2);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_INT, 0, pt);
	GLubyte vertIndex[] = {
			6,2,3,7,
			5,1,0,4,
			7,3,0,4,
			4,0,2,6,
			2,0,1,3,
			7,5,4,6
	};

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, vertIndex);

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