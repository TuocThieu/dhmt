// Bai1_Lap3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "math.h"

//Hang quy uoc trang thai di chuyen cua tay va chan
const char BACKWARD_STATE = 0;
const char FORWARD_STATE = 1;

//Index quy uoc cho mang (goc xoay cua tay va chan)
const char LEFT = 0;
const char RIGHT = 1;

//Trang thai di chuyen hien tai cua tay va chan (BACKWARD_STATE, FORWARD_STATE)
char legStates[2];
char armStates[2];

//Goc xoay hien tai cua tay va chan
float legAngles[2];
float armAngles[2];

//Goc xoay hien tai cua toan bo robot
float angle;

//Cac huong di chuyen co the
const char MOVE_LEFT = 0;
const char MOVE_RIGHT = 1;
const char MOVE_UP = 3;
const char MOVE_DOWN = 4;

//Goc xoay robot tuong ung khi su dung cac phiem dieu khien
const int TURN_LEFT = -90;
const int TURN_RIGHT = 1;
const int TURN_UP = 180;
const int TURN_DOWN = 0;

const int GROUND_SIZE = 200;	//Kich thuoc cua mat san
const float FLOOR_HEIGHT = -2;	//Do cao cua mat san
const int CHECK_SIZE = 5;	//Kich thuoc cua moi o vuong

int moveDirection;	//Huong di chuyen hien tai
float moveX;	//Vi tri di chuyen den theo truc x
float moveZ;	//Vi tri di chuyen den theo truc z

float theta;	//Goc xoay cua camera (tinhs toa do x va z)
float y;	//Toa do y cua camera
float dTheta;	//Muc tang/giam theta khi dieu khien
float dy;	//Muc tang/giam y khi dieu khien

//Khai bao ham
void DrawCube(float xPos, float yPos, float zPos);
void DrawArm(float xPos, float yPos, float zPos);
void DrawHead(float xPos, float yPos, float zPos);
void DrawTorso(float xPos, float yPos, float zPos);
void DrawLeg(float xPos, float yPos, float zPos);
void DrawRobot(float xPos, float yPos, float zPos);
void Prepare();
void Display();
void Init();
void Reshape(int Width, int Height);
void Idle();
void DrawGroud();
void SettingCamera(float theta, float y);
void Keyboard(unsigned char key, int, int);
void Special(int key, int, int);

//Ham DrawCube de ve hinh lap phuong tai vi tri chi dinh
void DrawCube(float xPos, float yPos, float zPos)
{
	glPushMatrix();	//Luu trang thai bien doi hien tai vao stack
	glTranslatef(xPos, yPos, zPos);
	glBegin(GL_QUADS);
	//Ve mat tren
	glNormal3d(0, 1, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	//Ve mat truoc
	glNormal3d(0, 0, 1);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	//Ve mat ben phai
	glNormal3d(1, 0, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	//Ve mat ben trai
	glNormal3d(-1, 0, 0);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	//Ve mat duoi
	glNormal3d(0, -1, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	//Ve mat sau
	glNormal3d(0, 0, -1);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glEnd();
	glPopMatrix();	//Quay lai trang thai bien doi da luu
}

//Ham DrawArm de ve canh tay (hinh hop chu nhat) tai vi tri chi dinh
void DrawArm(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	//To mau do
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 4.0f, 1.0f);	//Kich thuoc 1x4x1
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

//Ham DrawHead de ve dau (hinh hop chu nhat) tai vi tri chi dinh
void DrawHead(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);	//To mau trang
	glTranslatef(xPos, yPos, zPos);
	glScalef(2.0f, 2.0f, 2.0f);	//Kich thuoc 2x2x2
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

//Ham DrawTorso de ve than (hinh hop chu nhat) tai vi tri chi dinh
void DrawTorso(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);	//To mau lam
	glTranslatef(xPos, yPos, zPos);
	glScalef(3.0f, 5.0f, 2.0f);	//Kich thuoc 3x5x2
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

//Ham DrawLeg de ve chan (hinh hop chu nhat) tai vi tri chi dinh
void DrawLeg(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);	//To mau vang
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 5.0f, 1.0f);	//Kich thuoc 1x5x1
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

//Ham DrawRobot de ve toan bo robot tai vi tri chi dinh
void DrawRobot(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);	//Toa do ve robot

	//Ve phan dau va than
	DrawHead(1.0f, 2.0f, 0.0f);
	DrawTorso(1.5f, 0.0f, 0.0f);

	//Di chuyen canh tay trai va xoay canh tay de tao hieu ung dang buoc di
	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngles[LEFT], 1.0f, 0.0f, 0.0f);
	DrawArm(2.5f, 0.0f, -0.5f);
	glPopMatrix();

	//Di chuyen canh tay phai va xoay canh tay phai de tao hieu dung dang buoc di
	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngles[RIGHT], 1.0f, 0.0f, 0.0f);
	DrawArm(-1.5f, 0.0f, -0.5f);
	glPopMatrix();

	//Di chuyen chan trai va xoay chan de tao hieu ung dang buoc di
	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(legAngles[LEFT], 1.0f, 0.0f, 0.0f);
	DrawLeg(-0.5f, -5.0f, -0.5f);
	glPopMatrix();

	//Di chuyen chan phai va xoay chan de tao hieu ung dang buoc di
	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(legAngles[RIGHT], 1.0f, 0.0f, 0.0f);
	DrawLeg(1.5f, -5.0f, -0.5f);
	glPopMatrix();

	glPopMatrix();
}

//Ham Prepare de tinh toan cac goc xoay cua tay va vhan
void Prepare()
{
	//Neu tay/chan dang di chuyen ve phia truoc thi tang goc xoay, nguoc lai (di chuyen ve phia sau) thi giam goc xoay
	for (char side = 0; side < 2; side++)
	{
		//Goc xoay cho tay
		if (armStates[side] == FORWARD_STATE)
			armAngles[side] += 0.1f;
		else
			armAngles[side] -= 0.1f;

		//Thay doi trang thai neu goc xoay vuot qua gia tri cho phep
		if (armAngles[side] >= 15.0f)
			armStates[side] = BACKWARD_STATE;
		else if (armAngles[side] <= -15.0f)
			armStates[side] = FORWARD_STATE;

		//Goc xoay cho chan
		if (legStates[side] == FORWARD_STATE)
			legAngles[side] += 0.1f;
		else
			legAngles[side] -= 0.1f;

		//Thay doi trang thia neu goc xoay vuot qua gia tri cho phep
		if (legAngles[side] >= 15.0f)
			legStates[side] = BACKWARD_STATE;
		else if (legAngles[side] <= -15.0f)
			legStates[side] = FORWARD_STATE;
	}

	switch (moveDirection)
	{
	case MOVE_LEFT:
		moveX = moveX - 0.015f;	break;
	case MOVE_RIGHT:
		moveX = moveX + 0.015f;	break;
	case MOVE_UP:
		moveZ = moveZ - 0.015f;	break;
	case MOVE_DOWN:
		moveZ = moveZ + 0.015f;	break;
	}
}

//Ham DrawGrond de ve mat san
void DrawGround()
{
	int x, z;
	int counter = 0;

	for (x = -GROUND_SIZE; x < GROUND_SIZE; x += CHECK_SIZE)
	{
		for (z = -GROUND_SIZE; z < GROUND_SIZE; z += CHECK_SIZE)
		{
			if (counter % 2 == 0)
				glColor3f(0.0, 0.0, 0.0);	//To mau xanh
			else
				glColor3f(1.0, 1.0, 1.0);	//To mau trang

			glBegin(GL_QUADS);
			glNormal3d(0, 1, 0);
			glVertex3f(x, FLOOR_HEIGHT, z);
			glVertex3f(x, FLOOR_HEIGHT, z + CHECK_SIZE);
			glVertex3f(x + CHECK_SIZE, FLOOR_HEIGHT, z + CHECK_SIZE);
			glVertex3f(x + CHECK_SIZE, FLOOR_HEIGHT, z);
			glEnd();
			counter++;
		}
		counter++;
	}
}

//Ham SettingCamera de thiet lap camera
void SettingCamera(float theta, float y)
{
	gluLookAt(50 * sin(theta), y, 50 * cos(theta), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

//Ham Keyboard xu ly su kien tu ban phim (thay doi vi tri camera)
void Keyboard(unsigned char key, int, int)
{
	switch (key)
	{
	case 'a': theta -= dTheta;	break;
	case'd': theta += dTheta;	break;
	case 'w': y += dy;	break;
	case 's': if (y > dy)	y -= dy;	break;
	}
	glutPostRedisplay();
}

//Ham Special xu ly cac phim mui ten di chuyen
void Special(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		moveDirection = MOVE_LEFT;
		angle = TURN_LEFT;
		break;
	case GLUT_KEY_RIGHT:
		moveDirection = MOVE_RIGHT;
		angle = TURN_RIGHT;
		break;
	case GLUT_KEY_UP:
		moveDirection = MOVE_UP;
		angle = TURN_UP;
		break;
	case GLUT_KEY_DOWN:
		moveDirection = MOVE_DOWN;
		angle = TURN_DOWN;
		break;
	}
	glutPostRedisplay();
}

//Ham Dislay de dung hinh
void Display()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	//Reset modelview matrix
	SettingCamera(theta, y);

	glPushMatrix();
	glTranslatef(moveX, 8.0f, moveZ);
	//Xoay robot quanh truc y
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	Prepare();
	DrawRobot(0.0f, 0.0f, 0.0f);	//Ve robot
	glPopMatrix();

	glPushMatrix();
	DrawGround();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

//Ham Init de thiet lap anh sang moi truong va khoi tao gia tri mac dinh cho robot
void Init()
{
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Mau anh sang ambient
	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	//Mau anh sang diffuse
	GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//Vi tri nguon sang
	GLfloat lightPos[] = { 25.0f, 25.0f, 25.0f, 0.0f };
	//Huong chieu sang
	GLfloat spotDir[] = { 0.0, 0.0, 0.0, 0.0 };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//Gan gia tri mac dinh ban dau cho robot
	angle = 0.0f;
	armAngles[LEFT] = 0.0;
	armAngles[RIGHT] = 0.0;
	legAngles[LEFT] = 0.0;
	legAngles[RIGHT] = 0.0;
	armStates[LEFT] = FORWARD_STATE;
	armStates[RIGHT] = BACKWARD_STATE;
	legStates[LEFT] = FORWARD_STATE;
	legStates[RIGHT] = BACKWARD_STATE;

	//Gia tri ban dau mac dinh cho camera
	theta = 0.0f;
	y = 0.5f;
	dTheta = 0.04f;
	dy = 1.0f;
}

//Ham Reshape de thiet lap khung nhin, phep chieu va camera
void Reshape(int Width, int Height)
{
	glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)Width / (GLfloat)Height, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

//Ham Idle de yeu cau ve lai man hinh lien tuc
void Idle()
{
	glutPostRedisplay();
}

int _tmain(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Robot_01");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Idle);
	glutSpecialFunc(Special);
	glutKeyboardFunc(Keyboard);
	Init();
	glutMainLoop();

    return 0;
}

