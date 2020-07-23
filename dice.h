#pragma once

void draw1_f();
void draw2_f();
void draw3_f();
void draw4_f();
void draw5_f();
void draw6_f();
void draw1_s();
void draw2_s();
void draw3_s();
void draw4_s();
void draw5_s();
void draw6_s();

void clear_f();
void clear_s();

int Idobule();

void draw1_f()
{
	gotoxy(96, 15);
	printf("●");
}

void draw2_f()
{
	gotoxy(99, 13);
	printf("●");
	gotoxy(93, 17);
	printf("●");
}

void draw3_f()
{
	gotoxy(99, 13);
	printf("●");
	gotoxy(96, 15);
	printf("●");
	gotoxy(93, 17);
	printf("●");
}
void draw4_f()
{
	gotoxy(93, 13);
	printf("●");
	gotoxy(99, 13);
	printf("●");
	gotoxy(93, 17);
	printf("●");
	gotoxy(99, 17);
	printf("●");
}

void draw5_f()
{
	gotoxy(93, 13);
	printf("●");
	gotoxy(99, 13);
	printf("●");
	gotoxy(96, 15);
	printf("●");
	gotoxy(93, 17);
	printf("●");
	gotoxy(99, 17);
	printf("●");
}

void draw6_f()
{
	gotoxy(93, 13);
	printf("●");
	gotoxy(99, 13);
	printf("●");
	gotoxy(93, 15);
	printf("●");
	gotoxy(99, 15);
	printf("●");
	gotoxy(93, 17);
	printf("●");
	gotoxy(99, 17);
	printf("●");
}

void draw1_s()
{
	gotoxy(111, 15);
	printf("●");
}

void draw2_s()
{
	gotoxy(114, 13);
	printf("●");
	gotoxy(108, 17);
	printf("●");
}

void draw3_s()
{
	gotoxy(114, 13);
	printf("●");
	gotoxy(111, 15);
	printf("●");
	gotoxy(108, 17);
	printf("●");
}

void draw4_s()
{
	gotoxy(108, 13);
	printf("●");
	gotoxy(114, 13);
	printf("●");
	gotoxy(108, 17);
	printf("●");
	gotoxy(114, 17);
	printf("●");
}

void draw5_s()
{
	gotoxy(108, 13);
	printf("●");
	gotoxy(114, 13);
	printf("●");
	gotoxy(111, 15);
	printf("●");
	gotoxy(108, 17);
	printf("●");
	gotoxy(114, 17);
	printf("●");
}

void draw6_s()
{
	gotoxy(108, 13);
	printf("●");
	gotoxy(114, 13);
	printf("●");
	gotoxy(108, 15);
	printf("●");
	gotoxy(114, 15);
	printf("●");
	gotoxy(108, 17);
	printf("●");
	gotoxy(114, 17);
	printf("●");
}

void clear_f()
{
	gotoxy(96, 15);
	printf(" ");
	gotoxy(93, 13);
	printf(" ");
	gotoxy(99, 13);
	printf(" ");
	gotoxy(93, 15);
	printf(" ");
	gotoxy(99, 15);
	printf(" ");
	gotoxy(93, 17);
	printf(" ");
	gotoxy(99, 17);
	printf(" ");
}

void clear_s()
{
	gotoxy(111, 15);
	printf(" ");
	gotoxy(108, 13);
	printf(" ");
	gotoxy(114, 13);
	printf(" ");
	gotoxy(108, 15);
	printf(" ");
	gotoxy(114, 15);
	printf(" ");
	gotoxy(108, 17);
	printf(" ");
	gotoxy(114, 17);
	printf(" ");
}

int Idobule()
{
	if (roll_dice1 == roll_dice2)
		return TRUE;
	else
		return FALSE;
}
