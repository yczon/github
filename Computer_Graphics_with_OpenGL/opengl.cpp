#include "stdafx.h"
#include<GL/glut.h>
#include<iostream>
#include"chp_3/barChart.h"

using namespace std;

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Line Chart Data Plot");

	init();
	glutDisplayFunc(barChart);
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();
}