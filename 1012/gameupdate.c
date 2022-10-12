#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h> 

#pragma comment(lib,"winmm.lib")
#define wave "C:\\wave_file.wav"
double intro_game(char team_name[][7]);
void gotoxy(int x, int y);
void display_line(int rand);
void display_start(char t_name[][7], int s_win[], int s_lose[]);
void display_win(char t_name[][7], int s_win[], int s_lose[]);
void make_decision(int r_start, int s_win[], int s_lose[], char t_name[][7], int* result1, int* result2);
void game_control(int* r_start, clock_t st, double* ps);
int conclusion(char t_name[][7], int* result1, int* result2);
void digital_print(int dim[], int line);
void number_check(int k, int i);


int zero[20] = { 1,1,1,1,

							  1,0,0,1,

							  1,0,0,1,

							  1,0,0,1,

							  1,1,1,1 };

int one[20] = { 0,0,1,0,

						  0,0,1,0,

						  0,0,1,0,

						  0,0,1,0,

						  0,0,1,0 };



int two[20] = { 1,1,1,1,

						  0,0,0,1,

						  1,1,1,1,

						  1,0,0,0,

						  1,1,1,1 };

int three[20] = { 1,1,1,1,

							   0,0,0,1,

							   1,1,1,1,

							   0,0,0,1,

							   1,1,1,1 };

int main(void)
{
	int score_win[2] = { 0 }, score_loose[2] = { 0 }, r_start;
	char team_name[2][7];
	int result1 = 0, result2 = 0;
	double pst, game_time;
	clock_t start;

	srand(time(NULL));
	game_time = intro_game(team_name);

	do
	{
		display_start(team_name, score_win, score_loose);
		r_start = 20;
		start = clock();
		pst = 0;
		do
		{
			game_control(&r_start, start, &pst);
		} while (pst < game_time && ((8 < r_start) && (r_start < 32)));
		make_decision(r_start, score_win, score_loose, team_name, &result1, &result2);
	} while (!conclusion(team_name, &result1, &result2));
	gotoxy(1, 15);
	printf("������ �����մϴ�. \n");
	return 0;
}


/*���ӿ� ���� ����, �����ڿ� ���ѽð��� �Է¹޴� �Լ� intro_game*/
double intro_game(char team_name[][7])
{
	double game_time;
	char key;
	int i;

	PlaySound(TEXT("wave_file.wav"), NULL, SND_ASYNC | SND_LOOP);

	printf("  ����     ��������           ��            �����     �������� \n");
	printf("��      ��         ��               ��  ��          ��     ��          ��\n");
	printf("��                 ��              ��    ��         ��     ��          ��\n");
	printf("  ����           ��             ��      ��        �����           ��\n");
	printf("        ��         ��            �������       ��  ��             ��\n");
	printf("��      ��         ��           ��          ��      ��    ��           ��\n");
	printf("  ����           ��          ��            ��     ��      ��         ��\n");
	_getch();
	system("cls");



	printf("�ٴٸ��� ���� \n\n");
	printf("3�� �ο��� 2�� ���� �̱� ���� �����Դϴ�.\n\n");
	printf("�����ڴ� �� ���Դϴ�. \n");
	for (i = 0;i < 2;i++)
	{
		printf("%d�� �������� �̸��� �Է��ϰ� Enter>", i + 1);
		scanf("%s", &team_name[i]);
	}

	printf("\n");
	printf("�ٴٸ��� ������ ���� �ð�(�� ����)�� �Է��ϰ� Enter>");
	scanf("%lf", &game_time);

	printf("\n");

	printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
	printf("�����Ϸ��� ESC�� ��������.");
	key = _getch();
	if (key == 27)
		exit(0);

	system("cls");

	for (int i = 3; i > 0; i--)
	{
		system("cls");
		printf("\n\n");
		for (int line = 0;line < 5;line++) {
			number_check(i, line);
			printf("\n");
		}
		Sleep(1000);
	}
	system("cls");
	gotoxy(1, 1);
	printf("���ѽð� : %5.1f ��", game_time);
	gotoxy(30, 1);
	printf("����ð� : %4.1f��", 0);

	gotoxy(38, 6);
	printf("������");
	gotoxy(40, 7);
	printf("��");
	gotoxy(40, 9);
	printf("��");
	return game_time;
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void digital_print(int dim[], int line)
{
	int i;
	for (i = line * 4; i <= line * 4 + 3; i++)
	{
		if (dim[i] == 1) {
			printf("��");
		}
		else {
			printf("  ");
		}
	}
	printf(" ");
}
void number_check(int k, int i)
{
	if (k >= 1)
	{
		number_check(k / 4, i);
		switch (k % 4)
		{
		case 0:
			digital_print(zero, i);
			break;
		case 1:
			digital_print(one, i);
			break;
		case 2:
			digital_print(two, i);
			break;
		case 3:
			digital_print(three, i);
			break;
		}
	}
}
/*�ٴٸ��� ���� ����ϴ� �Լ� display_line*/
void display_line(int rnd)
{
	int i, line[21] = { 0 };
	line[10] = 1;
	line[4] = 2;
	line[16] = 2;
	gotoxy(1, 8);
	for (i = 0;i < 78;i++)
		printf(" ");

	gotoxy(rnd, 8);

	for (i = 0;i < 21;i++)
		if (line[i] == 0)
			printf("��");
		else if (line[i] == 1)
			printf("��");
		else
			printf("��");

}

/*�ٴٸ��� ���� ������ �ʱ�ȭ�� ǥ�� �Լ� display_start*/
void display_start(char t_name[][7], int s_win[], int s_lose[])
{
	int i, r_start = 20;
	display_line(20);

	for (i = 0;i < 2;i++)
	{
		gotoxy(i * 55 + 10, 6);
		printf("%s", t_name[i]);
		gotoxy(i * 55 + 10, 7);
		printf("%d��, %d��", s_win[i], s_lose[i]);
	}

	gotoxy(1, 13);
	printf("�ƹ�Ű�� ������ ��⸦ �����մϴ�. ");
	_getch();
	gotoxy(1, 12);
	printf("                                   ");
	gotoxy(1, 13);
	printf("                                   ");
}


void display_win(char t_name[][7], int s_win[], int s_lose[])
{
	for (int i = 0; i < 2;i++)
	{
		gotoxy(i * 55 + 10, 6);
		printf("%s", t_name[i]);
		gotoxy(i * 55 + 10, 7);
		printf("%d�� %d��", s_win[i], s_lose[i]);
	}
}
/*������� ���� �� ��� ����� ����ϴ� �Լ� make_decision*/
void make_decision(int r_start, int s_win[], int s_lose[], char t_name[][7], int* result1, int* result2)
{
	int win;
	if (20 < r_start)
	{
		win = 2;
		s_win[1] += 1;
		s_lose[0] += 1;
		*result2 += 1;
	}
	else if (r_start < 20)
	{
		win = 1;
		s_win[0] += 1;
		s_lose[1] += 1;
		*result1 += 1;
	}
	else
		win = 0;
	gotoxy(1, 12);
	if (win)
		printf("%s���� �̰���ϴ�. ", t_name[win - 1]);
	else
		printf("�����ϴ�,");
	gotoxy(1, 13);
	printf("�ƹ�Ű�� ��������. ");
	_getch();

}

/*�ٴٸ��� ������ �����ϴ� �Լ� game_control*/
void game_control(int* r_s, clock_t st, double* ps)
{
	int rnd, i;
	clock_t end;

	rnd = rand() % 100;
	if (rnd % 2)
		rnd = rnd % 4;
	else
		rnd = -rnd % 4;
	if (rnd < 0)
	{
		for (i = *r_s;i > (*r_s + rnd);i--)  //���� ���ʹ������� �̵�
		{
			display_line(i);
			Sleep(100);
		}
	}
	else
	{
		for (i = *r_s;i < (*r_s + rnd);i++) //���� �����ʹ������� �̵�
		{
			display_line(i);
			Sleep(100);
		}
	}

	//������ �缳��
	if (rnd < 0)
		*r_s = i + 1;
	else
		*r_s = i - 1;

	end = clock();
	*ps = (double)(end - st) / CLK_TCK;
	gotoxy(30, 1);
	printf("����ð� : %4.1f��", *ps);
}

int conclusion(char t_name[][7], int* result1, int* result2)
{
	gotoxy(1, 14);
	if (*result1 == 2)
	{
		printf("%s���� ��������߽��ϴ�", t_name[0]);
		return 1;
	}
	else if (*result2 == 2)
	{
		printf("%s���� ��������߽��ϴ�", t_name[1]);
		return 2;
	}
	return 0;
}
