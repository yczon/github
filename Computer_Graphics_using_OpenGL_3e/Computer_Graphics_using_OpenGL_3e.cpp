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

//<<<<<<<<<<<<<<<<< hexSwirl >>>>>>>>>>>>>>>>>>>>
void hexSwirl() {

	const double radPerDeg = 0.017453393f;

	double x, y, cx, cy;
	double length = 10.0f;
	double scale = 0.1f;
	double theta = 0.0f;

	for (int i = 0; i < 50; i++) {

		x = y = 0.0f;

		x -= 11.18034f * sin(radPerDeg * 30.0f);
		y -= 11.18034f * cos(radPerDeg * 30.0f);

		glPushMatrix();

		glTranslatef(300.0f, 200.0f, 0.0f);
		glScalef(scale, scale, scale);
		glRotatef(theta, 0, 0, 1);

		theta += 1.5f;
		scale += 0.7f;

		glBegin(GL_LINE_LOOP);

		for (int c = 0; c < 6; c++) {

			glVertex2f(x, y);

			x += (length * cos(radPerDeg * (c * 60.0f)));
			y += (length * sin(radPerDeg * (c * 60.0f)));

		}

		glEnd();

		glPopMatrix();
	}
}

// <<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	float cx = 0.3, cy = 0.2;
	float H, W = 1.2, aspect = 0.7;
	int NumFrames = 24;
	setViewport(0,640,0,480);

	//setWindow(100,200,100,200);
	//for (int frame = 0; frame < NumFrames; frame++) {
	//	glClear(GL_COLOR_BUFFER_BIT);
	//	glColor3f(0.7,0.7,0.7);
	//	W *= 0.7;
	//	H = W * aspect;
	//	setWindow(cx-W,cx+W,cy-H,cy+H);
	//	hexSwirl();
	//	glFlush();
	//}
	int x = 100;
	int y = 100;
	int w = 1;
	int h = 1;
	int center_x = w / 2;
	int center_y = h / 2;

	for (int i = 1; i < 10; i++) {
		for (long a = 0; a < 200000000; a++) {}
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 0, 0);
		w = 640 / i;
		h = 480 / i;
		center_x = w / 2;
		center_y = h / 2;
		setWindow(0, w, 0, h);
		glBegin(GL_LINE_LOOP);
			glVertex2i(center_x-10, center_y-10);
			glVertex2i(center_x+10, center_y-10);
			glVertex2i(center_x+10, center_y+10);
			glVertex2i(center_x-10, center_y+10);
		glEnd();
		glFlush();
		cout << "hello" << endl;
	}
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	setWindow(0,640,0,480);
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