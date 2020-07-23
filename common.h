#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;
int dwID;

#define _4PLAYER 10000
#define _3PLAYER 7000
#define _2PLAYER 5000
#define BONUS 500
#define month_money 1000
#define DICE_NUMBER 6		//dice number
#define USER_BUILD 24
#define TRUE 1
#define FALSE 0
#define TURN_MAX 15

#define delay(n)        Sleep(n)                    // n/1000초 시간을 중지
#define randomize()     srand((unsigned)time(NULL)) // 난수 발생기 초기화
#define random(n)       (rand() % (n))              // 0~n까지의 난수 발생
#define clrscr()        system("cls")               // 화면을 모두 지운다.

#define board_wholeW 84
#define board_wholeH 42
#define board_width 12
#define board_height 6

typedef enum cursor_info
{
    NOCURSOR,       // 커서 사라지기
    SOLIDCURSOR,    // 큰 커서
    NORMALCURSOR,   // 일반 커서
}CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c) { //커서 표시의 설정

    CONSOLE_CURSOR_INFO CurInfo;

    switch (c) {

    case NOCURSOR:        //커서없음
        CurInfo.dwSize=1;
        CurInfo.bVisible=FALSE;
        break;

    case SOLIDCURSOR:    //커서가 깜박거리지 않음
        CurInfo.dwSize=100;
        CurInfo.bVisible=TRUE;
        break;

    case NORMALCURSOR:    //일반적인 커서(깜박거림)
        CurInfo.dwSize=20;
        CurInfo.bVisible=TRUE;
        break;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

typedef struct point
{
	int x;
	int y;
}_POINT;

typedef struct player_information{
	char player_name[15];			//사용자이름
	int user_color;					//사용자 말 색깔
	_POINT position;				//말 위치
	int user_money;					//사용자 점수
	int build_count;				//건물 갯수
	int building;					//현재 밟고있는 칸
	int flag;						//말의 상태
	int prison;						//감옥에서 나오는 카운트
	int bankruptcy;					//파산 여부 1이면 파산 0이면 파산이 아님
	int user_build[USER_BUILD];		//사용자가 구입한 건물
	int owner;						//땅 주인 판별
	//int loan; 대출
}USER;

USER user[4];		//구조체 변수 배열 선언

int turn_identy;				//턴 확인 변수
int roll_dice1, roll_dice2;		//첫 번째, 두 번째 주사위 눈금
int dice_sum;					//눈금의 합
int dice_count;					//주사위 던질수 있는 횟수
int people_number;		//player number variable
int winner_owner;

void _system();						//control consol func
void gotoxy(int x, int y);
int wherex();
int wherey();
void menu();						//menu screen f-unc
void explanation();					//explain game func
void intro();						//before game basics information func
void board();
void dice();
void game();

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int wherex()     // 커서의 x 좌표를 조사
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);

	return BufInfo.dwCursorPosition.X;
}

int wherey()     // 커서의 y좌표를 조사
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);

	return BufInfo.dwCursorPosition.Y;
}
