// Computer_Graphics_using_OpenGL_3e.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>
#include<random>
#include<ctime>
#include<cmath>

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;
const GLdouble PI = 3.14159265;
GLdouble A, B, C, D;

using namespace std;


//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// 设置背景颜色为白色
	glColor3f(0.0f, 0.0f, 0.0f);			// 设置绘图颜色为黑色
	glPointSize(2.0);						// 设置点的大小为4x4像素
	glMatrixMode(GL_PROJECTION);			// 设置合适的矩阵
	glLoadIdentity();						// 后台将解释
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);	// 接下来将完整的说明
	A = screenWidth / 4.0;
	B = 0.0;
	C = D = screenHeight / 2.0;
}

//<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (GLdouble x = 0; x < 4.0; x += 0.005) {
		GLdouble func = exp(-x)*cos(2 * PI*x);
		glVertex2d(A * x + B, C * func + D);
	}
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	// GLUT 初始化函数
	glutInit(&argc, argv);							// 初始化工具包
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// 设置显示模式
	glutInitWindowSize(640, 480);					// 设置窗口大小
	glutInitWindowPosition(100, 100);				// 设置屏幕上窗口位置
	glutCreateWindow("My first OpenGL program");	// 打开带标题的窗口

	glutDisplayFunc(myDisplay);						// 注册重画回调函数

	myInit();
	glutMainLoop();									// 进入循环
}