#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;
//����ʾ����̨����  
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

const GLsizei winWidth = 640;
const GLsizei winHeight = 480;

GLdouble coorLeft = -1*(winWidth/winHeight);
GLdouble coorRight = 1*(winWidth/winHeight);
GLdouble coorBottom = -1;
GLdouble coorTop = 1;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	//���ָ��ߣ��ֳ��ĸ��Ӽ���  
	glViewport(0, 0, winWidth, winHeight);
	glBegin(GL_LINES);
	glVertex2f(coorLeft, 0.0);
	glVertex2f(coorRight, 0.0);
	glVertex2f(0.0, coorBottom);
	glVertex2f(0.0, coorTop);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, winWidth/2, winHeight/2);//ע�⣬���������������Ǹ߶ȺͿ��ȣ�����������  
	glBegin(GL_POLYGON);
	glVertex2f(coorLeft/2, coorBottom /2);
	glVertex2f(coorLeft/2, coorTop/2);
	glVertex2f(coorRight/2,coorTop/2);
	glVertex2f(coorRight/2, coorBottom/2);
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//���������  
	gluOrtho2D(coorLeft,coorRight,coorBottom,coorTop);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("glviewport");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}