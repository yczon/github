#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;
GLPoint currPos;
GLPoint CP;
GLLine line;

GLPoint h[] = { { 0,0 },{ 0,20 },{ 10,30 },{ 20,20 },{ 20,0 },{0,0} };
GLPoint door[] = { {10,0},{10,10},{15,10},{15,0} };
GLPoint B[] = { { 30,10 },{ 30,40 },{ 10,40 },{ 10,60 },{ 40,90 },{ 70,60 },{ 70,40 },{ 50,40 },{ 50,10 },{ 30,10 } };

void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// ���ñ�����ɫΪ��ɫ
	glColor3f(0.0f, 0.0f, 0.0f);			// ���û�ͼ��ɫΪ��ɫ
	glPointSize(2.0);						// ���õ�Ĵ�СΪ4x4����
	glMatrixMode(GL_PROJECTION);			// ���ú��ʵľ���
	glLoadIdentity();						// ��̨������
	gluOrtho2D(-320, 320, -240, 240);			// ��������������˵��
}

void house()
{
	GLLine line;
	// house
	for (int i = 0;i < 5;++i) {
		line.moveTo(h[i]);
		line.lineTo(h[i+1]);
	}
	// door
	for (int i = 0;i < 3;++i) {
		line.moveTo(door[i]);
		line.lineTo(door[i+1]);
	}

}
//<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	setColor(string("blue"));
	initCT();
	house();
	translate2D(32,25);
	rotate2D(-30.0);
	house();
	glFlush();
}
//------main------
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("The Famous Sinc Function");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}