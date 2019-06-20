// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
//***************BAI TAP 1******************

//#include <Math.h>
//#define PI  3.141592654f
//
//const int screenWidth = 640;
//const int screenHeight = 480;
//const int windowPosX = 50;
//const int windowPosY = 50;
//
//const char title[] = "Bouncing Ball (2D)";
//GLfloat ballRadius = 0.5f;
//GLfloat ballX = 0.0f;
//GLfloat ballY = 0.0f;
//GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
//GLfloat xSpeed = 0.02f;
//GLfloat ySpeed = 0.007f;
//int refreshMillis = 30;
//GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	//glShadeModel(GL_FLAT);
//}
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glTranslatef(ballX, ballY, 0.0f);
//
//	glBegin(GL_TRIANGLE_FAN);
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glVertex2f(0.0f, 0.0f);
//	int numSegments = 100;
//	GLfloat angle;
//	for (int i = 0; i <= numSegments; i++) {
//		angle = i * 2.0f*PI / numSegments;
//		glVertex2f(cos(angle)*ballRadius, sin(angle)*ballRadius);
//	}
//	glEnd();
//	glutSwapBuffers();
//	ballX += xSpeed;
//	ballY += ySpeed;
//	if (ballX > ballXMax) {
//		ballX = ballXMax;
//		xSpeed = -xSpeed;
//	}
//	else if (ballX < ballXMin)
//	{
//		ballX = ballXMin;
//		xSpeed = -xSpeed;
//	}
//	if (ballY > ballYMax) {
//		ballY = ballYMax;
//		ySpeed = -ySpeed;
//	}
//	else if (ballY < ballYMin)
//	{
//		ballY = ballYMin;
//		ySpeed = -ySpeed;
//	}
//
//
//}
//void reshape(GLsizei width, GLsizei height)
//{
//	if (height == 0)
//		height = 1;
//	GLfloat aspect = (GLfloat)width / (GLfloat)height;
//
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (width >= height) {
//		clipAreaXLeft = -1.0*aspect;
//		clipAreaXRight = 1.0*aspect;
//		clipAreaYBottom = -1.0;
//		clipAreaYTop = 1.0;
//	}
//	else
//	{
//		clipAreaXLeft = -1.0;
//		clipAreaXRight = 1.0;
//		clipAreaYBottom = -1.0 / aspect;
//		clipAreaYTop = 1.0 / aspect;
//	}
//
//	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
//	ballXMin = clipAreaXLeft + ballRadius;
//	ballXMax = clipAreaXRight - ballRadius;
//	ballYMax = clipAreaYTop - ballRadius;
//	ballYMin = clipAreaYBottom + ballRadius;
//}
//void Timer(int value) {
//	glutPostRedisplay();
//	glutTimerFunc(refreshMillis, Timer, 0);
//}
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv); //khoi tao glut
//	glutInitDisplayMode(GLUT_DOUBLE);
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutInitWindowPosition(windowPosX, windowPosY);
//	glutCreateWindow(title);
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutTimerFunc(0, Timer, 0);
//	init();
//	glutMainLoop();
//	return 0;
//}

//***************BAI TAP 2******************

//const int screenWidth = 640;
//const int screenHeight = 480;
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_SMOOTH);
//}
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glutSolidTeapot(0.5);
//	glFlush();
//}
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//}
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}

//***************BAI TAP 3******************

//#include<math.h>
//#include<iostream>
//
//void initGlut(int argc, char **argv);
//void displayFunc(void);
//void idleFunc(void);
//void reshapeFunc(int width, int height);
//void mouseFunc(int button, int state, int x, int y);
//void mouseMotionFunc(int x, int y);
//void keyboardFunc(unsigned char key, int x, int y);
//void specialFunc(int key, int x, int y);
//
//void countFrames(void);
//void renderBitmapString(float x, float y, float z, void *font, char*string);
//
//bool bUsePredefinedCamera = true;
//bool bFullsreen = false;
//int nWindowID;
//
//float viewerPosition[3] = { 0.0,0.0,-50.0 };
//float viewerDirection[3] = { 0.0,0.0,0.0 };
//float viewerUp[3] = { 0.0,1.0,0.0 };
//
//float navigationRotation[3] = { 0.0,0.0,0.0 };
//
//char pixelstring[30];
//int cframe = 0;
//int time = 0;
//int timebase = 0;
//
//int mousePressedX = 0, mousePressedY = 0;
//float lastXOffset = 0.0, lastYOffset = 0.0, lastZOffset = 0.0;
//int leftMouseButtonActive = 0, middleMouseButtonActive = 0, rightMouseButtonActive = 0;
//int shiftActive = 0, altActive = 0, ctrlActive = 0;
//
//bool init = false;
//
//void displayFunc(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(50.0, 1.00, 1.0, 100000.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	GLfloat lightpos[4] = { 5.0,15.0,10.0,1.0 };
//	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
//
//	glTranslatef(viewerPosition[0], viewerPosition[1], viewerPosition[2]);
//	glRotatef(navigationRotation[0], 1.0f, 0.0f, 0.0f);
//	glRotatef(navigationRotation[1], 0.0f, 1.0f, 0.0f);
//
//	glutSolidTeapot(10.0);
//	countFrames();
//
//	glutSwapBuffers();
//}
//
//void initGlut(int argc, char **argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(100, 100);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//	nWindowID - glutCreateWindow("simpleGLUT");
//
//	glutDisplayFunc(displayFunc);
//	glutReshapeFunc(reshapeFunc);
//	glutKeyboardFunc(keyboardFunc);
//	glutSpecialFunc(specialFunc);
//	glutMouseFunc(mouseFunc);
//	glutMotionFunc(mouseMotionFunc);
//	glutIdleFunc(idleFunc);
//}
//
//void idleFunc(void) {
//	glutPostRedisplay();
//}
//
//void reshapeFunc(int width, int height)
//{
//	glViewport(0, 0, width, height);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(75.0, 1.33, 1.0, 1000.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void mouseFunc(int button, int state, int x, int y) {
//	switch (glutGetModifiers()) {
//		case GLUT_ACTIVE_SHIFT:
//			shiftActive = 1;
//			break;
//		case GLUT_ACTIVE_ALT:
//			altActive = 1;
//			break;
//		case GLUT_ACTIVE_CTRL:
//			ctrlActive = 1;
//			break;
//		default:
//			shiftActive = 0;
//			altActive = 0;
//			ctrlActive = 0;
//			break;
//	}
//	if (button == GLUT_LEFT_BUTTON)
//		if (state == GLUT_DOWN) {
//			leftMouseButtonActive += 1;
//		}
//		else
//		{
//			leftMouseButtonActive -= 1;
//		}
//	else if (button == GLUT_MIDDLE_BUTTON)
//		if (state == GLUT_DOWN) {
//			middleMouseButtonActive += 1;
//			lastXOffset = 0.0;
//			lastYOffset = 0.0;
//		}
//		else
//			middleMouseButtonActive -= 1;
//	else if (button == GLUT_RIGHT_BUTTON)
//		if (state == GLUT_DOWN) {
//			middleMouseButtonActive += 1;
//			lastZOffset = 0.0;
//		}
//		else
//			rightMouseButtonActive -= 1;
//
//	mousePressedX = x;
//	mousePressedY = y;
//}
//
//void mouseMotionFunc(int x, int y) {
//	float xOffset = 0.0, yOffset = 0.0, zOffset = 0.0;
//	if (leftMouseButtonActive) {
//		navigationRotation[0] += ((mousePressedY - y)*180.0f) / 200.0f;
//		navigationRotation[1] += ((mousePressedX - x)*180.0f) / 200.0f;
//		mousePressedY = y;
//		mousePressedX = x;
//	}
//	else if (middleMouseButtonActive) {
//		xOffset = (mousePressedX + x);
//		if (!lastXOffset == 0.0) {
//			viewerPosition[0] -= (xOffset - lastXOffset) / 8.0;
//			viewerDirection[0] -= (xOffset - lastXOffset) / 8.0;
//		}
//		lastXOffset = xOffset;
//
//		yOffset = (mousePressedY + y);
//		if (!lastYOffset == 0.0) {
//			viewerPosition[0] += (yOffset - lastYOffset) / 8.0;
//			viewerDirection[0] += (yOffset - lastYOffset) / 8.0;
//		}
//		lastYOffset = yOffset;
//	}
//	else if (rightMouseButtonActive) {
//		zOffset = (mousePressedX + x);
//		if (!lastZOffset == 0.0) {
//			viewerPosition[0] -= (zOffset - lastZOffset) / 8.0;
//			viewerDirection[0] -= (zOffset - lastZOffset) / 8.0;
//		}
//		lastZOffset = zOffset;
//	}
//}
//
//void keyboardFunc(unsigned char key, int x, int y) {
//	switch (key) {
//#ifdef WIN32
//	case '\033':
//		exit(0);
//		break;
//#endif
//	case'f':
//		bFullsreen = !bFullsreen;
//		if (bFullsreen)
//			glutFullScreen();
//		else
//		{
//			glutSetWindow(nWindowID);
//			glutPositionWindow(100, 100);
//			glutReshapeWindow(640, 480);
//		}
//		break;
//	}
//}
//
//void specialFunc(int key, int x, int y) {
//
//}
//void countFrames(void) {
//	time = glutGet(GLUT_ELAPSED_TIME);
//	cframe++;
//	if (time - timebase > 50) {
//		printf(pixelstring, "fps: %4.2f", cframe*1000.0 / (time - timebase));
//		timebase = time;
//		cframe = 0;
//	}
//	glPushMatrix();
//	glLoadIdentity();
//	glDisable(GL_LIGHTING);
//	glColor4f(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	gluOrtho2D(0, 200, 0, 200);
//	glMatrixMode(GL_MODELVIEW);
//
//	renderBitmapString(5, 5, 0.0, GLUT_BITMAP_HELVETICA_10, pixelstring);
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void renderBitmapString(float x, float y, float z, void *font, char*string)
//{
//	char *c;
//	glRasterPos3f(x, y, z);
//	for (c = string; *c != '\0'; c++) {
//		glutBitmapCharacter(font, *c);
//	}
//}
//
//void main(int argc, char **argv) {
//	printf("simpleGLUT\n\tGordon Wetzstein [gordon.wetzstein@medien.uni-weimar.de]\n\n");
//	printf("key:\n\tf\t-toggle fullscreen\n\tesc\t-exit\n\n");
//	printf("mouse:\n\tleft button\t- rotation\n\tmiddle button\t-panning\n\tright button\t-zoom in and out\n");
//	initGlut(argc, argv);
//	glutMainLoop();
//}

//***************BAI TAP 4******************

void DisplayFunc(void)
{
	static float alpha = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -10);
	glRotatef(30, 1, 0, 0);

	glRotatef(alpha, 0, 1, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1); glVertex3f(-1, -1, 1);
	glColor3f(0, 1, 1); glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0); glVertex3f(-1, 1, -1);

	glColor3f(1, 0, 0); glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1); glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1); glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0); glVertex3f(1, 1, -1);

	glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1); glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1); glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0); glVertex3f(1, -1, -1);

	glColor3f(0, 1, 0); glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1); glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1); glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0); glVertex3f(1, 1, -1);

	glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0); glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0); glVertex3f(1, 1, -1);
	glColor3f(1, 0, 0); glVertex3f(1, -1, -1);

	glColor3f(0, 0, 1); glVertex3f(-1, -1, 1);
	glColor3f(0, 1, 1); glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1); glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1); glVertex3f(1, -1, 1);

	glEnd();

	alpha = alpha + 0.1;
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void ReshapeFunc(int width, int heght)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(20, width / (float)heght, 5, 15);
	glViewport(0, 0, width, heght);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void KeyboardFunc(unsigned char key, int x, int y)
{
	int foo;
	foo = x + y;
	if ('q' == key || 'Q' == key || 27 == key)
		exit(0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Spinning_cube");
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(&DisplayFunc);
	glutReshapeFunc(&ReshapeFunc);
	glutKeyboardFunc(&KeyboardFunc);

	glutMainLoop();

	return 0;
}
