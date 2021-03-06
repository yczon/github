#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;
GLPoint currPos;
GLPoint CP;
GLLine line;

GLPoint h[] = { { 0,0 },{ 0,20 },{ 10,30 },{ 20,20 },{ 20,0 },{0,0} };
GLPoint door[] = { {10,0},{10,10},{15,10},{15,0} };
GLPoint B[] = { { 0,50 },{ 15,10 },{ 5,10 },{ 0,30 },{ -15,-10 },
			    { -20,0 },{ 0,50 } };

void myInit() {

	glClearColor(1.0, 1.0, 1.0, 0.0);		// 设置背景颜色为白色
	glColor3f(0.0f, 0.0f, 0.0f);			// 设置绘图颜色为黑色
	glPointSize(2.0);						// 设置点的大小为4x4像素
	glMatrixMode(GL_PROJECTION);			// 设置合适的矩阵
	glLoadIdentity();						// 后台将解释
	gluOrtho2D(-320, 320, -240, 240);			// 接下来将完整的说明
}

void startMotif()
{
	GLLine line;
	// house
	for (int i = 0;i < 6;++i) {
		line.moveTo(B[i]);
		line.lineTo(B[i+1]);
	}
}
//<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	setColor(string("blue"));
	initCT();
	for (int count = 0;count < 5;count++) {
		startMotif();
		rotate2D(72.0);
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