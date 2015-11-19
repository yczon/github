#include"stdafx.h"
#include<GL/glut.h>
#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include"calculator/Axis.h"
#include"calculator/Display.h"
#include"calculator/Athmetic.h"

using namespace std;

GLsizei winWidth = 400, winHeight = 700;

Display cal(winWidth,winHeight);

vector<char> num;
vector<vector<char>> ivec;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);				// White display window.
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));

	glClear(GL_COLOR_BUFFER_BIT);
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
	Axis coor(xMouse,winHeight-yMouse,cal.wButton,cal.hButton);

	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
	{
		cal.key_down(coor.x1,coor.y1,coor.x2,coor.y2,&coor.w);
		switch (coor.w) {
		case 'E':
			ivec.push_back(num);
			num.clear();
			cal.enter(ivec);
			break;
		case 'B':
			num.pop_back();
			cal.backspace(num);
			break;
		case 'C':
			num.clear();
			cal.clear();
			break;
		case '+':
			if (ivec.size() > 1){
				Athmetic counter(ivec[ivec.size()], ivec[ivec.size() - 1]);
				counter.a_add();
			}
			else {
				cal.print_v(ivec[0],1);
			}
			break;
		case '-':
			break;
		case '*':
			break;
		case '/':
			break;
		default:
			num.push_back(coor.w);
			cal.print(num);
			break;
		}
	}
	if (button == GLUT_LEFT_BUTTON && action == GLUT_UP)
	{
		cal.key_up(coor.x1,coor.y1,coor.x2,coor.y2,&coor.w);
	}

	glFlush();
}

void display(void)
{
	cal.iniWindow();
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("������");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFcn);

	glutMouseFunc(mousePtPlot);

	glutMainLoop();
}

