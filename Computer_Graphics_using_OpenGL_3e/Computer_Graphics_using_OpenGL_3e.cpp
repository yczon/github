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

//<<<<<<<<<<<<<<<<<< hardwiredHouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void hardwiredHouse(void)
{
	glBegin(GL_LINE_LOOP);			// �����ӵ�����
		glVertex2i(40,40);
		glVertex2i(40,90);
		glVertex2i(70,120);
		glVertex2i(100,90);
		glVertex2i(100,40);
	glEnd();
	glBegin(GL_LINE_STRIP);			// ���̴�
		glVertex2i(50, 100);
		glVertex2i(50, 120);
		glVertex2i(60, 120);
		glVertex2i(60, 110);
	glEnd();
	glBegin(GL_LINE_STRIP);			// ����
		glVertex2i(50,40);
		glVertex2i(50,75);
		glVertex2i(65,75);
		glVertex2i(65,40);
	glEnd();
	glBegin(GL_LINE_LOOP);			// ������
		glVertex2i(80,70);
		glVertex2i(90,70);
		glVertex2i(90,80);
		glVertex2i(80,80);
	glEnd();

}

//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		// ����
	hardwiredHouse();
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