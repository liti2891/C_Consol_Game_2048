#include <stdio.h>
#include <time.h>

void Start();
void Up();
void Down();
void Left();
void Right();
void Move(int);
void Add();
void Show();
void GameOver();
int Square[4][4];
int Over;
int Score = 0;
int Max = 2;

void Start() {		//開局在2個隨機位置產生2
	int x, y, i=0;
	srand(time(NULL));
	while (1) {
		x = rand() % 4;
		y = rand() % 4;

		if (Square[x][y] == 0) {
			Square[x][y] = 2;
			i++;
		}
		if (i == 2)break;
	}
	Show();
}
void GameOver() {
	int i, j;
	Over = 1;
	for(i=0;i<4;i++)
		for (j = 0; j < 4; j++) {
			if (Square[i][j] == 0)
				Over = 0;
			if (Square[i][j] == Square[i][j + 1])
				Over = 0;
			if (Square[i][j] == Square[i + 1][j])
				Over = 0;
		}
}
void Up() {
	int i, j, k, t;
	int add=0;
	for (t = 0; t < 4; t++) {			//全部向上移動
		for (k = 0; k < 4; k++)			//檢查4次
			for (i = 0; i < 3; i++)			//由上往下檢查
				if (Square[i][t] == 0) {
					if (Square[i][t] == 0 && Square[i + 1][t] != 0)add = 1;
					for (j = i; j < 3; j++) {		//移動
						Square[j][t] = Square[j + 1][t];
						Square[j + 1][t] = 0;
					}
				}
		for (i = 0; i < 3; i++) {		//由上往下檢查相同的合併
			if (Square[i][t] == Square[i + 1][t]) {
				if (Square[i][t] != 0)add = 1;
				Square[i][t] *= 2;
				if (Square[i][t] > Max)Max = Square[i][t];
				Score += Square[i][t];
				for (j = i + 1; j < 3; j++) {
					Square[j][t] = Square[j + 1][t];
					Square[j + 1][t] = 0;
				}
			}
		}
	}
	if (add)Add();		//有動作就添加新的2、4
}
void Down() {		//向下移動
	int i, j, k, t;
	int add = 0;
	for (t = 0; t < 4; t++) {		
		for (k = 0; k < 4; k++)		
			for (i = 3; i > 0; i--)
				if (Square[i][t] == 0) {
					if (Square[i][t] == 0 && Square[i - 1][t] != 0)add = 1;
					for (j = i; j > 0; j--) {
						Square[j][t] = Square[j - 1][t];
						Square[j - 1][t] = 0;
					}
				}
		for (i = 3; i > 0; i--) {		
			if (Square[i][t] == Square[i - 1][t]) {
				if (Square[i][t] != 0)add = 1;
				Square[i][t] *= 2;
				if (Square[i][t] > Max)Max = Square[i][t];
				Score += Square[i][t];
				for (j = i - 1; j > 0; j--) {
					Square[j][t] = Square[j - 1][t];
					Square[j - 1][t] = 0;
				}
			}
		}
	}
	if (add)Add();		
}
void Left() {		//向左移動
	int i, j, k, t;
	int add = 0;
	for (t = 0; t < 4; t++) {			
		for (k = 0; k < 4; k++)			
			for (i = 0; i < 3; i++)			
				if (Square[t][i] == 0) {
					if (Square[t][i] == 0 && Square[t][i + 1] != 0)add = 1;
					for (j = i; j < 3; j++) {		
						Square[t][j] = Square[t][j + 1];
						Square[t][j + 1] = 0;
					}
				}
		for (i = 0; i < 3; i++) {		
			if (Square[t][i] == Square[t][i+1]) {
				if (Square[t][i] != 0)add = 1;
				Square[t][i] *= 2;
				if (Square[t][i] > Max)Max = Square[t][i];
				Score += Square[t][i];
				for (j = i + 1; j < 3; j++) {
					Square[t][j] = Square[t][j + 1];
					Square[t][j + 1] = 0;
				}
			}
		}
	}
	if (add)Add();		
}
void Right() {		//向右移動
	int i, j, k, t;
	int add = 0;
	for (t = 0; t < 4; t++) {			
		for (k = 0; k < 4; k++)			
			for (i = 3; i > 0; i--)			
				if (Square[t][i] == 0) {
					if (Square[t][i] == 0 && Square[t][i - 1] != 0)add = 1;
					for (j = i; j > 0; j--) {		
						Square[t][j] = Square[t][j - 1];
						Square[t][j - 1] = 0;
					}
				}
		for (i = 3; i > 0; i--) {		
			if (Square[t][i] == Square[t][i - 1]) {
				if (Square[t][i] != 0)add = 1;
				Square[t][i] *= 2;
				if (Square[t][i] > Max)Max = Square[t][i];
				Score += Square[t][i];
				for (j = i - 1; j > 0; j--) {
					Square[t][j] = Square[t][j - 1];
					Square[t][j - 1] = 0;
				}
			}
		}
	}
	if (add)Add();		
}
void Move(int Key) {		//讀取移動按鍵
	switch (Key) {
	case 72:
		Up(); break;
	case 80:
		Down(); break;
	case 75:
		Left(); break;
	case 77:
		Right(); break;
	default:
		break;
	}
}
void Add() {			//移動後加入新的2或4積木
	int x, y, n, t = 20;

	srand(time(NULL));
	while (t--) {
		x = rand() % 4;
		y = rand() % 4;
		n = rand() % 5;

		if (Square[x][y] == 0) {
			if (n)
				Square[x][y] = 2;
			else
				Square[x][y] = 4;
			break;
		}
	}
}

void Show() {			//顯示方陣
	int i, j;
		printf("Score:%d \tMaxBox:%d\n｜￣￣￣︱￣￣￣︱￣￣￣︱￣￣￣︱\n",Score,Max);
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (Square[i][j])
				printf("｜%4d\t", Square[i][j]);
			else
				printf("｜    \t");
		}
		printf("｜\n｜＿＿＿︱＿＿＿︱＿＿＿︱＿＿＿︱\n");
		if (i<3) { printf("｜\t｜\t｜\t｜\t｜\n"); }
	}
	if (Over) {
		printf("GameOver!");
	}
}

int main() {
	Start();
	while (1) {
		Move(getch());
		system("CLS");
		GameOver();
		Show();	
	}

	system("pause");
	return 0;
}
