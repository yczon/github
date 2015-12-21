// Computer_Graphics_using_OpenGL_3e.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;

using namespace std;

float angle = 0.0;
float red = 1.0, blue = 1.0, green = 1.0;

//<<<<<<<<<<<<<<<<<< myMouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void renderScene(void)
// 画三角形的回调函数
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle,0.0,1.0,0.0);		// 一点点旋转三角形
	glColor3f(red, green, blue);		// 改变三角形的颜色
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,0.0,0.0);
	glVertex3f(0.0,0.5,0.0);
	glEnd();
	angle++;
	glutSwapBuffers();
}
//<<<<<<<<<<<<<<<<<< processMenuEvents >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void procesMenuEvents(int option)
{
	switch (option) {
	case RED:red = 1.0; green = 0.0, blue = 0.0; break;
	case GREEN:red = 0.0; green = 1.0, blue = 0.0; break;
	case BLUE:red = 0.0; green = 0.0, blue = 1.0; break;
	case WHITE:red = 1.0; green = 1.0, blue = 1.0; break;
	}
}
//----------------- MAIN ----------------------
int main(int argc, char **argv)
{
	glutInit(&argc, argv);							// 初始化工具包
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	// 设置显示模式
	glutInitWindowPosition(100, 100);					// 设置屏幕上窗口位置
	glutInitWindowSize(screenWidth, screenHeight);	// 设置窗口大小
	glutCreateWindow("Menu Test");	// 打开带标题的窗口

	glutDisplayFunc(renderScene);						// 注册重画回调函数
	glutIdleFunc(renderScene);

	glutCreateMenu(procesMenuEvents);				// 调用函数创建菜单
	glutAddMenuEntry("Red",RED);					// 关联菜单事件
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("White",WHITE);
	glutAttachMenu(GLUT_RIGHT_BUTTON);				// 系在右鼠标按钮上
	glutMainLoop();									// 进入循环
	return 0;
}