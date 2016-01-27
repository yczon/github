#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;
//不显示控制台窗口  
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	//画分割线，分成四个视见区  
	glViewport(0, 0, 400, 400);
	glBegin(GL_LINES);
	glVertex2f(-1.0, 0);
	glVertex2f(1.0, 0);
	glVertex2f(0.0, -1.0);
	glVertex2f(0.0, 1.0);
	glEnd();

	//定义在左下角的区域  
	glColor3f(0.0, 1.0, 0.0);
	glViewport(0, 0, 200, 200);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();


	//定义在右上角的区域  
	glColor3f(0.0, 0.0, 1.0);
	glViewport(200, 200, 200, 200);//注意，后面这两个参数是高度和宽度，而不是坐标  
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();

	//定义在左上角的区域  
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0, 200, 200, 200);//注意，后面这两个参数是高度和宽度，而不是坐标  
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();

	//定义在右下角  
	glColor3f(1.0, 1.0, 1.0);
	glViewport(200, 0, 200, 200);//注意，后面这两个参数是高度和宽度，而不是坐标  
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//定义剪裁面  
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("glviewport");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}