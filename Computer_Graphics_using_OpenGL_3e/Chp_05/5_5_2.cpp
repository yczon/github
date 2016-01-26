#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;
GLPoint currPos;
GLPoint CP;
GLLine line;

GLPoint h[] = { { 0,0 },{ 15,0 },{ 20,10 },{ 22,12 },{ 17,0 },
				{30,0},{35,7},{37,5},{32,0},{40,0} };

void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// ���ñ�����ɫΪ��ɫ
	glColor3f(0.0f, 0.0f, 0.0f);			// ���û�ͼ��ɫΪ��ɫ
	glPointSize(2.0);						// ���õ�Ĵ�СΪ4x4����
	glMatrixMode(GL_PROJECTION);			// ���ú��ʵľ���
	glLoadIdentity();						// ��̨������
	gluOrtho2D(-320, 320, -240, 240);			// ��������������˵��
}

void flakeMotif()
{
	GLLine line;
	// house
	for (int i = 0;i < 9;++i) {
		line.moveTo(h[i]);
		line.lineTo(h[i+1]);
	}
}
//<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	setColor(string("blue"));
	initCT();
	for (int count = 0;count < 6;count++) {
		flakeMotif();
		scale2D(1.0,-1.0);
		flakeMotif();
		scale2D(1.0, -1.0);
		rotate2D(60.0);
	}
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