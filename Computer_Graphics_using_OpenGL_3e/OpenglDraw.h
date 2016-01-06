#pragma once
#include<GL/glut.h>
#include<string>

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
