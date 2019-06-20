#pragma once
#include <SDL.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_CELL 16	//Kich thuoc cua 1 o, nen la luy thua cua 2
#define BOARD_HORZ 48	//So luong o theo chieu ngang
#define BOARD_VERT 30	//So luong o theo chieu doc

//18 mau sac co the su dung duoc trong tro choi
#define CR_BLACK 0
#define CR_BLUE 1
#define CR_GREEN 2
#define CR_CYAN 3
#define CR_RED 4
#define CR_MAGENTA 5
#define CR_BROWN 6
#define CR_GRAY 7
#define CR_DKGRAY 8
#define CR_BRBLUE 9
#define CR_BRGREEN 10
#define CR_BRCYAN 11
#define CR_BRRED 12
#define CR_BRMAGENTA 13
#define CR_YELLOW 14
#define CR_WHITE 15
#define CR_SNAKE_HEAD 16
#define CR_SNAKE_BODY 17

//Tong so mau co the su dung, bao gom 16 mau EGA chuan va 2 mau danh cho ran
#define CR_MAX_COLORS 18

//Cac huong di chuyen co the
typedef enum direction { DOWN, LEFT, RIGHT, UP } DIRECTION;

//Cau truc luu tru toa do 2D
typedef struct coord
{
	int x, y;
} COORD;

//Cac bien ngoai bien
extern SDL_Window * g_window;	//SDL Window
extern SDL_Renderer * g_renderer;	//SDL renderer

//Bang gia tri cac mau sac co the su dung duoc
extern unsigned long GAME_PALETTE[CR_MAX_COLORS];

//Thiet lap gia tri mau hien thoi, su dung bang mau da cho
void setColor(int c);

//Ve mot hinh chu nhat
void rectDraw(int x, int y, int w, int h, unsigned long color);
