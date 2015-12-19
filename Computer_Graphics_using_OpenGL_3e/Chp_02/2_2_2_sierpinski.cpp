// Computer_Graphics_using_OpenGL_3e.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>
#include<random>
#include<ctime>

using namespace std;


//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// 设置背景颜色为白色
	glColor3f(0.0f, 0.0f, 0.0f);			// 设置绘图颜色为黑色
	glPointSize(4.0);					// 设置点的大小为4x4像素
	glMatrixMode(GL_PROJECTION);		// 设置合适的矩阵
	glLoadIdentity();					// 后台将解释
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);	// 接下来将完整的说明
}

//<<<<<<<<<<<<<<<<<<<< drawDot >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

struct GLintPoint {
	GLfloat x, y;
};

//<<<<<<<<<<<<<<<<<<<< sierpinkdi_render >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void sierpinski_render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLintPoint T[3] = { {10,10},{600,10},{200,450} };
	default_random_engine e;							// 随机数引擎
	e.seed(time(0));									// 以时间作为随机数种子
	uniform_int_distribution<unsigned> u(0,2);			// 特定概率分布的随机数
	GLint index = u(e);									// 一个随机数
	GLintPoint point = T[index];

	drawDot(point.x, point.y);
	for (int i = 0; i < 100000; ++i) {
		index = u(e);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
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

	glutDisplayFunc(sierpinski_render);						// 注册重画回调函数
													//glutMouseFunc(myMouse);
													//glutKeyboardFunc(myKeyboard);
													//glutReshapeFunc(myShape);

	myInit();
	glutMainLoop();									// 进入循环
}