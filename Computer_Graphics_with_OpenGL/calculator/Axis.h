#pragma once

#include<GL/glut.h>
#include<vector>

// ������
class Axis {
private:
	// �����ʱ������
	GLsizei x, y;
	//ÿ����������
	GLsizei xButton, yButton;
	//��������
	std::vector<GLsizei> x_coor;
	std::vector<GLsizei> y_coor;

public:
	// �����ϵ��ַ�
	char w;
	//��������
	GLsizei x1,x2,y1,y2;

	Axis() = default;
	Axis(GLint a, GLint b,GLsizei aButton,GLsizei bButton) :
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
				w = '+';  //�ӷ�
				x1 = x_coor[0];
				x2 = x_coor[0] + xButton;
				y1 = y_coor[4];
				y2 = y_coor[4] + yButton;
			}
		}
		else if (x < x_coor[2])
		{
			if (y < y_coor[1])
			{
				w = '.';
				x1 = x_coor[1];
				x2 = x_coor[1] + xButton;
				y1 = y_coor[0];
				y2 = y_coor[0] + yButton;
			}
			else if (y<y_coor[2])
			{
				w = '2';
				x1 = x_coor[1];
				x2 = x_coor[1] + xButton;
				y1 = y_coor[1];
				y2 = y_coor[1] + yButton;
			}
			else if (y<y_coor[3])
			{
				w = '5';
				x1 = x_coor[1];
				x2 = x_coor[1] + xButton;
				y1 = y_coor[2];
				y2 = y_coor[2] + yButton;
			}
			else if (y<y_coor[4])
			{
				w = '8';
				x1 = x_coor[1];
				x2 = x_coor[1] + xButton;
				y1 = y_coor[3];
				y2 = y_coor[3] + yButton;
			}
			else if (y<y_coor[5])
			{
				w = '-';   //����
				x1 = x_coor[1];
				x2 = x_coor[1] + xButton;
				y1 = y_coor[4];
				y2 = y_coor[4] + yButton;
			}
		}
		else if (x < x_coor[3])
		{
			if (y < y_coor[1])
			{
				w = 'E';  //enter
				x1 = x_coor[2];
				x2 = x_coor[2] + 2 * xButton;
				y1 = y_coor[0];
				y2 = y_coor[0] + yButton;
			}
			else if (y<y_coor[2])
			{
				w = '3';
				x1 = x_coor[2];
				x2 = x_coor[2] + xButton;
				y1 = y_coor[1];
				y2 = y_coor[1] + yButton;
			}
			else if (y<y_coor[3])
			{
				w = '6';
				x1 = x_coor[2];
				x2 = x_coor[2] + xButton;
				y1 = y_coor[2];
				y2 = y_coor[2] + yButton;
			}
			else if (y<y_coor[4])
			{
				w = '9';
				x1 = x_coor[2];
				x2 = x_coor[2] + xButton;
				y1 = y_coor[3];
				y2 = y_coor[3] + yButton;
			}
			else if (y<y_coor[5])
			{
				w = '*'; //�˷�
				x1 = x_coor[2];
				x2 = x_coor[2] + xButton;
				y1 = y_coor[4];
				y2 = y_coor[4] + yButton;
			}
		}
		else if (x < x_coor[4])
		{
			if (y < y_coor[1])
			{
				w = 'E';  //enter
				x1 = x_coor[2];
				x2 = x_coor[2] + 2 * xButton;
				y1 = y_coor[0];
				y2 = y_coor[0] + yButton;
			}
			else if (y<y_coor[2])
			{
				w = 'E';  // Enter
				x1 = x_coor[3];
				x2 = x_coor[3] + xButton;
				y1 = y_coor[1];
				y2 = y_coor[1] + yButton;
			}
			else if (y<y_coor[3])
			{
				w = 'B';  //bc
				x1 = x_coor[3];
				x2 = x_coor[3] + xButton;
				y1 = y_coor[2];
				y2 = y_coor[2] + yButton;
			}
			else if (y<y_coor[4])
			{
				w = 'C';  //clr
				x1 = x_coor[3];
				x2 = x_coor[3] + xButton;
				y1 = y_coor[3];
				y2 = y_coor[3] + yButton;
			}
			else if (y<y_coor[5])
			{
				w = '/';  // /   ����
				x1 = x_coor[3];
				x2 = x_coor[3] + xButton;
				y1 = y_coor[4];
				y2 = y_coor[4] + yButton;
			}
		}  // end if
	} // end construct

};
