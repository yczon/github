#include "stdafx.h"
#include"OpenglDraw.h"

void lineTo(GLint x, GLint y);
void moveTo(GLint x, GLint y);

//---------------------- ���� -----------------------------//
void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

//---------------------- ���� -----------------------------//
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{
	glBegin(GL_LINES);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
	glEnd();
}

//---------------------- ��Բ -----------------------------//
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

//---------------------- ����ǰ��ɫ -----------------------------//
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

//-------------------- ���Բ�ֵ(����a��b֮��ı���t����ֵ) ----------------------// 
float lerp(float a, float b, float t)
{
	return a + (b - a)*t;
}
//-------------------- �ڲ�(���ص�A��B֮��ı���t���ĵ�P(t)) ----------------------// 
//-------------------- �����һ��Ҳ������A�͵�B�ڱ���t�����ڲ� ---------------------//
GLPoint tween(GLPoint A, GLPoint B, float t)
{
	GLPoint T;
	T.x = lerp(A.x,B.x,t);
	T.y = lerp(A.y,B.y,t);
	return T;
}

