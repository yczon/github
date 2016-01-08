#include "stdafx.h"
#include"OpenglDraw.h"

GLPoint currPos;
GLPoint CP;

void moveTo(GLPoint p)
{
	CP.set(p);
}

void lineTo(GLPoint p)
{
	glBegin(GL_LINES);
		glVertex2f(CP.x, CP.y);
		glVertex2f(p.x, p.y);
	glEnd();
	glFlush();
	CP.set(p);
}
void rosette(int N, float radius)
{
	GLPoint *pointlist = new GLPoint[N];
	GLfloat theta = (2.0f * PI) / N;
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
	glViewport(10, 10, 640, 480);
	rosette(5, 0.66f);
	glFlush();
}
//<<<<<<<myInit>>>>>>>>>>>>>>>
void myInit(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
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