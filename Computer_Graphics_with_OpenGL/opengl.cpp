#include"stdafx.h"
#include<GL/glut.h>
#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
#include<cstdlib>

using namespace std;

//加
int c_add(int i, int j)
{
	return i + j;
}

//减
int c_minus(int i, int j)
{
	return i - j;
}

//乘
int c_mul(int i, int j)
{
	return i * j;
}

//除
int c_div(int i, int j)
{
	return i / j;
}

void draw()
{

}

GLsizei winWidth = 400, winHeight = 700;
GLint xRaster = 0, yRaster = 0;

vector<char *> label = {"0.Enter","123+/-","456bc","789clr","+-*/"};
//每个按钮的宽度跟高度
GLsizei  wpButton = winWidth / 4;
GLsizei  hpButton = winHeight / 8;

vector<GLsizei> x_coor = {0,wpButton,2*wpButton,3*wpButton,4*wpButton};
vector<GLsizei> y_coor = {0,hpButton,2*hpButton,3*hpButton,4*hpButton,5*hpButton,8*hpButton};

int result;
vector<int> num;
vector<vector<int>> ivec;

GLint dataValue[12] = { 420,342,324,310,262,185,
190,196,217,240,312,438 };

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);				// White display window.
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}

void barChart(void)
{
	GLint i=0,j=0;

	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(10);

	//显示按钮
	for (j = 0;j < 5;++j)
	{
		for (i = 0;i < 4;++i)
		{
			if(i == 3 && j==0)
			{ 
				glPolygonMode(GL_FRONT, GL_FILL);
				glColor3f(0.2, 0.2, 0.2);
				glBegin(GL_QUADS);
				glVertex2i(i*wpButton, j*hpButton);
				glVertex2i(i*wpButton + 2*wpButton, j*hpButton);
				glVertex2i(i*wpButton + 2*wpButton, hpButton + j*hpButton);
				glVertex2i(i*wpButton, hpButton + j*hpButton);
				glEnd();
			}
			else
			{
				glPolygonMode(GL_FRONT, GL_LINE);
				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_QUADS);
				glVertex2i(i*wpButton, j*hpButton);
				glVertex2i(i*wpButton + wpButton, j*hpButton);
				glVertex2i(i*wpButton + wpButton, hpButton + j*hpButton);
				glVertex2i(i*wpButton, hpButton + j*hpButton);
				glEnd();

				glPolygonMode(GL_FRONT, GL_FILL);
				glColor3f(0.2, 0.2, 0.2);
				glBegin(GL_QUADS);
				glVertex2i(i*wpButton, j*hpButton);
				glVertex2i(i*wpButton + wpButton, j*hpButton);
				glVertex2i(i*wpButton + wpButton, hpButton + j*hpButton);
				glVertex2i(i*wpButton, hpButton + j*hpButton);
				glEnd();
			}
		}
	}
	//显示区
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_QUADS);
	glVertex2i(0, 5*hpButton+10);
	glVertex2i(4*wpButton, 5*hpButton+10);
	glVertex2i(4*wpButton, 8*hpButton);
	glVertex2i(0,8*hpButton);
	glEnd();
	//数字，操作符
	glColor3f(1.0, 1.0, 1.0);

	xRaster = (wpButton-24)/2;
	yRaster = (hpButton-24)/2;

	glColor3f(1.0, 1.0, 1.0);
	for (j = 0;j < 5;++j)
	{
		for (i = 0;i < 4;++i)
		{
			//glRasterPos2i(xRaster, yRaster);
			//返回字符的宽度
			xRaster = glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, label[j][i]);
			glRasterPos2i(i*wpButton+((wpButton-xRaster)/2), j*hpButton+((hpButton-xRaster)/2));
			if (i == 2 && j == 0)
			{
				glRasterPos2i(i*wpButton+((wpButton-xRaster)), j*hpButton+((hpButton-xRaster)/2));
				for (size_t k = i;k < strlen(label[j]);++k)
				{
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][k]);
				}
			}
			else if (i == 3 && j != 0)
			{
				for (size_t k = i;k < strlen(label[j]);++k)
				{
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][k]);
				}
			}
			else
			{
				if (i == 3 && j == 0)
				{
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
				}
				else
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][i]);

			}

		}
	}

	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));

	glClear(GL_COLOR_BUFFER_BIT);
}

// 清除一个
void backOne(GLint x1, GLint y1,GLint x2,GLint y2)
{
	glColor3f(0.2, 0.2, 0.2);
	glRecti(x1,y1,x2,y2);
	/*
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	*/
}
//清除全部
void clear_all(GLint x1, GLint y1, GLint x2, GLint y2)
{
	glColor3f(0.2, 0.2, 0.2);
	glRecti(x1, y1, x2, y2);
}

//按键颜色改变
void press_button(GLint i, GLint j)
{

	glLineWidth(10);

	glPolygonMode(GL_FRONT, GL_LINE);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(i*wpButton, j*hpButton);
	glVertex2i(i*wpButton + wpButton, j*hpButton);
	glVertex2i(i*wpButton + wpButton, hpButton + j*hpButton);
	glVertex2i(i*wpButton, hpButton + j*hpButton);
	glEnd();

	if (i == 2 && j == 0)
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		glColor3f(0.4, 0.4, 0.4);
		glBegin(GL_QUADS);
		glVertex2i(i*wpButton, j*hpButton);
		glVertex2i(i*wpButton + 2 * wpButton, j*hpButton);
		glVertex2i(i*wpButton + 2 * wpButton, hpButton + j*hpButton);
		glVertex2i(i*wpButton, hpButton + j*hpButton);
		glEnd();
	}
	else
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		glColor3f(0.4, 0.4, 0.4);
		glBegin(GL_QUADS);
		glVertex2i(i*wpButton, j*hpButton);
		glVertex2i(i*wpButton + wpButton, j*hpButton);
		glVertex2i(i*wpButton + wpButton, hpButton + j*hpButton);
		glVertex2i(i*wpButton, hpButton + j*hpButton);
		glEnd();
	}




	glColor3f(1.0, 1.0, 1.0);
	xRaster = glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, label[j][i]);
	glRasterPos2i(i*wpButton + ((wpButton - xRaster) / 2), j*hpButton + ((hpButton - xRaster) / 2));
	if (i == 2 && j == 0)
	{
		glRasterPos2i(i*wpButton + ((wpButton - xRaster)), j*hpButton + ((hpButton - xRaster) / 2));
		for (size_t k = i;k < strlen(label[j]);++k)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][k]);
		}
	}
	else if (i == 3 && j != 0)
	{
		for (size_t k = i;k < strlen(label[j]);++k)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][k]);
		}
	}
	else
	{
		if (i == 3 && j == 0)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
		}
		else
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][i]);

	}
}
//显示结果
void show_result(int result)
{
	glColor3f(1.0, 1.0, 1.0);
	char str[20];
	int tmp = result;
	int aa = 0;
	do
	{
		aa = tmp % 10;
		tmp = tmp / 10;
		_itoa_s(aa, str, 2,10);
		xRaster += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *str);
		glRasterPos2i(4 * wpButton - xRaster, 6 * hpButton + ((hpButton - 24) / 2));
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);
	} while (tmp != 0);

	glFlush();
}
//显示数组
void show_num(vector<int> num)
{
	glColor3f(1.0, 1.0, 1.0);
	char str[20];
	int tmp = result;
	int aa = 0;
	for (auto i = num.rbegin();i != num.rend();++i)
	{
		_itoa_s(*i, str, 2, 10);
		xRaster += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *str);
		glRasterPos2i(4 * wpButton - xRaster, 6 * hpButton + ((hpButton - 24) / 2));
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);
	}

	glFlush();
}
void plotPoint(GLint x, GLint y)
{
	char word=' ';
	bool back = false;
	bool clear = false;
	static GLsizei bootset = 10;

	if (x < x_coor[1])
	{
		if (y < y_coor[1])
		{
			word = '0';
			press_button(0,0);
			num.push_back(0);
		}
		else if (y<y_coor[2])
		{
			word = '1';
			press_button(0,1);
			num.push_back(1);
		}
		else if (y<y_coor[3])
		{
			word = '4';
			press_button(0,2);
			num.push_back(4);
		}
		else if (y<y_coor[4])
		{
			word = '7';
			press_button(0,3);
			num.push_back(7);
		}
		else if (y<y_coor[5])
		{
			word = ' ';  //加法
			press_button(0,4);
			auto size = ivec.size();
			int i = 0;
			if (size > 1)
			{
				for (auto v = ivec[size].rbegin();v != ivec[size].rend();++v)
				{
					result += *v * pow(10, i);
					++i;
				}
				i = 0;
				for (auto v = ivec[size - 1].rbegin();v != ivec[size - 1].rend();++v)
				{
					result += *v * pow(10, i);
					++i;
				}
				ivec.pop_back();
				ivec.pop_back();
			}
			else
			{
				i = 0;
				result = 0;
				for (auto v = ivec[0].rbegin();v != ivec[0].rend();++v)
				{
					result += *v * pow(10, i);
					++i;
				}
			}
			show_result(result);
		}
	}
	else if (x < x_coor[2])
	{
		if (y < y_coor[1])
		{
			word = '.';
			press_button(1,0);
		}
		else if (y<y_coor[2])
		{
			word = '2';
			press_button(1,1);
			num.push_back(2);
		}
		else if (y<y_coor[3])
		{
			word = '5';
			press_button(1,2);
			num.push_back(5);
		}
		else if (y<y_coor[4])
		{
			word = '8';
			press_button(1,3);
			num.push_back(8);
		}
		else if (y<y_coor[5])
		{
			word = ' ';   //减法
			press_button(1,4);
			auto size = ivec.size();
			int i = 0;
			if (size > 1)
			{
				for (auto v = ivec[size].rbegin();v != ivec[size].rend();++v)
				{
					result += *v + pow(10, i);
					++i;
				}
				i = 0;
				for (auto v = ivec[size - 1].rbegin();v != ivec[size - 1].rend();++v)
				{
					result -= *v * pow(10, i);
					++i;
				}
				ivec.pop_back();
				ivec.pop_back();
			}
			else
			{
				i = 0;
				result = 0;
				for (auto v = ivec[0].rbegin();v != ivec[0].rend();++v)
				{
					result += *v * pow(10, i);
					++i;
				}
			}
			show_result(result);

		}
	}
	else if (x < x_coor[3])
	{
		if (y < y_coor[1])
		{
			word = ' ';  //enter
			press_button(2, 0);
			ivec.push_back(num);
			clear_all(0, 5 * hpButton + (hpButton - 24) / 2, 4 * wpButton, 8 * hpButton);
			show_num(num);
			num.clear();
		}
		else if (y<y_coor[2])
		{
			word = '3';
			press_button(2,1);
			num.push_back(3);
		}
		else if (y<y_coor[3])
		{
			word = '6';
			press_button(2,2);
			num.push_back(6);
		}
		else if (y<y_coor[4])
		{
			word = '9';
			press_button(2,3);
			num.push_back(9);
		}
		else if (y<y_coor[5])
		{
			word = ' '; //乘法
			press_button(2,4);
			auto size = ivec.size();
			int i = 0;
			if (size > 1)
			{
				for (auto v = ivec[size].rbegin();v != ivec[size].rend();++v)
				{
					result  += *v + pow(10, i);
					++i;
				}
				i = 0;
				for (auto v = ivec[size-1].rbegin();v != ivec[size-1].rend();++v)
				{
					result *= *v * pow(10,i);
					++i;
				}
				ivec.pop_back();
				ivec.pop_back();
			}
			else
			{
				i = 0;
				result = 0;
				for (auto v = ivec[0].rbegin();v != ivec[0].rend();++v)
				{
					result  += *v * pow(10, i);
					++i;
				}
			}
			show_result(result);
		}
	}
	else if (x < x_coor[4])
	{
		if (y < y_coor[1])
		{
			word = ' ';  //enter
			press_button(2, 0);
			ivec.push_back(num);
			clear_all(0, 5 * hpButton + (hpButton - 24) / 2, 4 * wpButton, 8 * hpButton);
			show_num(num);
			num.clear();
		}
		else if (y<y_coor[2])
		{
			word = ' ';  //+/-
			press_button(3,1);
		}
		else if (y<y_coor[3])
		{
			word = ' ';  //bc
			press_button(3,2);
			
			back = true;
		}
		else if (y<y_coor[4])
		{
			word = ' ';  //clr
			press_button(3,3);
			clear = true;
		}
		else if (y<y_coor[5])
		{
			word = ' ';  // /   除法
			press_button(3,4);
			auto size = ivec.size();
			int i = 0;
			if (size > 1)
			{
				for (auto v = ivec[size].rbegin();v != ivec[size].rend();++v)
				{
					result += *v + pow(10, i);
					++i;
				}
				i = 0;
				for (auto v = ivec[size - 1].rbegin();v != ivec[size - 1].rend();++v)
				{
					result *= *v * pow(10, i);
					++i;
				}
				ivec.pop_back();
				ivec.pop_back();
			}
			else
			{
				i = 0;
				result = 0;
				for (auto v = ivec[0].rbegin();v != ivec[0].rend();++v)
				{
					result += *v * pow(10, i);
					++i;
				}
			}
			show_result(result);
		}
	}

	//if(x<wpButton && y<hpButton)
	GLsizei word_width = glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, word);
	if (back)
	{
		backOne(bootset, 5 * hpButton + (hpButton - word_width) / 2, bootset + word_width, 5 * hpButton + (hpButton - word_width) / 2 + 3 * word_width);
		if(bootset>10)
			bootset -= word_width;
	}
	else if (clear)
	{
		clear_all(0, 5 * hpButton + (hpButton - word_width) / 2,4*wpButton,8*hpButton);
		bootset = 10;
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
		bootset += word_width;
		glRasterPos2i(bootset, 5 * hpButton + (hpButton - word_width) / 2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, word);
	}
}
//释放鼠标
void up_button()
{
	GLint i = 0, j = 0;

	glLineWidth(10);

	//显示按钮
	for (j = 0;j < 5;++j)
	{
		for (i = 0;i < 4;++i)
		{
			if (i == 3 && j == 0)
			{
				glPolygonMode(GL_FRONT, GL_FILL);
				glColor3f(0.2, 0.2, 0.2);
				glBegin(GL_QUADS);
				glVertex2i(i*wpButton, j*hpButton);
				glVertex2i(i*wpButton + 2 * wpButton, j*hpButton);
				glVertex2i(i*wpButton + 2 * wpButton, hpButton + j*hpButton);
				glVertex2i(i*wpButton, hpButton + j*hpButton);
				glEnd();
			}
			else
			{
				glPolygonMode(GL_FRONT, GL_LINE);
				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_QUADS);
				glVertex2i(i*wpButton, j*hpButton);
				glVertex2i(i*wpButton + wpButton, j*hpButton);
				glVertex2i(i*wpButton + wpButton, hpButton + j*hpButton);
				glVertex2i(i*wpButton, hpButton + j*hpButton);
				glEnd();

				glPolygonMode(GL_FRONT, GL_FILL);
				glColor3f(0.2, 0.2, 0.2);
				glBegin(GL_QUADS);
				glVertex2i(i*wpButton, j*hpButton);
				glVertex2i(i*wpButton + wpButton, j*hpButton);
				glVertex2i(i*wpButton + wpButton, hpButton + j*hpButton);
				glVertex2i(i*wpButton, hpButton + j*hpButton);
				glEnd();
			}
		}
	}
	//数字，操作符
	glColor3f(1.0, 1.0, 1.0);

	xRaster = (wpButton - 24) / 2;
	yRaster = (hpButton - 24) / 2;

	glColor3f(1.0, 1.0, 1.0);
	for (j = 0;j < 5;++j)
	{
		for (i = 0;i < 4;++i)
		{
			//glRasterPos2i(xRaster, yRaster);
			//返回字符的宽度
			xRaster = glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, label[j][i]);
			glRasterPos2i(i*wpButton + ((wpButton - xRaster) / 2), j*hpButton + ((hpButton - xRaster) / 2));
			if (i == 2 && j == 0)
			{
				glRasterPos2i(i*wpButton + ((wpButton - xRaster)), j*hpButton + ((hpButton - xRaster) / 2));
				for (size_t k = i;k < strlen(label[j]);++k)
				{
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][k]);
				}
			}
			else if (i == 3 && j != 0)
			{
				for (size_t k = i;k < strlen(label[j]);++k)
				{
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][k]);
				}
			}
			else
			{
				if (i == 3 && j == 0)
				{
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
				}
				else
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][i]);

			}

		}
	}

	glFlush();
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
		plotPoint(xMouse, winHeight - yMouse);
	if (button == GLUT_LEFT_BUTTON && action == GLUT_UP)
		up_button();

	glFlush();
}

void main(int argc, char ** argv)
{
	// 计算
	int a = 0, b = 0;
	string op;
	map<string, int(*)(int, int)> binops;
	binops.insert({ "+",c_add });
	binops.insert({ "-",c_minus });
	binops.insert({ "*",c_mul });
	binops.insert({ "/",c_div });

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Line Chart Data Plot");

	init();

	glutDisplayFunc(barChart);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mousePtPlot);

	glutMainLoop();
}

