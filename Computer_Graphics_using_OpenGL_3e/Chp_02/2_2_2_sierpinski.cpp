// Computer_Graphics_using_OpenGL_3e.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>
#include<random>
#include<ctime>

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

//<<<<<<<<<<<<<<<<<<<< drawDot >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

struct GLintPoint {
	GLfloat x, y;
};

//<<<<<<<<<<<<<<<<<<<< sierpinkdi_render >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void sierpinski_render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLintPoint T[3] = { {10,10},{600,10},{200,450} };
	default_random_engine e;							// ���������
	e.seed(time(0));									// ��ʱ����Ϊ���������
	uniform_int_distribution<unsigned> u(0,2);			// �ض����ʷֲ��������
	GLint index = u(e);									// һ�������
	GLintPoint point = T[index];

	drawDot(point.x, point.y);
	for (int i = 0; i < 100000; ++i) {
		index = u(e);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
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

	glutDisplayFunc(sierpinski_render);						// ע���ػ��ص�����
													//glutMouseFunc(myMouse);
													//glutKeyboardFunc(myKeyboard);
													//glutReshapeFunc(myShape);

	myInit();
	glutMainLoop();									// ����ѭ��
}