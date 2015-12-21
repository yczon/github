// Computer_Graphics_using_OpenGL_3e.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

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

struct GLintPoint {
	GLint x, y;
};

//<<<<<<<<<<<<<<<<<< parameterizeHouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void parameterizeHouse(GLintPoint peak, GLint width, GLint height)
// 房子的顶点：peak，给定房子的大小：width,height
{
	glBegin(GL_LINE_LOOP);										// 画房子的外形
	glVertex2i(peak.x, peak.y);
	glVertex2i(peak.x + width, peak.y);
	glVertex2i(peak.x + width, peak.y + 5 * height / 8);
	glVertex2i(peak.x + width / 2, peak.y + height);
	glVertex2i(peak.x, peak.y + 5 * height / 8);
	glEnd();

	glBegin(GL_LINE_STRIP);										// 画烟囱
	glVertex2i(peak.x + width / 6, peak.y + 6 * height / 8);
	glVertex2i(peak.x + width / 6, peak.y + height);
	glVertex2i(peak.x + width / 3, peak.y + height);
	glVertex2i(peak.x + width / 3, peak.y + 7 * height / 8);
	glEnd();

	glBegin(GL_LINE_STRIP);										// 画门
	glVertex2i(peak.x + width / 6, peak.y);
	glVertex2i(peak.x + width / 6, peak.y + height / 2);
	glVertex2i(peak.x + width / 3, peak.y + height / 2);
	glVertex2i(peak.x + width / 3, peak.y);
	glEnd();


	glBegin(GL_LINE_LOOP);										// 画窗户
	glVertex2i(peak.x + 4 * width / 6, peak.y + 4 * height / 8);
	glVertex2i(peak.x + 5 * width / 6, peak.y + 4 * height / 8);
	glVertex2i(peak.x + 5 * width / 6, peak.y + 5 * height / 8);
	glVertex2i(peak.x + 4 * width / 6, peak.y + 5 * height / 8);
	glEnd();



}
//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	GLintPoint p;
	glClear(GL_COLOR_BUFFER_BIT);		// 清屏
	p.x = 10, p.y = 50;
	parameterizeHouse(p, 50, 70);

	p.x = 60, p.y = 120;
	parameterizeHouse(p, 30, 40);

	p.x = 100, p.y = 10;
	parameterizeHouse(p, 30, 80);

	p.x = 200, p.y = 10;
	parameterizeHouse(p, 90, 70);
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