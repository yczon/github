#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;
//����ʾ����̨����  
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	//���ָ��ߣ��ֳ��ĸ��Ӽ���  
	glViewport(0, 0, 400, 400);
	glBegin(GL_LINES);
	glVertex2f(-1.0, 0);
	glVertex2f(1.0, 0);
	glVertex2f(0.0, -1.0);
	glVertex2f(0.0, 1.0);
	glEnd();

	//���������½ǵ�����  
	glColor3f(0.0, 1.0, 0.0);
	glViewport(0, 0, 200, 200);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();


	//���������Ͻǵ�����  
	glColor3f(0.0, 0.0, 1.0);
	glViewport(200, 200, 200, 200);//ע�⣬���������������Ǹ߶ȺͿ�ȣ�����������  
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();

	//���������Ͻǵ�����  
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0, 200, 200, 200);//ע�⣬���������������Ǹ߶ȺͿ�ȣ�����������  
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();

	//���������½�  
	glColor3f(1.0, 1.0, 1.0);
	glViewport(200, 0, 200, 200);//ע�⣬���������������Ǹ߶ȺͿ�ȣ�����������  
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
	//���������  
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