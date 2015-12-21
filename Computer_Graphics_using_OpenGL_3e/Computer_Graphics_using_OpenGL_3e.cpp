// Computer_Graphics_using_OpenGL_3e.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;

using namespace std;

struct GLintPoint {
	GLint x, y;
};
GLintPoint corner[2];
bool selected = false;
GLintPoint CP;
//<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(0.0f,1.0f,0.0f);
	if (selected) {
		glBegin(GL_QUADS);
			glVertex2i(corner[0].x,corner[0].y);
			glVertex2i(corner[0].x,corner[1].y);
			glVertex2i(corner[1].x,corner[1].y);
			glVertex2i(corner[1].x,corner[0].y);
		glEnd();
		glFlush();
	}
	glutSwapBuffers();
}

//<<<<<<<<<<<<<<<<<< myMouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		corner[0].x = x;
		corner[0].y = screenHeight - y;
		selected = true;
	}
	glutPostRedisplay();
}
void myPassiveMotion(int x, int y)
{
	corner[1].x = x;
	corner[1].y = screenHeight - y;
	glutPostRedisplay();
}
int main(int argc, char **argv)
{
	// GLUT ��ʼ������
	glutInit(&argc, argv);							// ��ʼ�����߰�
	glutInitWindowSize(screenWidth, screenHeight);	// ���ô��ڴ�С
	glutInitWindowPosition(0, 0);					// ������Ļ�ϴ���λ��
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// ������ʾģʽ
	glutCreateWindow("My first OpenGL program");	// �򿪴�����Ĵ���
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,screenWidth,0,screenHeight);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);			// ����Ϊ��ɫ
	glViewport(0,0,screenWidth,screenHeight);
	glutMouseFunc(myMouse);
	glutDisplayFunc(myDisplay);						// ע���ػ��ص�����
	glutPassiveMotionFunc(myPassiveMotion);

	glutMainLoop();									// ����ѭ��
	return 0;
}