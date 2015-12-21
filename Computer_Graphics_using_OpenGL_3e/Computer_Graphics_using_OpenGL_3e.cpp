// Computer_Graphics_using_OpenGL_3e.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<GL/glut.h>
#include<iostream>

#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4

const GLdouble screenWidth = 640;
const GLdouble screenHeight = 480;

using namespace std;

float angle = 0.0;
float red = 1.0, blue = 1.0, green = 1.0;

//<<<<<<<<<<<<<<<<<< myMouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void renderScene(void)
// �������εĻص�����
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle,0.0,1.0,0.0);		// һ�����ת������
	glColor3f(red, green, blue);		// �ı������ε���ɫ
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,0.0,0.0);
	glVertex3f(0.0,0.5,0.0);
	glEnd();
	angle++;
	glutSwapBuffers();
}
//<<<<<<<<<<<<<<<<<< processMenuEvents >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void procesMenuEvents(int option)
{
	switch (option) {
	case RED:red = 1.0; green = 0.0, blue = 0.0; break;
	case GREEN:red = 0.0; green = 1.0, blue = 0.0; break;
	case BLUE:red = 0.0; green = 0.0, blue = 1.0; break;
	case WHITE:red = 1.0; green = 1.0, blue = 1.0; break;
	}
}
//----------------- MAIN ----------------------
int main(int argc, char **argv)
{
	glutInit(&argc, argv);							// ��ʼ�����߰�
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	// ������ʾģʽ
	glutInitWindowPosition(100, 100);					// ������Ļ�ϴ���λ��
	glutInitWindowSize(screenWidth, screenHeight);	// ���ô��ڴ�С
	glutCreateWindow("Menu Test");	// �򿪴�����Ĵ���

	glutDisplayFunc(renderScene);						// ע���ػ��ص�����
	glutIdleFunc(renderScene);

	glutCreateMenu(procesMenuEvents);				// ���ú��������˵�
	glutAddMenuEntry("Red",RED);					// �����˵��¼�
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("White",WHITE);
	glutAttachMenu(GLUT_RIGHT_BUTTON);				// ϵ������갴ť��
	glutMainLoop();									// ����ѭ��
	return 0;
}