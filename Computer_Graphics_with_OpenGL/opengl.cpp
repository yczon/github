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
int result = 0;

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
			ivec.clear();
			cal.clear();
			break;
		case '+':
			if (num.begin() == num.end())
			{
				if (ivec.size() > 1) {
					Athmetic counter(ivec[ivec.size() - 2], ivec[ivec.size() - 1]);
					result = counter.a_add();
					ivec.pop_back();
					ivec.pop_back();
					cal.print_v(counter.itov(result), 0);
				}
			}
			else {
				if (ivec.begin() != ivec.end()) {
					Athmetic counter(ivec[ivec.size() - 1],num);
					int result = counter.a_add();
					cal.clear();
					cal.print_v(ivec[ivec.size()-1],2);
					cal.print_v(num,1);
					cal.print_v(counter.itov(result), 0);
					num.clear();

				}
				else{
					cal.clear();
					cal.print_v(num,0);
				}
			}
			break;
		case '-':
			if (num.begin() == num.end())
			{
				if (ivec.size() > 1) {
					Athmetic counter(ivec[ivec.size() - 2], ivec[ivec.size() - 1]);
					int result = counter.a_minus();
					cal.print_v(counter.itov(result), 0);
				}
			}
			else {
				if (ivec.begin() != ivec.end()) {
					Athmetic counter(ivec[ivec.size() - 1],num);
					int result = counter.a_minus();
					cal.clear();
					cal.print_v(ivec[ivec.size() - 1], 2);
					cal.print_v(num, 1);
					cal.print_v(counter.itov(result), 0);
					num.clear();
				}
				else {
					cal.clear();
					cal.print_v(num, 0);
				}
			}
			break;
		case '*':
			if (num.begin() == num.end())
			{
				if (ivec.size() > 1) {
					Athmetic counter(ivec[ivec.size() - 2], ivec[ivec.size() - 1]);
					int result = counter.a_mul();
					cal.print_v(counter.itov(result), 0);
				}
			}
			else {
				if (ivec.begin() != ivec.end()) {
					Athmetic counter(ivec[ivec.size() - 1],num);
					int result = counter.a_mul();
					cal.clear();
					cal.print_v(ivec[ivec.size() - 1], 2);
					cal.print_v(num, 1);
					cal.print_v(counter.itov(result), 0);
					num.clear();
				}
				else {
					cal.clear();
					cal.print_v(num, 0);
				}
			}
			break;
		case '/':
			if (num.begin() == num.end())
			{
				if (ivec.size() > 1) {
					Athmetic counter(ivec[ivec.size() - 2], ivec[ivec.size() - 1]);
					int result = counter.a_div();
					cal.print_v(counter.itov(result), 0);
				}
			}
			else {
				if (ivec.begin() != ivec.end()) {
					Athmetic counter(ivec[ivec.size() - 1],num);
					int result = counter.a_div();
					cal.clear();
					cal.print_v(ivec[ivec.size() - 1], 2);
					cal.print_v(num, 1);
					cal.print_v(counter.itov(result), 0);
					num.clear();
				}
				else {
					cal.clear();
					cal.print_v(num, 0);
				}
			}
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
	glutCreateWindow("¼ÆËãÆ÷");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFcn);

	glutMouseFunc(mousePtPlot);

	glutMainLoop();
}

