// Computer_Graphics_using_OpenGL_3e.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>
#include<fstream>
#include<random>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<ios>

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;
const GLdouble PI = 3.14159265;
GLdouble A, B, C, D;

using namespace std;


//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// 设置背景颜色为白色
	glColor3f(0.0f, 0.0f, 0.0f);			// 设置绘图颜色为黑色
	glLineWidth(4.0);						// 设置点的大小为4x4像素
	glMatrixMode(GL_PROJECTION);			// 设置合适的矩阵
	glLoadIdentity();						// 后台将解释
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);	// 接下来将完整的说明
	A = screenWidth / 4.0;
	B = 0.0;
	C = D = screenHeight / 2.0;
}
//<<<<<<<<<<<<<<<<<<<< drawLine >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{
	glBegin(GL_LINES);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
	glEnd();
}
//<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (size_t x = 0; x < screenWidth / 2; x += 0.005) {
		GLint func = 3 * x;
		glVertex2i(x,func);
	}
	glEnd();
	glFlush();
}
//<<<<<<<<<<<<<<<<<<<< drawPolyLineFile >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

string fileName;
void drawPolyLineFile()
{
	fstream inStream;
	fileName = "dino.txt";
	inStream.open(fileName, ios::in);
	if (inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;
	for (int j = 0; j < numpolys; j++) {
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++) {
			inStream >> x >> y;
			glVertex2i(x,y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

int main(int argc, char **argv)
{
	// GLUT 初始化函数
	glutInit(&argc, argv);							// 初始化工具包
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// 设置显示模式
	glutInitWindowSize(640, 480);					// 设置窗口大小
	glutInitWindowPosition(100, 100);				// 设置屏幕上窗口位置
	glutCreateWindow("My first OpenGL program");	// 打开带标题的窗口

	glutDisplayFunc(drawPolyLineFile);						// 注册重画回调函数

	myInit();
	glutMainLoop();									// 进入循环
}