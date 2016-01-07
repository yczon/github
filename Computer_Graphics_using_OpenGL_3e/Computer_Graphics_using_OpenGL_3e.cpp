/****************************************************************************

example5.cpp

A GLUI program demonstrating subwindows, rotation controls,
translation controls, and listboxes

-----------------------------------------------------------------------

7/10/98 Paul Rademacher (rademach@cs.unc.edu)

****************************************************************************/
#include "stdafx.h"
#include"OpenglDraw.h"

using namespace std;

typedef vector<GLPoint> Polygon;
typedef vector<Polygon> PolyLines;
PolyLines dimo;

//<<<<<<<<<<<<<<<<<< setWindow >>>>>>>>>>>>>>>>>>>
void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left,right,bottom,top);
}

//<<<<<<<<<<<<<<<<<< setViewport >>>>>>>>>>>>>>>>>>>
void setViewport(GLint left, GLdouble right, GLdouble bottom, GLdouble top)
{
	glViewport(left,bottom,right-left,top-bottom);
}

void loadData(char * fileName)
{
	ifstream inStream;
	inStream.open(fileName);
	if (inStream.fail())
	{
		cout << "can not open file :" << fileName << endl;
		return;
	}
	GLint numPolygon, numPolyLines;
	GLPoint currentPoint;
	inStream >> numPolyLines;
	Polygon currentPolygon;
	for (int i = 0; i < numPolyLines;i++)
	{
		inStream >> numPolygon;
		currentPolygon.clear();
		for (int j = 0;j<numPolygon;j++)
		{
			inStream >> currentPoint.x >> currentPoint.y;
			currentPolygon.push_back(currentPoint);
		}
		dimo.push_back(currentPolygon);
	}
	inStream.close();
	cout << "read file: " << fileName << "success!" << endl;
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	for (int col = 0;col < 5;col++) {                     //平铺的列
		for (int row = 0;row < 5;row++) {				//行
			for (int i = 0;i < dimo.size();i++)
			{
				glViewport(col * 64, row * 44, 64, 44);

				glBegin(GL_LINE_STRIP);
				for (int j = 0;j < dimo[i].size();j++)
				{
					glVertex2i(dimo[i][j].x, dimo[i][j].y);
				}
				glEnd();
			}
		}
	}
	glFlush();
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	setWindow(0,640,0,480);
	loadData("./Chp_02/dino.dat");
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("MyDimo");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}