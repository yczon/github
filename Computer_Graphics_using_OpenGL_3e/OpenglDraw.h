#pragma once
#include<GL/glut.h>
#include<string>
#include<GL/glut.h>
#include<GL/glui.h>
#include<random>
#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>

const float FAI = 1.61803398874989; //(1 + sqrt(5)) / 2 ���ƽ�ָ���
const float PI  = 3.14159265358979;  

struct GLPoint {
	GLfloat x, y;
};

struct GLLine {
	GLPoint CP;

	GLLine(GLint x1, GLint y1)
	{
		CP.x = x1;
		CP.x = x1;
	}

	//<<<<<<<<<<<< moveTo >>>>>>>>>>>>>>>>
	void moveTo(GLint x, GLint y)
	{
		CP.x = x;
		CP.y = y;
	}

	//<<<<<<<<<<<< lineTo >>>>>>>>>>>>>>>>
	void lineTo(GLint x, GLint y)
	{
		glBegin(GL_LINES);
		glVertex2i(CP.x,CP.y);
		glVertex2i(x,y);
		glEnd();
		glFlush();
		CP.x = x;
		CP.y = y;
	}
};

void setColor(const std::string);
void drawDot(GLint x,GLint y);
void drawLine(GLint x1,GLint y1,GLint x2,GLint y2);
