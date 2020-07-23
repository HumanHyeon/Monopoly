#include "common.h"
#include "color_define.h"
#include "keyboard_def.h"
#include "dice.h"
#include "Building.h"
#include "game.h"
#pragma warning (disable : 4996)
#define A 1

void main (void)
{
	_system();
	mciOpen.lpstrElementName = L"모두의마블orchestra.mp3";
	mciOpen.lpstrDeviceType = L"mpegvideo";

	 mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE,
	 (DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
#if A == 1
	menu();
	intro();
#endif
	mciSendCommand(dwID, MCI_CLOSE, 0, NULL);
	board();
	game();
	getchar();
}

void _system()
{
	system("title Monopoly");					//콘솔창 제목 지정
	system("color 0");							//콘솔창 색 지정
	system("mode con: cols=135 lines=43");		//콘솔창 크기 지정
}

void menu()			//메뉴 화면 출력 함수
{
	char menu_choice;	//메뉴 번호 변수
	int cursor_y;

	YELLOW																gotoxy(38,9);
	printf("■■■■■ ■           ■■      ■           ■■ \n");;				gotoxy(38,10);
	printf("■         ■         ■    ■    ■         ■    ■ \n");		gotoxy(38,11);
	printf("■         ■        ■      ■   ■        ■      ■ \n");		gotoxy(38,12);
	printf("■         ■■     ■        ■  ■       ■        ■\n");		gotoxy(38,13);
	printf("■         ■        ■      ■   ■      ■          ■ \n");		gotoxy(38,14);
	printf("■         ■         ■    ■    ■                    \n");	gotoxy(38,15);
	printf("■■■■■ ■           ■■      ■     ■■■■■■■■\n");	
	
	ORIGINAL	gotoxy(39, 27);
	printf("\t\t\t     ☆Monopoly☆");	gotoxy(39, 29);	
	printf("\t\t\t       게임 시작");		gotoxy(39, 30);
	printf("\t\t\t       게임 설명"); 		

	gotoxy(59, 29);		printf("☞");
	setcursortype(NOCURSOR); 
	do
	{
		menu_choice = getch();

		cursor_y = wherey();
		
		if(menu_choice == UP)
		{
			gotoxy(59, cursor_y);	printf(" ");
			gotoxy(59, 29);			printf("☞");
		}
		else if(menu_choice == DOWN)
		{
			gotoxy(59, cursor_y);	printf(" ");
			gotoxy(59, 30);			printf("☞");
		}
	}while(menu_choice != ENTER);

	clrscr();

	if(cursor_y == 30)
		{
			explanation();
		}
}

void explanation()					//사용설명서
{
	char _char;
	char spacebar;
	int cursor_y;

	setcursortype(NOCURSOR);
	mciOpen.lpstrElementName = L"User_In_A01.mp3";
	mciOpen.lpstrDeviceType = L"mpegvideo";

	 mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE,
	 (DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);

	while (1)
	{
		YELLOW	gotoxy(39, 14);
		printf("\t\t\t     ☆게임 설명☆");		gotoxy(39, 18);		ORIGINAL
		printf("\t\t\t        기본 룰");			gotoxy(39, 21);
		printf("\t\t\t        고급 룰");			gotoxy(39, 24);
		printf("\t\t\t       게임 시작");

		gotoxy(60, 18);		printf("☞");
		do
		{
			_char = getch();

			cursor_y = wherey();

			if (_char == UP)
			{
				if (cursor_y == 18 || cursor_y == 21)
				{
					gotoxy(60, cursor_y);	printf(" ");
					gotoxy(60, 18);			printf("☞");
				}
				else if (cursor_y == 24)
				{
					gotoxy(60, cursor_y);	printf(" ");
					gotoxy(60, 21);			printf("☞");
				}
			}
			else if (_char == DOWN)
			{
				if (cursor_y == 18)
				{
					gotoxy(60, cursor_y);	printf(" ");
					gotoxy(60, 21);			printf("☞");
				}
				else if (cursor_y == 21)
				{
					gotoxy(60, cursor_y);	printf(" ");
					gotoxy(60, 24);			printf("☞");
				}
			}
		} while (_char != ENTER);

		clrscr();
		if (cursor_y == 18)
		{
			gotoxy(40, 2);
			printf("안녕하세요! 다이스를 플레이 해주시는 여러분 감사드립니다!");											gotoxy(33, 6);		delay(1500);
			printf("다이스는 monopoly의 게임 형식을 가지고 있는 즉 부루마블 같은 게임입니다.");							gotoxy(28, 10);		delay(1500);
			printf("플레이어의 인원수를 입력을 받고 인원 수에 따라 게임점수가 다르게 지급될 것입니다.");					gotoxy(35, 14);		delay(1500);
			printf("다이스에서는 돈이아니라 점수로 건물을 짓고 점수로 등수 게산을 합니다!");								gotoxy(42, 18);		delay(1500);
			printf("1 PLAYER 부터 N PLAYER까지 순서대로 턴을 가지게 됩니다.");											gotoxy(22, 22);		delay(1500);
			printf("주사위를 굴려 땅에 도착하시면 여러분은 땅에 몇 개의 호텔 개수를 건설하실건지 정하실 수 있습니다.");		gotoxy(27, 26);		delay(1500);
			printf("만약 땅에 자신이 건설한 호텔이 아닌 곳에 도착을 할 시 통행료(점수)를 지불하게 됩니다.");				gotoxy(38, 30);		delay(1500);
			printf("통행료를 지불하지 못할시 자동적으로 파산하게 되니 주의하세요!");										gotoxy(34, 34);		delay(1500);
			printf("총 %d턴으로 %d번째 턴이 마무리 되면 점수가 가장 높은 사람이 승리합니다!", TURN_MAX, TURN_MAX);		gotoxy(56, 38);		delay(1500);
			printf("자 여기까지가 기본 룰입니다!");																	gotoxy(100, 41);
			printf("엔터키를 누르시면 되돌아갑니다!");																	getchar();
		}
		else if (cursor_y == 21)
		{
			gotoxy(5, 5);
			printf("다이스에는 총 4칸의 특수칸("); GRAY printf("START,"); BLOOD printf(" 무인도,"); YELLOW printf(" 비행기,"); HIGH_GREEN printf(" 보너스");  ORIGINAL
			printf(")이 있습니다.");																																	gotoxy(5, 8);		delay(1500);
			GRAY printf("START"); ORIGINAL printf("칸은 출발지로 여러분의 시작 칸입니다.");																			gotoxy(5, 11);		delay(2000);
			printf("여러분은 1, 2, 3, 4라인을 거쳐 이 지점을 지날때마다 소정의 돈이 지급됩니다.");																		gotoxy(5, 14);		delay(2000);
			BLOOD printf("무인도 "); ORIGINAL printf("칸은 들어가게 되면 3턴 동안 주사위를 굴리지 못합니다.");															gotoxy(5, 17);		delay(2000);
			YELLOW printf("비행기 "); ORIGINAL printf("칸에 도착하시면 그 다음턴에 여러분은 어느 칸이든 자유롭게 이동할 수 있습니다.");									gotoxy(5, 20);		delay(2000);
			HIGH_GREEN printf("보너스 ");  ORIGINAL printf("칸은 돈을 추가로 획득할 수 있는 구간으로 도착하시게 되면 주사위를 한번 더 굴릴 수 있습니다.");					gotoxy(5, 23);		delay(2000);
			printf("주사위의 나온 눈금 * %d 만큼의 돈을 얻으실 수 있습니다.", BONUS);																					gotoxy(5, 26);		delay(1500);
			printf("그리고 제일 중요한 룰이 있습니다!");																												gotoxy(5, 29);		delay(1500);
			printf("4번째 라인에서 "); PLUM printf("파산 "); ORIGINAL printf("칸을 주의하세요!");																		gotoxy(5, 32);		delay(2000);
			PLUM printf("파산 "); ORIGINAL printf("칸에 도착시 무조건 그 플레이어는 파산하게 됩니다");																	gotoxy(5, 36);		delay(1500);
			printf("자 여기까지가 고급 룰입니다.");																													gotoxy(100, 41);
			printf("엔터키를 누르시면 되돌아갑니다!");																													getchar();
		}
		else if (cursor_y == 24)
			break;
		clrscr();
	}
	gotoxy(10, 9);
	printf("그럼 본격적으로 게임 하기 전에 주사위 던지는 법을 알려드리겠습니다.");		
	gotoxy(10, 13);		delay(1500);
	printf("주사위는 오른쪽 화면에 나타나있으며 보시다 싶이");				
	printf(" 네모 박스 2개로 되어 있습니다.");											
	gotoxy(90, 10);		delay(1500);
	gotoxy(90, 12);
	printf("┌");
	for (int j = 90 + 1; j < 90 + board_height; j++)
		printf("─");
	gotoxy(90, 12 + board_height);
	printf("└");
	for (int j = 90 + 1; j < 90 + board_height; j++)
		printf("─");
	gotoxy(90 + board_width, 12);
	printf("┐");
	gotoxy(90 + board_width, 12 + board_height);
	printf("┘");
	for (int j = 12 + 1; j < 12 + 6; j++)
	{
		gotoxy(90, j);
		printf("│");
		gotoxy(90 + board_width, j);
		printf("│");
	}
	gotoxy(105, 12);
	printf("┌");
	for (int j = 105 + 1; j < 105 + board_height; j++)
		printf("─");
	gotoxy(105, 12 + board_height);
	printf("└");
	for (int j = 105 + 1; j < 105 + board_height; j++)
		printf("─");
	gotoxy(105 + board_width, 12);
	printf("┐");
	gotoxy(105 + board_width, 12 + board_height);
	printf("┘");
	for (int j = 12 + 1; j < 12 + 6; j++)
	{
		gotoxy(105, j);
		printf("│");
		gotoxy(105 + board_width, j);
		printf("│");
	}
	gotoxy(119, 14);
	printf("두 주사위 합");
	gotoxy(120, 16);
	printf("<        >");
	gotoxy(10, 17);		delay(1500);	YELLOW
	printf("스페이스바를 눌러주세요!");	ORIGINAL
	do
	{
		spacebar = getch();
	} while (spacebar != SPACE);

	dice();

	gotoxy(10, 21);		delay(1500);
	printf("잘하셨습니다. 주사위는 스페이바를 통해 굴릴 수 있습니다.");	
	gotoxy(10, 25);		delay(1500);
	printf("또한 주사위 2개가 같은 숫자가나오면 한번 더 던질 수 있습니다!");
	gotoxy(10, 29);		delay(1500);
	printf("사용법도 다 익혔으니 이제 게임으로 넘어가볼까요?!");

	delay(1000);
	for (int i = 3; i > 0; i--)
	{
		gotoxy(10, 34);
		printf("%d초 후에 게임이 시작됩니다!", i);
		delay(1000);
	}
	clrscr();
}

void intro()					
{
	int put_money;					//player money variable
	int j = 0;

		YELLOW;		gotoxy(53, 12);

		while(1){
			printf("플레이 인원수(2 ~ 4) :    명\b\b\b\b");		scanf_s("%d", &people_number);
			putchar('\n');
			if(people_number > 1 && people_number < 5)		break;
			gotoxy(53, 12 + j);
			j += 2;
		}
		j = 0;
		putchar('\n');	

	GREEN;	
	for(int i = 0; i < people_number; i++)
	{
		gotoxy(52, 16 + j);		
		printf("%d Player 이름 : [            ]\b\b\b\b\b\b\b\b\b\b", i + 1);
		scanf("%s", &user[i].player_name);	fflush(stdin);
		j += 2;
	}

	switch (people_number)				//disburse funds to the player
	{
	case 2:
		put_money = _2PLAYER;
		break;
	case 3:
		put_money = _3PLAYER;
		break;
	case 4:
		put_money = _4PLAYER;
		break;
	default:
		break;
	}

	for(int i = 0; i < people_number; i++)		//인원수에 알맞게 돈 지급
		user[i].user_money = put_money;

	for (int i = 0; i < people_number; i++)		//땅 주인 번호
		user[i].owner = i;

	build();
	
	user[0].user_color = RED;
	user[0].position.x = ORIGINAL_X;
	user[0].position.y = ORIGINAL_Y;
	user[0].build_count = 0;
	user[0].bankruptcy = 0;

	user[1].user_color = YELLOW;
	user[1].position.x = ORIGINAL_X + 2;
	user[1].position.y = ORIGINAL_Y;
	user[1].build_count = 0;
	user[1].bankruptcy = 0;

	user[2].user_color = GREEN;
	user[2].position.x = ORIGINAL_X + (2 * 2);
	user[2].position.y = ORIGINAL_Y;
	user[2].build_count = 0;
	user[2].bankruptcy = 0;

	user[3].user_color = BLUE;
	user[3].position.x = ORIGINAL_X + (2 * 3);
	user[3].position.y = ORIGINAL_Y;
	user[3].build_count = 0;
	user[3].bankruptcy = 0;
	tile();

	clrscr();		ORIGINAL;
}

void board()
{
	int i, j, a = 20, b = 12;

	SKY_BLUE		setcursortype(NOCURSOR);
	gotoxy(0, 0);
	printf("┌");
	gotoxy(0, 42);
	printf("└");
	gotoxy(84, 0);
	printf("┐");
	gotoxy(84, 42);
	printf("┘");
	gotoxy(13, 6);
	printf("┼");

	for (int i = 0 + 2; i < board_wholeW; i += 2)
	{
		if (i % board_width == 0)
		{
			gotoxy(i, 0);
			printf("┬");
			gotoxy(i, 6);
			printf("┴");
			gotoxy(i, 36);
			printf("┬");
			gotoxy(i, 42);
			printf("┴");
		}
		else
		{
			gotoxy(i, 0);
			printf("─");
			gotoxy(i, 6);
			printf("─");
			gotoxy(i, 36);
			printf("─");
			gotoxy(i, 42);
			printf("─");
		}
	}

	for (int i = 0 + 1; i < board_wholeH; i++)
	{
		if (i % board_height == 0)
		{
			gotoxy(0, i);
			printf("├");
		/*	for (int j = 0 + 1; j < board_height; j++)
				printf("─");*/
			gotoxy(12, i);
			printf("┤");
			gotoxy(72, i);
			printf("├");
		/*	for (int j = 0 + 1; j < board_height; j++)
				printf("─");*/
			gotoxy(84, i);
			printf("┤");
		}
		else
		{
			gotoxy(0, i);
			printf("│");
			gotoxy(12, i);
			printf("│");
			gotoxy(72, i);
			printf("│");
			gotoxy(84, i);
			printf("│");
		}
	}

	/*for (int i = 0 + board_width * 2; i < board_wholeW; i += board_width)
	{
		for (int j = 0; j < board_wholeH; j++)
		{
			if (j > 0 && j < board_height)
			{
				gotoxy(i, j);
				printf("│");
			}
			if (j > 36 && j < board_wholeH)
			{
				gotoxy(i, j);
				printf("│");
			}
		}
	}*/

	gotoxy(12, 6);
	printf("┼");
	gotoxy(72, 6);
	printf("┼");
	gotoxy(12, 36);
	printf("┼");
	gotoxy(72, 36);
	printf("┼");
	
	GRAY
	gotoxy(2, 38);
	printf("S T A R T!");
	gotoxy(4, 39);
	printf("→\t→");

	BLOOD
	gotoxy(75, 38);
	printf("무 인 도");

	HIGH_GREEN
	gotoxy(75, 2);
	printf("비 행 기");
	
	YELLOW
	gotoxy(3, 2);
	printf("보 너 스");
	
	SKY_BLUE
	gotoxy(90, 2);
	printf("┌");
	gotoxy(130, 2);
	printf("┐");
	gotoxy(90, 8);
	printf("└");
	gotoxy(130, 8);
	printf("┘");

	gotoxy(102, 1);
	printf("< 플레이어 점수판 >");

	ORIGINAL
	switch (people_number)
	{
	case 2:
		gotoxy(94, 4);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 6);
		printf("%s : ", user[1].player_name);
		break;
	case 3:
		gotoxy(94, 4);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 6);
		printf("%s : ", user[1].player_name);
		gotoxy(113, 4);
		printf("%s : ", user[2].player_name);
		break;
	case 4:
		gotoxy(94, 4);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 6);
		printf("%s : ", user[1].player_name);
		gotoxy(113, 4);
		printf("%s : ", user[2].player_name);
		gotoxy(113, 6);
		printf("%s : ", user[3].player_name);
		break;
	default:
		break;
	}

	gotoxy(90, 12);
	printf("┌");
	for (int j = 90 + 1; j < 90 + board_height; j++)
		printf("─");
	gotoxy(90, 12 + board_height);
	printf("└");
	for (int j = 90 + 1; j < 90 + board_height; j++)
		printf("─");
	gotoxy(90 + board_width, 12);
	printf("┐");
	gotoxy(90 + board_width, 12 + board_height);
	printf("┘");

	for (int j = 12 + 1; j < 12 + 6; j++)
	{
		gotoxy(90, j);
		printf("│");
		gotoxy(90 + board_width, j);
		printf("│");
	}

	gotoxy(105, 12);
	printf("┌");
	for (int j = 105 + 1; j < 105 + board_height; j++)
		printf("─");
	gotoxy(105, 12 + board_height);
	printf("└");
	for (int j = 105 + 1; j < 105 + board_height; j++)
		printf("─");
	gotoxy(105 + board_width, 12);
	printf("┐");
	gotoxy(105 + board_width, 12 + board_height);
	printf("┘");

	for (int j = 12 + 1; j < 12 + 6; j++)
	{
		gotoxy(105, j);
		printf("│");
		gotoxy(105 + board_width, j);
		printf("│");
	}

	gotoxy(119, 14);
	printf("두 주사위 합");
	gotoxy(120, 16);
	printf("<        >");
	
	SKY_BLUE
	gotoxy(102, 22);
	printf("< 플레이어 정보판 >");
	gotoxy(90, 23);
	printf("┌");
	gotoxy(130, 23);
	printf("┐");
	gotoxy(90, 40);
	printf("└");
	gotoxy(130, 40);
	printf("┘");

	for (int i = 23 + 1; i < 40; i++)
	{
		gotoxy(90, i);
		printf("│");
		gotoxy(130, i);
		printf("│");
	}
	ORIGINAL	gotoxy(93, 25);
	printf("ο보유 건물 개수");
	switch (people_number)
	{
	case 2:
		gotoxy(94, 27);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 30);
		printf("%s : ", user[1].player_name);
		break;
	case 3:
		gotoxy(94, 27);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 30);
		printf("%s : ", user[1].player_name);
		gotoxy(112, 27);
		printf("%s : ", user[2].player_name);
		break;
	case 4:
		gotoxy(94, 27);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 30);
		printf("%s : ", user[1].player_name);
		gotoxy(112, 27);
		printf("%s : ", user[2].player_name);
		gotoxy(112, 30);
		printf("%s : ", user[3].player_name);
		break;
	default:
		break;
	}
	gotoxy(93, 33);
	printf("ο남은 무인도 탈출 횟수");
	switch (people_number)
	{
	case 2:
		gotoxy(94, 35);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 38);
		printf("%s : ", user[1].player_name);
		break;
	case 3:
		gotoxy(94, 35);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 38);
		printf("%s : ", user[1].player_name);
		gotoxy(112, 35);
		printf("%s : ", user[2].player_name);
		break;
	case 4:
		gotoxy(94, 35);
		printf("%s : ", user[0].player_name);
		gotoxy(94, 38);
		printf("%s : ", user[1].player_name);
		gotoxy(112, 35);
		printf("%s : ", user[2].player_name);
		gotoxy(112, 38);
		printf("%s : ", user[3].player_name);
		break;
	default:
		break;
	}
	
	YELLOW	gotoxy(37, 9);
	printf("남은 턴 :");
	ORIGINAL

	gotoxy(39, 12);
	printf("님의 차례입니다!");

	for (int i = 1; i < 6; i++)
	{
		gotoxy(2 + (board_width * i), 38);
		printf("%s", building[i].name);
	}
	j = 1;
	for (int i = 18; i > 13; i--)
	{
		gotoxy(3 + (board_width * j), 2);
		j++;
		printf("%s", building[i].name);
	}
	for (int i = 2 + board_height; i < board_wholeH - board_height; i += board_height)
	{
		j = 3;
		gotoxy(j, i);
		printf("%s", building[a].name);
		j = 3 + (board_width * 6);
		gotoxy(j, i);
		printf("%s", building[b].name);
		a++, b--;
	}

	PLUM	gotoxy(4, 26);
	printf("파 산 !");	ORIGINAL

	switch (people_number)
	{
	case 2:
		RED		gotoxy(user[0].position.x, user[0].position.y);
		printf("●");
		YELLOW	gotoxy(user[1].position.x, user[1].position.y);
		printf("●");
		break;
	case 3:
		RED		gotoxy(user[0].position.x, user[0].position.y);
		printf("●");
		YELLOW	gotoxy(user[1].position.x, user[1].position.y);
		printf("●");
		GREEN	gotoxy(user[2].position.x, user[2].position.y);
		printf("●");
		break;
	case 4:
		RED		gotoxy(user[0].position.x, user[0].position.y);
		printf("●");
		YELLOW	gotoxy(user[1].position.x, user[1].position.y);
		printf("●");
		GREEN	gotoxy(user[2].position.x, user[2].position.y);
		printf("●");
		BLUE	gotoxy(user[3].position.x, user[3].position.y);
		printf("●");
		break;
	default:
		break;
		}

	ORIGINAL

	mciOpen.lpstrElementName = L"모마+월드맵+1.mp3";
	mciOpen.lpstrDeviceType = L"mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
}

void dice()
{
	int idouble;
	srand((unsigned int)clock() + (unsigned int)time(NULL));
	setcursortype(NOCURSOR);

	roll_dice1 = random(DICE_NUMBER);		delay(500);
	roll_dice2 = random(DICE_NUMBER);

	dice_sum = roll_dice1 + 1 + roll_dice2 + 1;

	clear_f();
	clear_s();

	gotoxy(125, 16);
	putchar(' ');

	//gotoxy(50, 30);
	//printf("%d %d", roll_dice1, roll_dice2);

	switch (roll_dice1)
	{
	case 0:
		draw1_f();
		break;
	case 1:
		draw2_f();
		break;
	case 2:
		draw3_f();
		break;
	case 3:
		draw4_f();
		break;
	case 4:
		draw5_f();
		break;
	case 5:
		draw6_f();
		break;
	default:
		break;
	}

	switch (roll_dice2)
	{
	case 0:
		draw1_s();
		break;
	case 1:
		draw2_s();
		break;
	case 2:
		draw3_s();
		break;
	case 3:
		draw4_s();
		break;
	case 4:
		draw5_s();
		break;
	case 5:
		draw6_s();
		break;
	default:
		break;
	}
	gotoxy(124, 16);
	printf("%d", dice_sum);

	idouble = Idobule();

	if (idouble == TRUE)
	{
		mciOpen.lpstrElementName = L"Double_A01.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		delay(450);
	}

	switch (dice_sum)
	{
	case 2:
		mciOpen.lpstrElementName = L"DiceNum_A02.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 3:
		mciOpen.lpstrElementName = L"DiceNum_A03.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 4:
		mciOpen.lpstrElementName = L"DiceNum_A04.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 5:
		mciOpen.lpstrElementName = L"DiceNum_A05.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 6:
		mciOpen.lpstrElementName = L"DiceNum_A06.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 7:
		mciOpen.lpstrElementName = L"DiceNum_A07.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 8:
		mciOpen.lpstrElementName = L"DiceNum_A08.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 9:
		mciOpen.lpstrElementName = L"DiceNum_A09.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 10:
		mciOpen.lpstrElementName = L"DiceNum_A10.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 11:
		mciOpen.lpstrElementName = L"DiceNum_A11.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	case 12:
		mciOpen.lpstrElementName = L"DiceNum_A12.mp3";
		mciOpen.lpstrDeviceType = L"mpegvideo";

		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
		break;
	}
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
}

void game()
{	
	int identify = 0;
	int turn = TURN_MAX;
	int game_over = 0;
	char spacebar;
	int ingore_double = 0;

	while (1)
	{
		for (int i = 0; i < people_number; i++)
		{
			identify = ruin(user[i].user_money);

			if (identify == 1){
				user[i].bankruptcy = 1;
				die_clear(i);
				game_over++;
			}
		}

		if (game_over == people_number - 1){				//우승자 확인
			winner_owner = winner_ruin();
			break;
		}
		if (turn == 0){
			winner_owner = winner_turn();
			break;
		}

		gotoxy(47, 9);	printf("  ");
		YELLOW	gotoxy(47, 9);
		printf("%d", turn);
		ORIGINAL

		print_score();
		print_building();
		print_prison();

		for (int i = 0; i < people_number; i++)
		{
			gotoxy(32, 12);
			printf("      ");

			if (user[i].bankruptcy == 1)
				continue;

			if (user[i].prison != 0) {
				user[i].prison--;
				continue;
			}

			gotoxy(32, 12);
			printf("%s", user[i].player_name);
			do
			{
				gotoxy(35, 15);
				printf("주사위를 던지세요!");
				spacebar = getch();
			} while (spacebar != SPACE);

			gotoxy(35, 15);
			printf("                  ");

			dice();	delay(500);	 user[i].flag = move(i);

			if (user[i].flag == 1)		ingore_double = 1;
			if (user[i].flag == 2)		ingore_double = 1;
			if (user[i].flag == 3)		ingore_double = 1;
			if (user[i].flag == 4)		ingore_double = 1;
			if (user[i].flag == 0)		check_build(i);

			if (roll_dice1 == roll_dice2)
			{
				if (ingore_double == 1)	{
					ingore_double = 0;
					break;
				}
				do
				{
					gotoxy(24, 15);
					printf("더블입니다. 주사위를 한번 더 던지세요!");
					spacebar = getch();
				} while (spacebar != SPACE);

				gotoxy(24, 15);
				printf("                                      ");
				dice();	delay(500);	user[i].flag = move(i);
				if (user[i].flag == 1)		g_prosion(i);
				if (user[i].flag == 3)		g_bonus(i);
				if (user[i].flag == 4)		g_ruin(i);
				if (user[i].flag == 0)		check_build(i);
			}
		}
		turn--;
	}
}
