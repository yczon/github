// Computer_Graphics_using_OpenGL_3e.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>
#include<random>
#include<ctime>
#include<cmath>

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;
const GLdouble PI = 3.14159265;
GLdouble A, B, C, D;

using namespace std;


//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// ���ñ�����ɫΪ��ɫ
	glColor3f(0.0f, 0.0f, 0.0f);			// ���û�ͼ��ɫΪ��ɫ
	glPointSize(2.0);						// ���õ�Ĵ�СΪ4x4����
	glMatrixMode(GL_PROJECTION);			// ���ú��ʵľ���
	glLoadIdentity();						// ��̨������
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);	// ��������������˵��
	A = screenWidth / 4.0;
	B = 0.0;
	C = D = screenHeight / 2.0;
}

//<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (GLdouble x = 0; x < 4.0; x += 0.005) {
		GLdouble func = exp(-x)*cos(2 * PI*x);
		glVertex2d(A * x + B, C * func + D);
	}
	glEnd();
	glFlush();
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

	myInit();
	glutMainLoop();									// ����ѭ��
}