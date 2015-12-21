// Computer_Graphics_using_OpenGL_3e.cpp : �������̨Ӧ�ó������ڵ㡣
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

	glClearColor(1.0, 1.0, 1.0, 0.0);		// ���ñ�����ɫΪ��ɫ
	glColor3f(0.0f, 0.0f, 0.0f);			// ���û�ͼ��ɫΪ��ɫ
	glPointSize(4.0);					// ���õ�Ĵ�СΪ4x4����
	glMatrixMode(GL_PROJECTION);		// ���ú��ʵľ���
	glLoadIdentity();					// ��̨������
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);	// ��������������˵��
}
//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		// ����
	glBegin(GL_POINTS);					// ��һЩ�㣨��֪�����٣�
	glVertex2i(289, 190);
	glVertex2i(320, 128);
	glVertex2i(239, 67);
	glVertex2i(194, 101);
	glVertex2i(129, 83);
	glVertex2i(75, 73);
	glVertex2i(20, 10);
	glEnd();
	glFlush();							// �������������ʾ�豸
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