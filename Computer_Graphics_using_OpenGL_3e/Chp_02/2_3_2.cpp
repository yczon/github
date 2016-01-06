/****************************************************************************

example5.cpp

A GLUI program demonstrating subwindows, rotation controls,
translation controls, and listboxes

-----------------------------------------------------------------------

7/10/98 Paul Rademacher (rademach@cs.unc.edu)

****************************************************************************/
#include "stdafx.h"
#include <string.h>
#include <GL/glut.h>
#include <GL/glui.h>
#include<random>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

struct Point {
	int x;
	int y;
};

typedef vector<Point> Polygon;
typedef vector<Polygon> PolyLines;
PolyLines dimo;

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
	Point currentPoint;
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
	for (int i = 0;i<dimo.size();i++)
	{
		glBegin(GL_LINE_STRIP);
		for (int j = 0;j<dimo[i].size();j++)
		{
			glVertex2i(dimo[i][j].x, dimo[i][j].y);
		}
		glEnd();
	}
	glFlush();
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 650, -20, 450);
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