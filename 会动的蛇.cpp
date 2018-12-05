
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

void BackGround(unsigned int ForeColor = 7, unsigned int BackGroundColor = 0) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);
}
 

void gotoxy(int x, int y) {
	HANDLE handle;
	COORD coord;   
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(handle, coord);  
}
 

void restart(int bk[20][20], int look[4], int move[20][20]) {
	int pp, qq;  
	for(int i=0;i<=16;i++)
		for (int j = 0; j <= 16; j++) {
			if (i == 0 || i == 16 || j == 0 || j == 16)  bk[i][j] = 1;
			else bk[i][j] = 0; 
			move[i][j] = 0;    
		}
	bk[8][8] = 3;
	move[8][8] = 1;
	move[0][0] = 1;
	pp = rand() % 15 + 1;
	qq = rand() % 15 + 1;
	bk[pp][qq] = 2;
	look[0] = 1;
	look[1] = 1;
	look[2] = 0;
	look[3] = 0;
	for(int i=0;i<=16;i++)
		for (int j = 0; j <= 16; j++) {
			gotoxy(i * 2, j);
			switch (bk[i][j]) {
			case 0:
				BackGround(0, 0);
				break;
			case 1:
				BackGround(0, 1);
				break;
			case 2:
				break;
			case 3:
				BackGround(0, 3);
				break;
			default:
				break;
			}
			printf("  ");
		}
}
 
void map(int bk[20][20], int look[4], int xy[2], int move[20][20]) {
	int b[10], qq=0, pp=0;
	if (kbhit()) {
		b[0] = getch();
		if (b[0] == 224)  b[0] = getch();
		if (b[0] == 72 && look[0] != 2)
			look[0] = 1;
		if (b[0] == 80 && look[0] != 1)
			look[0] = 2;
		if (b[0] == 75 && look[0] != 4)
			look[0] = 3;
		if (b[0] == 77 && look[0] != 3)
			look[0] = 4;
	}
	switch (look[0]) {
	case 1:
		xy[1]--;
		break;
	case 2:
		xy[1]++;
		break;
	case 3:
		xy[0]--;
		break;
	case 4:
		xy[0]++;
		break;
	}
	move[0][0]++;
	move[xy[0]][xy[1]] = move[0][0];
	gotoxy(35, 2);
	BackGround(7, 0);
	gotoxy(xy[0] * 2, xy[1]);
	BackGround(0, 3);
	printf("  ");
	
	
	if (bk[xy[0]][xy[1]] == 1 || bk[xy[0]][xy[1]] == 3) {
		look[3] = 1;
		gotoxy(6, 6);
		BackGround(7, 0);
	}

bk[xy[0]][xy[1]] = 3;
	for(int i=0;i<=16;i++)
		for (int j = 0; j <= 16; j++) {
			if (move[i][j] == move[xy[0]][xy[1]] - look[1]){
				bk[i][j] = 0;
				gotoxy(i * 2, j);
				BackGround(0, 0);
				printf("  ");
				break;
			}
		}
	end:;
}
int main() {
	int bk[20][20], xy[2], move[20][20], look[4];
	xy[1] = xy[0] = 8;
	srand((unsigned) time(NULL));
	system("pause");
	restart(bk, look, move);
	while (look[3] == 0) {
		Sleep(200);
		map(bk, look, xy, move);
	}
	system("pause");
	return 0;
} 
