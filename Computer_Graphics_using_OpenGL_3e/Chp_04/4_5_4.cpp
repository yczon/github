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

GLPoint A[] = { {10,10},{10,60},{40,90},{70,60},{70,10},{50,10},{50,30},{30,30},{30,10},{10,10} };
GLPoint B[] = { {30,10},{30,40},{10,40},{10,60},{40,90},{70,60},{70,40},{50,40},{50,10},{30,10} };
void drawTween(GLPoint A[], GLPoint B[], int n, float t)
{
	for (int i = 0;i < n;i++) {
		GLPoint P;
		P = tween(A[i], B[i], t);
		if (i == 0) {
			moveTo(P);
		}
		else {
			lineTo(P);
		}
	}
}

void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// 设置背景颜色为白色
	glColor3f(0.0f, 0.0f, 0.0f);			// 设置绘图颜色为黑色
	glPointSize(2.0);						// 设置点的大小为4x4像素
	glMatrixMode(GL_PROJECTION);			// 设置合适的矩阵
	glLoadIdentity();						// 后台将解释
	gluOrtho2D(0.0, 640, 0.0, 480);			// 接下来将完整的说明
}

//<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	float delT = 0.1;

	for (float t=.0;t <= 1;t += delT) {
		for (int i = 0;i < 200000000;i++) {}
		glClear(GL_COLOR_BUFFER_BIT);
		drawTween(A,B,10,t);
	}
	glFlush();
}
//------main------
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("The Famous Sinc Function");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}