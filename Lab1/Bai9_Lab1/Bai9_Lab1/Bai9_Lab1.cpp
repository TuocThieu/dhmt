// Bai9_Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

const int screenWidth = 640;
const int screenHeight = 480;
const double R = 150;
const double R1 = 50;
const double pi = 3.141592654;

struct GLdoublePoint
{
	GLdouble x;
	GLdouble y;
};

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POINTS);
	GLdoublePoint V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V01, V0;
	V0.x = screenWidth / 2;
	V0.y = screenHeight / 2;
	V1.x = V0.x;
	V1.y = V0.y + R;
	V2.x = V0.x + R*sin(2 * pi / 5);
	V2.y = V0.y + R*cos(2 * pi / 5);
	V3.x = V0.x + R*sin(pi / 5);
	V3.y = V0.y - R*cos(pi / 5);
	V4.x = V0.x - R*sin(pi / 5);
	V4.y = V0.y - R*cos(pi / 5);
	V5.x = V0.x - R*sin(2 * pi / 5);
	V5.y = V0.y + R*cos(2 * pi / 5);

	V01.x = screenWidth / 2;
	V01.y = screenHeight / 2;
	V6.x = V01.x;
	V6.y = V01.y + R1;
	V7.x = V01.x + R1*sin(2 * pi / 5);
	V7.y = V01.y + R1*cos(2 * pi / 5);
	V8.x = V01.x + R1*sin(pi / 5);
	V8.y = V01.y - R1*cos(pi / 5);
	V9.x = V01.x - R1*sin(pi / 5);
	V9.y = V01.y - R1*cos(pi / 5);
	V10.x = V01.x - R1*sin(2 * pi / 5);
	V10.y = V01.y + R1*cos(2 * pi / 5);

	glVertex2d(V1.x, V1.y);
	glVertex2d(V2.x, V2.y);
	glVertex2d(V3.x, V3.y);
	glVertex2d(V4.x, V4.y);
	glVertex2d(V5.x, V5.y);

	glVertex2d(V6.x, V6.y);
	glVertex2d(V7.x, V7.y);
	glVertex2d(V8.x, V8.y);
	glVertex2d(V9.x, V9.y);
	glVertex2d(V10.x, V10.y);
	glEnd();

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
