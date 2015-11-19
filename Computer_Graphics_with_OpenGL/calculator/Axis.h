#pragma once

#include<GL/glut.h>
#include<vector>

class Axis {
private:
	GLsizei x1,x2,y1,y2;
	GLsizei x, y;
	GLsizei xButton, yButton;
	char w;
	std::vector<GLsizei> x_coor;
	std::vector<GLsizei> y_coor;

public:
	Axis() = default;
	Axis(GLsizei a, GLsizei b,GLsizei aButton,GLsizei bButton) :
		x(a), y(b),xButton(aButton),yButton(bButton), 
		x_coor { 0,xButton,2 * xButton,3 * xButton,4 * xButton },
		y_coor { 0,yButton,2 * yButton,3 * yButton,4 * yButton,5 * yButton,8 * yButton } 
	{
		if (x < x_coor[1])
		{
			if (y < y_coor[1])
			{
				w = '0';
				x1 = x_coor[0];
				x2 = x_coor[0]+xButton;
				y1 = y_coor[0];
				y2 = y_coor[0]+yButton;
			}
			else if (y<y_coor[2])
			{
				w = '1';
				x1 = x_coor[0];
				x2 = x_coor[0] + xButton;
				y1 = y_coor[1];
				y2 = y_coor[1] + yButton;
			}
			else if (y<y_coor[3])
			{
				w = '4';
				x1 = x_coor[0];
				x2 = x_coor[0] + xButton;
				y1 = y_coor[2];
				y2 = y_coor[2] + yButton;
			}
			else if (y<y_coor[4])
			{
				w = '7';
				x1 = x_coor[0];
				x2 = x_coor[0] + xButton;
				y1 = y_coor[3];
				y2 = y_coor[3] + yButton;
			}
			else if (y<y_coor[5])
			{
				w = '+';  //加法
			}
		}
		else if (x < x_coor[2])
		{
			if (y < y_coor[1])
			{
				w = '.';
			}
			else if (y<y_coor[2])
			{
				w = '2';
			}
			else if (y<y_coor[3])
			{
				w = '5';
			}
			else if (y<y_coor[4])
			{
				w = '8';
			}
			else if (y<y_coor[5])
			{
				w = '-';   //减法
			}
		}
		else if (x < x_coor[3])
		{
			if (y < y_coor[1])
			{
				w = 'E';  //enter
			}
			else if (y<y_coor[2])
			{
				w = '3';
			}
			else if (y<y_coor[3])
			{
				w = '6';
			}
			else if (y<y_coor[4])
			{
				w = '9';
			}
			else if (y<y_coor[5])
			{
				w = '*'; //乘法
			}
		}
		else if (x < x_coor[4])
		{
			if (y < y_coor[1])
			{
				w = 'E';  //enter
			}
			else if (y<y_coor[2])
			{
				w = 'E';  // Enter
			}
			else if (y<y_coor[3])
			{
				w = 'B';  //bc
			}
			else if (y<y_coor[4])
			{
				w = 'C';  //clr
			}
			else if (y<y_coor[5])
			{
				w = '/';  // /   除法
			}
		}

	}
};
