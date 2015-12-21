// Computer_Graphics_using_OpenGL_3e.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>
#include<fstream>
#include<random>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<ios>

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;
const GLdouble PI = 3.14159265;
GLdouble A, B, C, D;

using namespace std;


//<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// ���ñ�����ɫΪ��ɫ
	glColor3f(0.0f, 0.0f, 0.0f);			// ���û�ͼ��ɫΪ��ɫ
	glLineWidth(4.0);						// ���õ�Ĵ�СΪ4x4����
	glMatrixMode(GL_PROJECTION);			// ���ú��ʵľ���
	glLoadIdentity();						// ��̨������
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);	// ��������������˵��
	A = screenWidth / 4.0;
	B = 0.0;
	C = D = screenHeight / 2.0;
}
//<<<<<<<<<<<<<<<<<<<< drawLine >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{
	glBegin(GL_LINES);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
	glEnd();
}
//<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (size_t x = 0; x < screenWidth / 2; x += 0.005) {
		GLint func = 3 * x;
		glVertex2i(x,func);
	}
	glEnd();
	glFlush();
}
//<<<<<<<<<<<<<<<<<<<< drawPolyLineFile >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

string fileName;
void drawPolyLineFile()
{
	fstream inStream;
	fileName = "dino.txt";
	inStream.open(fileName, ios::in);
	if (inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;
	for (int j = 0; j < numpolys; j++) {
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++) {
			inStream >> x >> y;
			glVertex2i(x,y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

int main(int argc, char **argv)
{
	// GLUT ��ʼ������
	glutInit(&argc, argv);							// ��ʼ�����߰�
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// ������ʾģʽ
	glutInitWindowSize(640, 480);					// ���ô��ڴ�С
	glutInitWindowPosition(100, 100);				// ������Ļ�ϴ���λ��
	glutCreateWindow("My first OpenGL program");	// �򿪴�����Ĵ���

	glutDisplayFunc(drawPolyLineFile);						// ע���ػ��ص�����

	myInit();
	glutMainLoop();									// ����ѭ��
}