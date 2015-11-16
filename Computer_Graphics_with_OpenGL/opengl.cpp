#include"stdafx.h"
#include<GL/glut.h>
#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>

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

	GLsizei  wpButton = winWidth / 4;
	GLsizei  hpButton = winHeight / 8;

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
				for (int k = i;k < strlen(label[j]);++k)
				{
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][k]);
				}
			}
			else if (i == 3 && j != 0)
			{
				for (int k = i;k < strlen(label[j]);++k)
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

void plotPoint(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
		plotPoint(xMouse, winHeight - yMouse);

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

	// 画图
	/*
	draw();

	while (cin >> a >> b >> op)
	{
		cout << binops[op](a, b) << endl;
	}
	*/


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Line Chart Data Plot");

	init();

	glutDisplayFunc(barChart);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mousePtPlot);

	glutMainLoop();
}

