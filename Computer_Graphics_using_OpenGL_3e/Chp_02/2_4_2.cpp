// Computer_Graphics_using_OpenGL_3e.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;

using namespace std;

//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// 设置背景颜色为白色
	glColor3f(0.0f, 0.0f, 0.0f);			// 设置绘图颜色为黑色
	glPointSize(4.0);					// 设置点的大小为4x4像素
	glMatrixMode(GL_PROJECTION);		// 设置合适的矩阵
	glLoadIdentity();					// 后台将解释
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);	// 接下来将完整的说明
}

struct GLintPoint {
	GLint x, y;
};

GLintPoint CP;
//<<<<<<<<<<<<<<<<<< moveto >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void moveTo(GLint x, GLint y)
{
	CP.x = x;					// 更新CP
	CP.y = y;
}
//<<<<<<<<<<<<<<<<<< lineTo >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void lineTo(GLint x, GLint y)
{
	glBegin(GL_LINES);			// 画线
	glVertex2i(CP.x,CP.y);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	CP.x = x;					// 更新CP
	CP.y = y;
}

//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	glClearColor(1.0,1.0,1.0,0.0);		// 设置白色背景
	glClear(GL_COLOR_BUFFER_BIT);		// 清屏
	int width = 10;
	int height = 10;
	for (int row = 0;row < 10;++row) {
		for (int col = 0;col < 10;++col) {
			if ((col+row)%2==0) {
				glColor3f(0.2,0.2,0.2);				// 深灰
			}
			else {
				glColor3f(0.6,0.6,0.6);				// 浅灰
			}
			glRecti(row*width,col*height,width+row*width,height+col*height);
		}
	}
	glFlush();
}

//<<<<<<<<<<<<<<<<<< drawDot >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawDot(int x,int y) 
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
//<<<<<<<<<<<<<<<<<< myMouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myMouse(int button, int state, int x, int y)
{
	static GLintPoint corner[2];
	static int numCorners = 0;
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			corner[numCorners].x = x;
			corner[numCorners].y = screenHeight - y;
			if (++numCorners == 2) {
				glRecti(corner[0].x, corner[0].y, corner[1].x, corner[1].y);
				numCorners = 0;
			}
			glFlush();
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
		}
	}
}
int main(int argc, char **argv)
{
	// GLUT 初始化函数
	glutInit(&argc, argv);							// 初始化工具包
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// 设置显示模式
	glutInitWindowSize(screenWidth, screenHeight);	// 设置窗口大小
	glutInitWindowPosition(100, 100);				// 设置屏幕上窗口位置
	glutCreateWindow("My first OpenGL program");	// 打开带标题的窗口

	glutDisplayFunc(myDisplay);						// 注册重画回调函数
	glutMouseFunc(myMouse);

	myInit();
	glutMainLoop();									// 进入循环
}