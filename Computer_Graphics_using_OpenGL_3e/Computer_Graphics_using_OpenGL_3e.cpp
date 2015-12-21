// Computer_Graphics_using_OpenGL_3e.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

using namespace std;

//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// ���ñ�����ɫΪ��ɫ
	glColor3f(0.0f, 0.0f, 0.0f);			// ���û�ͼ��ɫΪ��ɫ
	glPointSize(4.0);					// ���õ�Ĵ�СΪ4x4����
	glMatrixMode(GL_PROJECTION);		// ���ú��ʵľ���
	glLoadIdentity();					// ��̨������
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);	// ��������������˵��
}

struct GLintPoint {
	GLint x, y;
};

GLintPoint CP;
//<<<<<<<<<<<<<<<<<< moveto >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void moveTo(GLint x, GLint y)
{
	CP.x = x;					// ����CP
	CP.y = y;
}
//<<<<<<<<<<<<<<<<<< lineTo >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void lineTo(GLint x, GLint y)
{
	glBegin(GL_LINES);			// ����
	glVertex2i(CP.x,CP.y);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	CP.x = x;					// ����CP
	CP.y = y;
}

//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		// ����
	moveTo(40,40);
	lineTo(70,123);
}
int main(int argc, char **argv)
{
	// GLUT ��ʼ������
	glutInit(&argc, argv);							// ��ʼ�����߰�
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// ������ʾģʽ
	glutInitWindowSize(640, 480);					// ���ô��ڴ�С
	glutInitWindowPosition(100, 100);				// ������Ļ�ϴ���λ��
	glutCreateWindow("My first OpenGL program");	// �򿪴�����Ĵ���

	glutDisplayFunc(myDisplay);						// ע���ػ��ص�����
													//glutMouseFunc(myMouse);
													//glutKeyboardFunc(myKeyboard);
													//glutReshapeFunc(myShape);

	myInit();
	glutMainLoop();									// ����ѭ��
}