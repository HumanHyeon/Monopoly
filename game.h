#pragma once
#define ORIGINAL_X 3
#define ORIGINAL_Y 40
#define ALL_TILE 24

#define PROSION 1;
#define AIRPLANE 2;
#define T_BONUS 3;
#define RUIN 4; 

int ruin(int money);
int winner_ruin();
int winner_turn();
void print_score();
void print_building();
void print_prison();
void tile();
int move(int who);
int w_posit(int i);
void die_clear(int who);
void g_prosion(int who);
void g_airplane(int who);
void g_bonus(int who);
void g_ruin(int who);
void check_build(int who);

int ruin(int money)
{
	if (money < 0)
		return TRUE;
	else if(money >= 0)
		return FALSE;
}

int winner_ruin()
{
	switch (people_number)
	{
	case 2:
		if (user[0].bankruptcy == 0)
			return 0;
		else if (user[1].bankruptcy == 0)
			return 1;
		break;
	case 3:
		if (user[0].bankruptcy == 0)
			return 0;
		else if (user[1].bankruptcy == 0)
			return 1;
		else if (user[2].bankruptcy == 0)
			return 2;
		break;
	case 4:
		if (user[0].bankruptcy == 0)
			return 0;
		else if (user[1].bankruptcy == 0)
			return 1;
		else if (user[2].bankruptcy == 0)
			return 2;
		else if (user[3].bankruptcy == 0)
			return 3;
		break;
	default:
		break;
	}
}

int winner_turn()
{
	int money;
	int winner = 0;

	money = user[0].user_money;

	for (int i = 1; i < people_number; i++)
		if (money < user[i].user_money){
			money = user[i].user_money;
			winner = i;
		}
	return winner;
}

void print_score()
{
	switch (people_number)
	{
	case 2:
		gotoxy(103, 4);
		printf("%d", user[0].user_money);
		gotoxy(103, 6);
		printf("%d", user[1].user_money);
		break;
	case 3:
		gotoxy(103, 4);
		printf("%d", user[0].user_money);
		gotoxy(103, 6);
		printf("%d", user[1].user_money);
		gotoxy(122, 4);
		printf("%d", user[2].user_money);
		break;
	case 4:
		gotoxy(103, 4);
		printf("%d", user[0].user_money);
		gotoxy(103, 6);
		printf("%d", user[1].user_money);
		gotoxy(122, 4);
		printf("%d", user[2].user_money);
		gotoxy(122, 6);
		printf("%d", user[3].user_money);
		break;
	default:
		break;
	}

	if (user[0].bankruptcy == 1) {
		gotoxy(103, 4);
		printf("       ");
		gotoxy(103, 4);	PLUM
		printf("파 산");
	}
	else if (user[1].bankruptcy == 1) {
		gotoxy(103, 6);
		printf("       ");
		gotoxy(103, 6);	PLUM
		printf("파 산");
	}
	else if (user[2].bankruptcy == 1) {
		gotoxy(122, 4);
		printf("       ");
		gotoxy(122, 4);	PLUM
		printf("파 산");
	}
	else if (user[3].bankruptcy == 1) {
		gotoxy(122, 6);
		printf("       ");
		gotoxy(122, 6);	PLUM
		printf("파 산");
	}
	ORIGINAL
}

void print_building()
{
	switch (people_number)
	{
	case 2:
		gotoxy(103, 27);
		printf("%d", user[0].build_count);
		gotoxy(103, 30);
		printf("%d", user[1].build_count);
		break;
	case 3:
		gotoxy(103, 27);
		printf("%d", user[0].build_count);
		gotoxy(103, 30);
		printf("%d", user[1].build_count);
		gotoxy(121, 27);
		printf("%d", user[2].build_count);
		break;
	case 4:
		gotoxy(103, 27);
		printf("%d", user[0].build_count);
		gotoxy(103, 30);
		printf("%d", user[1].build_count);
		gotoxy(121, 27);
		printf("%d", user[2].build_count);
		gotoxy(121, 30);
		printf("%d", user[3].build_count);
		break;
	default:
		break;
	}

	if (user[0].bankruptcy == 1) {
		gotoxy(103, 27);
		printf("       ");
		gotoxy(103, 27);	PLUM
			printf("파 산");
	}
	else if (user[1].bankruptcy == 1) {
		gotoxy(103, 30);
		printf("       ");
		gotoxy(103, 30);	PLUM
			printf("파 산");
	}
	else if (user[2].bankruptcy == 1) {
		gotoxy(122, 27);
		printf("       ");
		gotoxy(122, 27);	PLUM
			printf("파 산");
	}
	else if (user[3].bankruptcy == 1) {
		gotoxy(122, 30);
		printf("       ");
		gotoxy(122, 30);	PLUM
			printf("파 산");
	}
	ORIGINAL
}

void print_prison()
{
	switch (people_number)
	{
	case 2:
		gotoxy(103, 35);
		printf("%d", user[0].prison);
		gotoxy(103, 38);
		printf("%d", user[1].prison);
		break;
	case 3:
		gotoxy(103, 35);
		printf("%d", user[0].prison);
		gotoxy(103, 38);
		printf("%d", user[1].prison);
		gotoxy(121, 35);
		printf("%d", user[2].prison);
		break;
	case 4:
		gotoxy(103, 35);
		printf("%d", user[0].prison);
		gotoxy(103, 38);
		printf("%d", user[1].prison);
		gotoxy(121, 35);
		printf("%d", user[2].prison);
		gotoxy(121, 38);
		printf("%d", user[3].prison);
		break;
	default:
		break;
	}

	if (user[0].bankruptcy == 1) {
		gotoxy(103, 35);
		printf("       ");
		gotoxy(103, 35);	PLUM
			printf("파 산");
	}
	else if (user[1].bankruptcy == 1) {
		gotoxy(103, 38);
		printf("       ");
		gotoxy(103, 38);	PLUM
			printf("파 산");
	}
	else if (user[2].bankruptcy == 1) {
		gotoxy(122, 35);
		printf("       ");
		gotoxy(122, 35);	PLUM
			printf("파 산");
	}
	else if (user[3].bankruptcy == 1) {
		gotoxy(122, 38);
		printf("       ");
		gotoxy(122, 38);	PLUM
			printf("파 산");
	}
	ORIGINAL
}

_POINT user_point[4][ALL_TILE];

void tile()
{
	for (int i = 0; i < 7; i++)		//1라인
	{
		user_point[0][i].x = ORIGINAL_X + (board_width * i);
		user_point[0][i].y = ORIGINAL_Y;

		user_point[1][i].x = (ORIGINAL_X + 2) + (board_width * i);
		user_point[1][i].y = ORIGINAL_Y;

		user_point[2][i].x = (ORIGINAL_X + 4) + (board_width * i);
		user_point[2][i].y = ORIGINAL_Y;

		user_point[3][i].x = (ORIGINAL_X + 6) + (board_width * i);
		user_point[3][i].y = ORIGINAL_Y;
	}
	for (int i = 0; i < 6; i++)		//2라인
	{
		user_point[0][i + 7].x = ORIGINAL_X + (board_width * 6);
		user_point[0][i + 7].y = ORIGINAL_Y - (board_height * (i + 1));

		user_point[1][i + 7].x = (ORIGINAL_X + 2) + (board_width * 6);
		user_point[1][i + 7].y = ORIGINAL_Y - (board_height * (i + 1));

		user_point[2][i + 7].x = (ORIGINAL_X + 4) + (board_width * 6);
		user_point[2][i + 7].y = ORIGINAL_Y - (board_height * (i + 1));

		user_point[3][i + 7].x = (ORIGINAL_X + 6) + (board_width * 6);
		user_point[3][i + 7].y = ORIGINAL_Y - (board_height * (i + 1));
	}
	for (int i = 0; i < 6; i++)		//3라인
	{
		user_point[0][i + 7 + 6].x = ORIGINAL_X + (board_width * 6) - (board_width * (i + 1));
		user_point[0][i + 7 + 6].y = ORIGINAL_Y - (board_height * 6);

		user_point[1][i + 7 + 6].x = (ORIGINAL_X + 2) + (board_width * 6) - (board_width * (i + 1));
		user_point[1][i + 7 + 6].y = ORIGINAL_Y - (board_height * 6);

		user_point[2][i + 7 + 6].x = (ORIGINAL_X + 4) + (board_width * 6) - (board_width * (i + 1));
		user_point[2][i + 7 + 6].y = ORIGINAL_Y - (board_height * 6);

		user_point[3][i + 7 + 6].x = (ORIGINAL_X + 6) + (board_width * 6) - (board_width * (i + 1));
		user_point[3][i + 7 + 6].y = ORIGINAL_Y - (board_height * 6);
	}
	for (int i = 0; i < 5; i++)		//4라인
	{
		user_point[0][i + 7 + 6 + 6].x = ORIGINAL_X;
		user_point[0][i + 7 + 6 + 6].y = ORIGINAL_Y - (board_height * 5) + (board_height * i);

		user_point[1][i + 7 + 6 + 6].x = (ORIGINAL_X + 2);
		user_point[1][i + 7 + 6 + 6].y = ORIGINAL_Y - (board_height * 5) + (board_height * i);

		user_point[2][i + 7 + 6 + 6].x = (ORIGINAL_X + 4);
		user_point[2][i + 7 + 6 + 6].y = ORIGINAL_Y - (board_height * 5) + (board_height * i);

		user_point[3][i + 7 + 6 + 6].x = (ORIGINAL_X + 6);
		user_point[3][i + 7 + 6 + 6].y = ORIGINAL_Y - (board_height * 5) + (board_height * i);
	}
}

int w_posit(int i)
{
	for (int j = 0; j < 24; j++)
	{
		if (user[i].position.x == user_point[0][j].x && user[i].position.y == user_point[0][j].y)
			return j;
		else if (user[i].position.x == user_point[1][j].x && user[i].position.y == user_point[1][j].y)
			return j;
		else if (user[i].position.x == user_point[2][j].x && user[i].position.y == user_point[2][j].y)
			return j;
		else if (user[i].position.x == user_point[3][j].x && user[i].position.y == user_point[3][j].y)
			return j;
	}
}

int move(int who)
{
	int whe;
	int sum = 0;

	whe = w_posit(who);

	if (who == 0)			RED
	else if (who == 1)		YELLOW
	else if (who == 2)		GREEN
	else if (who == 3)		BLUE
	
	for (int i = 0; i < dice_sum; i++)
	{
		sum = whe + i;
		if (sum > 23) {
			sum -= 23;
			gotoxy(user_point[who][23].x, user_point[who][23].y);
			printf("  ");
			gotoxy(user_point[who][sum].x, user_point[who][sum].y);
			printf("●");
			gotoxy(user_point[who][sum - 1].x, user_point[who][sum - 1].y);
			printf(" ");
			delay(500);
		}
		else if (sum < 23) {
			gotoxy(user_point[who][whe + i].x, user_point[who][whe + i].y);
			printf("  ");
			gotoxy(user_point[who][whe + i + 1].x, user_point[who][whe + i + 1].y);
			printf("●");
			delay(500);
		}
	}

	ORIGINAL
	user[who].position.x = user_point[who][whe + dice_sum].x;
	user[who].position.y = user_point[who][whe + dice_sum].y;


	if (user[who].position.x == user_point[who][6].x && user[who].position.y == user_point[who][6].y){
		return PROSION;
	}
	else if (user[who].position.x == user_point[who][12].x && user[who].position.y == user_point[who][12].y){
		return AIRPLANE;
	}
	else if (user[who].position.x == user_point[who][18].x && user[who].position.y == user_point[who][18].y){
		return T_BONUS; 
	}
	else if (user[who].position.x == user_point[who][22].x && user[who].position.y == user_point[who][22].y) {
		return RUIN;
	}
	else {
		return 0;
	}

}

void die_clear(int who)
{
	int posit;

	posit = w_posit(who);

	gotoxy(user_point[who][posit].x, user_point[who][posit].y);
	printf("  ");
}

void g_prosion(int who)
{
	user[who].prison = 3;
}

void g_airplane(int who)
{

}

void g_bonus(int who)
{
	char spacebar;
	gotoxy(14, 15);
	printf("보너스 지점에 도착하셨습니다. 주사위를 한번 더 굴려주세요!");
	do
	{
		spacebar = getch();
	} while (spacebar != SPACE);

	gotoxy(14, 15);
	printf("                                                          ");

	gotoxy(29, 15);
	printf("%d * %d 을 획득하셨습니다!", dice_sum, BONUS);	delay(1500);
	gotoxy(29, 15);
	printf("                             ");

	user[who].user_money += dice_sum * BONUS;
}

void g_ruin(int who)
{
	user[who].bankruptcy = 1;

	if (user[0].bankruptcy == 1) {
		gotoxy(103, 4);
		printf("       ");
		gotoxy(103, 4);	PLUM
			printf("파 산");
	}
	else if (user[1].bankruptcy == 1) {
		gotoxy(103, 6);
		printf("       ");
		gotoxy(103, 6);	PLUM
			printf("파 산");
	}
	else if (user[2].bankruptcy == 1) {
		gotoxy(122, 4);
		printf("       ");
		gotoxy(122, 4);	PLUM
			printf("파 산");
	}
	else if (user[3].bankruptcy == 1) {
		gotoxy(122, 6);
		printf("       ");
		gotoxy(122, 6);	PLUM
			printf("파 산");
	}
	ORIGINAL

	die_clear(who);
}

void check_build(int who)
{
	int whe = w_posit(who);
	char ch1 = 0, ch2 = 0;
	srand(time(NULL));
	int _rand;
	_rand = rand();

	if (building[whe].state == 1)
	{
		user[who].user_money -= building[whe].build_state * building[whe].price * 2;
		gotoxy(18, 17);
		printf("%s 님의 땅을 밞으셔서 %d 의 점수가 차감됩니다.", user[who].player_name, building[whe].build_state * building[whe].price * 2);
		gotoxy(18, 17);
		printf("                                                    ");
	}

	else if (building[whe].state == 0)
	{
		do{
			if (ch1 == '1' || ch1 == '2')
				break;
			gotoxy(35, 21);
			printf("▶INFORMATION!◀");
			gotoxy(32, 23);
			printf("땅을 구입하시겠습니까?");
			gotoxy(34, 24);
			printf("1. 네  2. 아니오");

			ch1 = getch();
		} while (1);

		if (ch1 == '1') {
			building[whe].owner = who;
			building[whe].state = 1;
		}

		gotoxy(35, 21);
		printf("                    ");
		gotoxy(32, 23);
		printf("                       ");
		gotoxy(34, 24);
		printf("                 ");

		do {
			if (ch2 == '1' || ch2 == '2' || ch2 == '3' ||ch2 == '0')
				break;
			gotoxy(35, 21);
			printf("▶INFORMATION!◀");
			gotoxy(25, 23);
			printf("건설할 호텔 개수를 적어주세요!(0 ~ 3)");

			ch2 = getch();
		} while (1);

		gotoxy(35, 21);
		printf("                    ");
		gotoxy(25, 23);
		printf("                                     ");

		if (user[who].user_money >= building[whe].price * ch2)
		{
			int k = 0;
			for (int i = 0; i < ch2; i++)
			{
				switch (who)
				{
				case 0:
					RED
					break;
				case 1:
					YELLOW
					break;
				case 2:
					GREEN
					break;
				case 3:
					BLUE
					break;
					
					gotoxy(user[who].position.x + k, user[who].position.y + 1);
					printf("▲");	
					k += 3;
				
					user[who].user_money -= building[whe].price * ch2;
					user[who].build_count++;
				}	
			}
			
		}

	}
}
