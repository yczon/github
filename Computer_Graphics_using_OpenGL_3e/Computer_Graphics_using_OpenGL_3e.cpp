#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;
//不显示控制台窗口  
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

const GLsizei winWidth = 640;
const GLsizei winHeight = 480;

GLdouble coorLeft = -1*(winWidth/winHeight);
GLdouble coorRight = 1*(winWidth/winHeight);
GLdouble coorBottom = -1;
GLdouble coorTop = 1;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);  // 白色

	glViewport(0, 0, winWidth, winHeight);//注意，后面这两个参数是高度和宽度，而不是坐标  

	int N = 5;
	GLPoint *pointlist = new GLPoint[N];
	GLfloat theta = (2.0f * PI) / N;
	GLLine line;
	GLfloat radius = 0.5;
	for (int c = 0; c < N; c++) {
		pointlist[c].set(radius*sin(theta*c), radius*cos(theta*c));
	}
	for (int i = 0; i < N-1; i++) {
		line.moveTo(pointlist[i]);
		line.lineTo(pointlist[i+1]);
	}
	line.moveTo(pointlist[0]);
	line.lineTo(pointlist[N-1]);

	glFlush();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glViewport(0,0,winWidth,winHeight);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//定义剪裁面  
	//gluOrtho2D(coorLeft,coorRight,coorBottom,coorTop);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//定义剪裁面  
	if (w <= h)
		glOrtho(-1, 1, -1 * (GLfloat)h / (GLfloat)w, 1 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1*(GLfloat)w / (GLfloat)h, 1*(GLfloat)w / (GLfloat)h, -1, 1, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("glviewport");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}
