#pragma once

#include<GL/glut.h>
#include<vector>
//��ʾ��
class Display {
private:
	GLsizei width, height;
	std::vector<char *> label = { "0.E","123E","456B","789C","+-*/" };
public:
	GLsizei wButton, hButton;
	Display(GLsizei w, GLsizei h) :
		width(w), height(h) 
	{
		wButton = width / 4;
		hButton = height / 8;
	}
	void iniWindow(void);
	void key_down(GLsizei x1, GLsizei y1, GLsizei x2, GLsizei y2,char *w);
	void key_up(GLsizei x1, GLsizei y1, GLsizei x2, GLsizei y2,char *w);
	void clear();
	void backspace(std::vector<char>);
	void print(std::vector<char>);
	void print_v(std::vector<char>,int);
	void enter(std::vector<std::vector<char>>);
};

// ��ʼ��������ͼ�ν���
void Display::iniWindow(void) {

	GLint i = 0, j = 0;

	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(10);

	//��ʾ��ť
	for (j = 0;j < 5;++j)
	{
		for (i = 0;i < 4;++i)
		{
			if (i == 3 && j == 0)
			{
				glPolygonMode(GL_FRONT, GL_FILL);
				glColor3f(0.2, 0.2, 0.2);
				glBegin(GL_QUADS);
				glVertex2i(i*wButton, j*hButton);
				glVertex2i(i*wButton + 2 * wButton, j*hButton);
				glVertex2i(i*wButton + 2 * wButton, hButton + j*hButton);
				glVertex2i(i*wButton, hButton + j*hButton);
				glEnd();
			}
			else
			{
				glPolygonMode(GL_FRONT, GL_LINE);
				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_QUADS);
				glVertex2i(i*wButton, j*hButton);
				glVertex2i(i*wButton + wButton, j*hButton);
				glVertex2i(i*wButton + wButton, hButton + j*hButton);
				glVertex2i(i*wButton, hButton + j*hButton);
				glEnd();

				glPolygonMode(GL_FRONT, GL_FILL);
				glColor3f(0.2, 0.2, 0.2);
				glBegin(GL_QUADS);
				glVertex2i(i*wButton, j*hButton);
				glVertex2i(i*wButton + wButton, j*hButton);
				glVertex2i(i*wButton + wButton, hButton + j*hButton);
				glVertex2i(i*wButton, hButton + j*hButton);
				glEnd();
			}
		}
	}
	//��ʾ��������
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_QUADS);
	glVertex2i(0, 5 * hButton + 10);
	glVertex2i(4 * wButton, 5 * hButton + 10);
	glVertex2i(4 * wButton, 8 * hButton);
	glVertex2i(0, 8 * hButton);
	glEnd();
	//���֣�������
	glColor3f(1.0, 1.0, 1.0);

	GLsizei wSize = (wButton - 24) / 2;

	glColor3f(1.0, 1.0, 1.0);
	for (j = 0;j < 5;++j)
	{
		for (i = 0;i < 4;++i)
		{
			//glRasterPos2i(wSize, yRaster);
			//�����ַ��Ŀ��
			wSize = glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, label[j][i]);
			glRasterPos2i(i*wButton + ((wButton - wSize) / 2), j*hButton + ((hButton - wSize) / 2));
			if (i == 2 && j == 0)
			{
				glRasterPos2i(i*wButton + ((wButton - wSize)), j*hButton + ((hButton - wSize) / 2));
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
					//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
				}
				else
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[j][i]);

			}

		}
	}

	glFlush();
}
// ��������
void Display::key_down(GLsizei x1, GLsizei y1, GLsizei x2, GLsizei y2,char *w) {

	glColor3f(0.4, 0.4, 0.4);
	glRecti(x1,y1,x2-5,y2-5);

	GLsizei wSize = glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24,*w);

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(x1+(x2-x1-wSize) / 2, y1 + (y2-y1-wSize) / 2);

	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *w);
}

void Display::key_up(GLsizei x1, GLsizei y1, GLsizei x2, GLsizei y2,char *w) {

	glColor3f(0.2, 0.2, 0.2);
	glRecti(x1, y1, x2-5, y2-5);

	GLsizei wSize = glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *w);

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(x1 + (x2 - x1 - wSize) / 2, y1 + (y2 - y1 - wSize) / 2);

	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *w);;
}
// �����������ʾ����
void Display::clear() {
	glColor3f(0.2, 0.2, 0.2);
	glRecti(0, 5*hButton+10,4*wButton , 8*hButton);

	glFlush();
}
// �˸�
void Display::backspace(std::vector<char> var) {
	glColor3f(0.2, 0.2, 0.2);
	print(var);
}
void Display::print(std::vector<char> result) {
	//��ʾǰ������һ����Ļ
	clear();

	glColor3f(1.0, 1.0, 1.0);
	GLsizei wSize = 0;
	for (auto v = result.begin();v != result.end(); ++v)
	{
		wSize += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *v);
		glRasterPos2i(wSize, 5 * hButton + ((hButton - 24) / 2));
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *v);
	}

	glFlush();
}

void Display::print_v(std::vector<char> result,int h) {

	//��Լ�������ʾ��������
	int row = 6 + h;
	glColor3f(1.0, 1.0, 1.0);
	GLsizei wSize = 0;
	for (auto v = result.rbegin();v != result.rend(); ++v)
	{
		wSize += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *v);
		glRasterPos2i(4 * wButton - wSize, row * hButton + ((hButton - 24) / 2));
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *v);
	}

}

void Display::enter(std::vector<std::vector<char>> cvec) {
	//��ʾǰ������һ����Ļ

	clear();
	int row = 0;
	for (auto v = cvec.rbegin();v != cvec.rend();++v)
	{
		print_v(*v, row);
		++row;
	}
	glFlush();
}
