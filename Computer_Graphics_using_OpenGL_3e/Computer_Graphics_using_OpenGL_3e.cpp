// Computer_Graphics_using_OpenGL_3e.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;

using namespace std;

struct GLintPoint {
	GLint x, y;
};
GLintPoint corner[2];
bool selected = false;
GLintPoint CP;
//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(0.0f,1.0f,0.0f);
	if (selected) {
		glBegin(GL_QUADS);
			glVertex2i(corner[0].x,corner[0].y);
			glVertex2i(corner[0].x,corner[1].y);
			glVertex2i(corner[1].x,corner[1].y);
			glVertex2i(corner[1].x,corner[0].y);
		glEnd();
		glFlush();
	}
	glutSwapBuffers();
}

//<<<<<<<<<<<<<<<<<< myMouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		corner[0].x = x;
		corner[0].y = screenHeight - y;
		selected = true;
	}
	glutPostRedisplay();
}
void myPassiveMotion(int x, int y)
{
	corner[1].x = x;
	corner[1].y = screenHeight - y;
	glutPostRedisplay();
}
int main(int argc, char **argv)
{
	// GLUT 初始化函数
	glutInit(&argc, argv);							// 初始化工具包
	glutInitWindowSize(screenWidth, screenHeight);	// 设置窗口大小
	glutInitWindowPosition(0, 0);					// 设置屏幕上窗口位置
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// 设置显示模式
	glutCreateWindow("My first OpenGL program");	// 打开带标题的窗口
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,screenWidth,0,screenHeight);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);			// 背景为白色
	glViewport(0,0,screenWidth,screenHeight);
	glutMouseFunc(myMouse);
	glutDisplayFunc(myDisplay);						// 注册重画回调函数
	glutPassiveMotionFunc(myPassiveMotion);

	glutMainLoop();									// 进入循环
	return 0;
}