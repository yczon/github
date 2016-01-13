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
	GLPoint center;
	GLPoint tmp;
	center.set(0,0);
	GLfloat theta = (2.0f * PI) / N;
	for (int c = 0; c < N; c++) {
		pointlist[c].set(radius*sin(theta*c+PI), radius*cos(theta*c+PI));
	}

	moveTo(pointlist[1]);
	tmp.set(pointlist[1].x,pointlist[1].y+pointlist[0].y);
	lineTo(tmp);

	lineTo(pointlist[0]);

	tmp.set(pointlist[2].x,pointlist[0].y+pointlist[2].y);
	lineTo(tmp);

	lineTo(pointlist[2]);

	lineTo(center);

	lineTo(pointlist[1]);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 600, 600);
	float R = 0.33f;
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