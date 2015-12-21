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

//<<<<<<<<<<<<<<<<<< parameterizeHouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void parameterizeHouse(GLintPoint peak, GLint width, GLint height)
// ���ӵĶ��㣺peak���������ӵĴ�С��width,height
{
	glBegin(GL_LINE_LOOP);										// �����ӵ�����
	glVertex2i(peak.x, peak.y);
	glVertex2i(peak.x + width, peak.y);
	glVertex2i(peak.x + width, peak.y + 5 * height / 8);
	glVertex2i(peak.x + width / 2, peak.y + height);
	glVertex2i(peak.x, peak.y + 5 * height / 8);
	glEnd();

	glBegin(GL_LINE_STRIP);										// ���̴�
	glVertex2i(peak.x + width / 6, peak.y + 6 * height / 8);
	glVertex2i(peak.x + width / 6, peak.y + height);
	glVertex2i(peak.x + width / 3, peak.y + height);
	glVertex2i(peak.x + width / 3, peak.y + 7 * height / 8);
	glEnd();

	glBegin(GL_LINE_STRIP);										// ����
	glVertex2i(peak.x + width / 6, peak.y);
	glVertex2i(peak.x + width / 6, peak.y + height / 2);
	glVertex2i(peak.x + width / 3, peak.y + height / 2);
	glVertex2i(peak.x + width / 3, peak.y);
	glEnd();


	glBegin(GL_LINE_LOOP);										// ������
	glVertex2i(peak.x + 4 * width / 6, peak.y + 4 * height / 8);
	glVertex2i(peak.x + 5 * width / 6, peak.y + 4 * height / 8);
	glVertex2i(peak.x + 5 * width / 6, peak.y + 5 * height / 8);
	glVertex2i(peak.x + 4 * width / 6, peak.y + 5 * height / 8);
	glEnd();



}
//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	GLintPoint p;
	glClear(GL_COLOR_BUFFER_BIT);		// ����
	p.x = 10, p.y = 50;
	parameterizeHouse(p, 50, 70);

	p.x = 60, p.y = 120;
	parameterizeHouse(p, 30, 40);

	p.x = 100, p.y = 10;
	parameterizeHouse(p, 30, 80);

	p.x = 200, p.y = 10;
	parameterizeHouse(p, 90, 70);
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