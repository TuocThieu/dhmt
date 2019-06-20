// Lab_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"


const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glShadeModel(GL_FLAT);
}

void drawSquare(GLint x, GLint y, GLint a)
{
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + a, y);
	glVertex2i(x + a, y + a);
	glVertex2i(x, y + a);
	glEnd();
}

void drawRectangle(GLint x, GLint y, GLint width, GLint height)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2i(x, y);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2i(x + width, y);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2i(x + width, y + height);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(x, y + height);
	glEnd();
}

void displaySquare()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLint size = 200;
	GLint x = (screenWidth - size) / 2;
	GLint y = (screenHeight - size) / 2;
	drawSquare(x, y, size);

	glFlush();
}

void displayRectangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLint w = 400, h = 200;
	GLint x = (screenWidth - w) / 2;
	GLint y = (screenHeight - h) / 2;
	drawRectangle(x, y, w, h);

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
	//glutCreateWindow("Square");
	glutCreateWindow("Rectangle");
	init();
	//glutDisplayFunc(displaySquare);
	glutDisplayFunc(displayRectangle);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
