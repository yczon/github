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

const float FAI = 1.61803398874989; //(1 + sqrt(5)) / 2 Φ黄金分割数
const float PI  = 3.14159265358979;  
const float TWOPI  = 2 * 3.14159265358979;  

class GLPoint {
public:
	GLfloat x, y;

	void set(float dx, float dy) {
		x = dx;
		y = dy;
	}

	void set(GLPoint &p) {
		x = p.x; y = p.y;
	}
	GLPoint(GLfloat xx, GLfloat yy) {
		x = xx;
		y = yy;
	}
	GLPoint() {
		x = y = 0;
	}

};

class GLLine {
public:
	GLPoint CP;

	GLLine() = default;
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
	// moveTo 重载
	void moveTo(GLPoint p)
	{
		CP.set(p);
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
	// lineTo 重载
	void lineTo(GLPoint p)
	{
		glBegin(GL_LINES);
		glVertex2f(CP.x, CP.y);
		glVertex2f(p.x, p.y);
		glEnd();
		glFlush();
		CP.set(p);
	}
};

void setColor(const std::string);
void drawDot(GLint x,GLint y);
void drawLine(GLint x1,GLint y1,GLint x2,GLint y2);
void drawCircle(GLfloat radius);
float lerp(float a, float b, float t);
GLPoint tween(GLPoint A,  GLPoint B, float t);
void initCT(void);
void scale2D(double sx, double sy);
void translate2D(double dx,double dy);
void rotate2D(double angle);
void drawTween(GLPoint A[], GLPoint B[], int n, float t);

