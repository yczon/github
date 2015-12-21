// Computer_Graphics_using_OpenGL_3e.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

using namespace std;

void myMouse(int button, int state, int x, int y) {
}
void myKeyboard(unsigned char key, int x, int y) {

}
void myShape(int w, int h) {

}
//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// 设置背景颜色为白色
	glColor3f(0.0f, 0.0f, 0.0f);			// 设置绘图颜色为黑色
	glPointSize(4.0);					// 设置点的大小为4x4像素
	glMatrixMode(GL_PROJECTION);		// 设置合适的矩阵
	glLoadIdentity();					// 后台将解释
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);	// 接下来将完整的说明
}

//<<<<<<<<<<<<<<<<<< hardwiredHouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void hardwiredHouse(void)
{
	glBegin(GL_LINE_LOOP);			// 画房子的外形
		glVertex2i(40,40);
		glVertex2i(40,90);
		glVertex2i(70,120);
		glVertex2i(100,90);
		glVertex2i(100,40);
	glEnd();
	glBegin(GL_LINE_STRIP);			// 画烟囱
		glVertex2i(50, 100);
		glVertex2i(50, 120);
		glVertex2i(60, 120);
		glVertex2i(60, 110);
	glEnd();
	glBegin(GL_LINE_STRIP);			// 画门
		glVertex2i(50,40);
		glVertex2i(50,75);
		glVertex2i(65,75);
		glVertex2i(65,40);
	glEnd();
	glBegin(GL_LINE_LOOP);			// 画窗户
		glVertex2i(80,70);
		glVertex2i(90,70);
		glVertex2i(90,80);
		glVertex2i(80,80);
	glEnd();

}

//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		// 清屏
	hardwiredHouse();
	glFlush();							// 送所有输出到显示设备
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
													//glutMouseFunc(myMouse);
													//glutKeyboardFunc(myKeyboard);
													//glutReshapeFunc(myShape);

	myInit();
	glutMainLoop();									// 进入循环
}