#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;
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

	for (int i = 0; i < N - 1; i++) {
		moveTo(pointlist[i]);
		lineTo(pointlist[i+1]);
	}
	lineTo(pointlist[0]);

	GLfloat r = 0.1*radius;
	GLfloat angle = theta / 2;
	GLPoint *pointlist2 = new GLPoint[N];
	for (int c = 0; c < N; c++) {
		pointlist2[c].set(r*sin(theta*c + angle), r*cos(theta*c + angle));
	}

	for (int j = 0;j < N-1;++j) {
		moveTo(pointlist2[j]);
		lineTo(pointlist[j]);
		moveTo(pointlist[j+1]);
		lineTo(pointlist2[j]);
	}
	moveTo(pointlist2[N-1]);
	lineTo(pointlist[N-1]);
	moveTo(pointlist[0]);
	lineTo(pointlist2[N-1]);;


}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 600, 600);
	float R = 0.66f;
	rosette(3, R);
	glFlush();
}
//<<<<<<<myInit>>>>>>>>>>>>>>>
void myInit(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.7, 0.7, 0.7, 0.0);
	setColor(string("grey"));
}

//------main------
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("The Famous Sinc Function");
	glutDisplayFunc(render);
	myInit();
	glutMainLoop();
}