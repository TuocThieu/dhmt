#pragma once
#include "GLOBAL.h"

#define SNAKE_MAXLEN 100	//Chieu dai toi da cua ran
#define SNAKE_INITLEN 2	//Chieu dai ban dau cua ran

typedef struct snake
{
	COORD coords[SNAKE_MAXLEN];	//Ran la mot danh sach cac toa do 2D
	int len;	//Do dai hien thoi cua ran
} SNAKE;

typedef struct fruit
{
	COORD loc;	//Vi tri cua moi
	Uint32 color;	//Mau sac
} FRUIT;

//Ve mot o cua than rang hoac dau ran
void snakeCell(COORD c, SDL_bool head);

//Khoi tao ran
void snakeInit(SNAKE * s);

//Ve ran
void snakeDraw(const SNAKE * s);

//Cap nhat trang thai cua ran
void snakeUpdate(SNAKE * s);

//Phat sinh moi
void fruitGen(FRUIT * f, const SNAKE * s);

//Ve moi
void fruitDraw(const FRUIT * f);
