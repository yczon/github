// Computer_Graphics_using_OpenGL_3e.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;

using namespace std;

//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// ���ñ�����ɫΪ��ɫ
	glColor3f(0.0f, 0.0f, 0.0f);			// ���û�ͼ��ɫΪ��ɫ
	glPointSize(4.0);					// ���õ�Ĵ�СΪ4x4����
	glMatrixMode(GL_PROJECTION);		// ���ú��ʵľ���
	glLoadIdentity();					// ��̨������
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);	// ��������������˵��
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
	glClearColor(1.0,1.0,1.0,0.0);		// ���ð�ɫ����
	glClear(GL_COLOR_BUFFER_BIT);		// ����
	int width = 10;
	int height = 10;
	for (int row = 0;row < 10;++row) {
		for (int col = 0;col < 10;++col) {
			if ((col+row)%2==0) {
				glColor3f(0.2,0.2,0.2);				// ���
			}
			else {
				glColor3f(0.6,0.6,0.6);				// ǳ��
			}
			glRecti(row*width,col*height,width+row*width,height+col*height);
		}
	}
	glFlush();
}

//<<<<<<<<<<<<<<<<<< drawDot >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawDot(int x,int y) 
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
//<<<<<<<<<<<<<<<<<< myMouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myMouse(int button, int state, int x, int y)
{
	static GLintPoint corner[2];
	static int numCorners = 0;
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			corner[numCorners].x = x;
			corner[numCorners].y = screenHeight - y;
			if (++numCorners == 2) {
				glRecti(corner[0].x, corner[0].y, corner[1].x, corner[1].y);
				numCorners = 0;
			}
			glFlush();
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
		}
	}
}
int main(int argc, char **argv)
{
	// GLUT ��ʼ������
	glutInit(&argc, argv);							// ��ʼ�����߰�
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// ������ʾģʽ
	glutInitWindowSize(screenWidth, screenHeight);	// ���ô��ڴ�С
	glutInitWindowPosition(100, 100);				// ������Ļ�ϴ���λ��
	glutCreateWindow("My first OpenGL program");	// �򿪴�����Ĵ���

	glutDisplayFunc(myDisplay);						// ע���ػ��ص�����
	glutMouseFunc(myMouse);

	myInit();
	glutMainLoop();									// ����ѭ��
}