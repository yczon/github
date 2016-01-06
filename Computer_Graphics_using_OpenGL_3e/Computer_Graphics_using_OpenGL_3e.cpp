/****************************************************************************

example5.cpp

A GLUI program demonstrating subwindows, rotation controls,
translation controls, and listboxes

-----------------------------------------------------------------------

7/10/98 Paul Rademacher (rademach@cs.unc.edu)

****************************************************************************/
#include "stdafx.h"
#include <string.h>
#include <GL/glut.h>
#include <GL/glui.h>
#include<random>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void myDisplay(void);
void myInit(void);
void readFromFile(char *fileName);
void myKeyboard(unsigned char key, int x, int y);

struct GLPoint {
	GLint x, y;
};

bool moved = true;                //为了一开始能够显示
GLint xDirection = 0;
GLint yDirection = 0;
static GLint numPolys = 0;        //总共线条的个数
								  //static GLint numLines = 0;

vector <GLPoint> pt;            //用来存放各个顶点的值
vector <GLint> numPoints;        //每条线包含的顶点个数

const GLint screenWidth = 640;
const GLint screenHeight = 480;

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Dinosaur");

	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
	myInit();
	glutMainLoop();

	return 0;
}

void readFromFile(char *fileName) {
	//cout<<a<<" "<<s<<" "<<d<<" "<<w<<endl;
	fstream inStream;
	GLint num;    //记录每条线的顶点个数
	inStream.open(fileName, ios::in);
	if (inStream.fail())
	{
		return;
	}
	cout << "file open succeed" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	inStream >> numPolys;                    //线带的总条数（因为每条线带是多个顶点，顾用poly）
	for (int j = 0;j<numPolys;j++) {        //每条折线
		inStream >> num;
		numPoints.push_back(num);        //每条线带 所包含的 顶点个数
		for (int i = 0;i<num;++i) {
			GLPoint *pp = new GLPoint();
			inStream >> pp->x >> pp->y;
			pt.push_back(*pp);            //顶点值存入数组中
		}
	}

	inStream.close();
	cout << "file closed" << endl;
}

void myKeyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'w':moved = true;xDirection = 0;yDirection = 1;glutPostRedisplay();
		break;
	case 'd':moved = true;xDirection = 1;yDirection = 0;glutPostRedisplay();
		break;
	case 's':moved = true;xDirection = 0;yDirection = -1;glutPostRedisplay();
		break;
	case 'a':moved = true;xDirection = -1;yDirection = 0;glutPostRedisplay();
		break;
	default:break;
	}
}

void myDisplay(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	cout << endl;
	cout << endl;
	cout << endl;
	GLint number = 0;
	for (int j = 0;j<numPolys;j++)        //多少条线，就有多少次循环
	{
		cout << "线条个数：" << numPolys << endl;
		glBegin(GL_LINE_STRIP);
		cout << "顶点坐标：";
		for (int i = 0;i<numPoints[j];i++)
		{
			pt[number].x += xDirection;
			pt[number].y += yDirection;
			glVertex2i(pt[number].x, pt[number].y);
			number++;
		}
		glEnd();
		cout << endl;
	}
	glutSwapBuffers();
}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);

	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

	readFromFile("./Chp_02/dino.dat");

}