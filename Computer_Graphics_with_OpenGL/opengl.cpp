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
int result = 0;

GLsizei winWidth = 400, winHeight = 700;

Display cal(winWidth,winHeight);

vector<char> num;
//vector<vector<char>> ivec;
vector<int> ivec;

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
//数字转 vector 数组
vector<char> itov(int i) {
	std::vector<char> result;
	std::vector<char> res;

	char str[20];
	int tmp = 0;
	if (i < 0)
	{
		tmp = -i;
		res.push_back('-');
	}
	else
		tmp = i;
	int aa = 0;
	do
	{
		aa = tmp % 10;
		tmp = tmp / 10;
		_itoa_s(aa, str, 2, 10);
		result.push_back(*str);
	} while (tmp != 0);

	for (auto v = result.rbegin();v != result.rend();++v) {
		res.push_back(*v);
		cout << *v << endl;
	}

	return res;
}
// vector 数组转 数字
int vtoi(std::vector<char> v) {

	int result = 0;
	size_t n = 0;
	int tmp = 0;

	for (auto i = v.rbegin();i != v.rend();++i)
	{
		// 会发生隐式转换 char 转 int  '1' = 49
		tmp = (int)(*i);
		tmp = tmp - 48;
		result += pow(10, n) * (tmp);
		++n;
	}

	return result;
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
	Axis coor(xMouse,winHeight-yMouse,cal.wButton,cal.hButton);

	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
	{
		cal.key_down(coor.x1,coor.y1,coor.x2,coor.y2,&coor.w);
		switch (coor.w) {
		case 'E':
			ivec.push_back(vtoi(num));
			num.clear();
			cal.print_v(num,1);
			break;
		case 'B':
			num.pop_back();
			cal.backspace(num);
			break;
		case 'C':
			num.clear();
			ivec.clear();
			cal.clear();
			result = 0;
			break;
		case '+':
			if (num.begin() == num.end()) {
				if (ivec.size() > 1 && ivec.size() != 1) {
					Athmetic counter(*(ivec.end() - 2), *(ivec.end() - 1));
					result = counter.a_add();
					ivec.pop_back();
					ivec.pop_back();
					ivec.push_back(result);
					cal.clear();
					cal.print_v(itov(result), 0);
				}
			}
			else {
				if (ivec.begin() != ivec.end()) {
					Athmetic counter(ivec[ivec.size() - 1], vtoi(num));
					num.clear();
					result = counter.a_add();
					ivec.pop_back();
					ivec.push_back(result);
					cal.clear();
					cal.print_v(itov(result), 0);
				}
			}
			break;
		case '-':
			if (num.begin() == num.end()){
				if (ivec.size() > 1 && ivec.size() != 1) {
					Athmetic counter(*(ivec.end()-2), *(ivec.end() - 1));
					result = counter.a_minus();
					ivec.pop_back();
					ivec.pop_back();
					ivec.push_back(result);
					cal.clear();
					cal.print_v(itov(result), 0);
				}
			}
			else {
				if (ivec.begin() != ivec.end()) {
					Athmetic counter(ivec[ivec.size() - 1], vtoi(num));
					num.clear();
					result = counter.a_minus();
					ivec.pop_back();
					ivec.push_back(result);
					cal.clear();
					cal.print_v(itov(result), 0);
				}
			}
			break;
		case '*':
			if (num.begin() == num.end()) {
				if (ivec.size() > 1 && ivec.size() != 1) {
					Athmetic counter(*(ivec.end() - 2), *(ivec.end() - 1));
					result = counter.a_mul();
					ivec.pop_back();
					ivec.pop_back();
					ivec.push_back(result);
					cal.clear();
					cal.print_v(itov(result), 0);
				}
			}
			else {
				if (ivec.begin() != ivec.end()) {
					Athmetic counter(ivec[ivec.size() - 1], vtoi(num));
					num.clear();
					result = counter.a_mul();
					ivec.pop_back();
					ivec.push_back(result);
					cal.clear();
					cal.print_v(itov(result), 0);
				}
			}
			break;
		case '/':
			if (num.begin() == num.end()) {
				if (ivec.size() > 1 && ivec.size() != 1) {
					Athmetic counter(*(ivec.end() - 2), *(ivec.end() - 1));
					result = counter.a_div();
					ivec.pop_back();
					ivec.pop_back();
					ivec.push_back(result);
					cal.clear();
					cal.print_v(itov(result), 0);
				}
			}
			else {
				if (ivec.begin() != ivec.end()) {
					Athmetic counter(ivec[ivec.size() - 1], vtoi(num));
					num.clear();
					result = counter.a_div();
					ivec.pop_back();
					ivec.push_back(result);
					cal.clear();
					cal.print_v(itov(result), 0);
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
	glutCreateWindow("计算器");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFcn);

	glutMouseFunc(mousePtPlot);

	glutMainLoop();
}

