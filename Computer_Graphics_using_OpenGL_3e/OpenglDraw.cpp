#include "stdafx.h"
#include"OpenglDraw.h"

void lineTo(GLint x, GLint y);
void moveTo(GLint x, GLint y);

//---------------------- 画点 -----------------------------//
void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

//---------------------- 画线 -----------------------------//
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{
	glBegin(GL_LINES);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
	glEnd();
}

//---------------------- 画圆 -----------------------------//
void drawCircle(GLfloat radius)
{
	glBegin(GL_LINES);
	GLfloat x, y;
	for (GLfloat i = 0;i < TWOPI;i += 0.1) {
		x = radius*cos(i);
		y = radius*sin(i);
		glVertex2i(x,y);
	}
	glEnd();
}

//---------------------- 设置前景色 -----------------------------//
void setColor(const std::string cl)
{
	std::string color = cl;
	if (color == "RED" || color == "red") {
		glColor3f(1.0,0.0,0.0);
	}
	else if(color == "BLUE" || color == "blue"){
		glColor3f(0.0,0.0,1.0);
	}
	else if(color == "GREEN" || color == "green"){
		glColor3f(0.0,1.0,0.0);
	}
	else if(color == "BLACK" || color == "black"){
		glColor3f(0.0,1.0,0.0);
	}
	else if(color == "WHITE" || color == "white"){
		glColor3f(0.0,1.0,0.0);
	}
	else if(color == "YELLOW" || color == "yellow"){
		glColor3f(1.0,1.0,0.0);
	}
	else if(color == "GRAY" || color == "gray"){
		glColor3f(0.2,0.2,0.2);
	}
	else if(color == "DARKGRAY" || color == "darkgray"){
		glColor3f(0.1,0.1,0.1);
	}
	else if(color == "LIGHTGRAY" || color == "lightgray"){
		glColor3f(0.7,0.7,0.7);
	}
	else if(color == "CYAN" || color == "cyan"){
		glColor3f(0.0,1.0,1.0);
	}
	else if(color == "CARMINE" || color == "carmine"){
		glColor3f(1.0,0.0,1.0);
	}
}
