#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
//方向键的ASCLL值:上72，左75，右77，下80
//背景颜色的代码： 0=黑色  1蓝色 2 绿色 3湖蓝色 4红色 5紫色 6黄色 7白色 8灰色 9淡蓝色 
//**改变当前光标方块的背景颜色和字体颜色**//
void BackGround(unsigned int ForeColor = 7, unsigned int BackGroundColor = 0) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //获取控制台的句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//改变当前光标的背景和字体颜色
}
 

void gotoxy(int x, int y) {
	HANDLE handle;
	COORD coord;   
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(handle, coord);  
}
 
/**初始化地图数据**/
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
 //**运动主体**//
void map(int bk[20][20], int look[4], int xy[2], int move[20][20]) {
	//bk是地图信息，look作数据记录，xy记录坐标，move记录蛇的运动轨迹
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
	case 1://往上走
		xy[1]--;
		break;
	case 2://往下走
		xy[1]++;
		break;
	case 3://往左走
		xy[0]--;
		break;
	case 4://往右走
		xy[0]++;
		break;
	}
	move[0][0]++;//蛇的步数加一
	move[xy[0]][xy[1]] = move[0][0];//记录当前格子中蛇的轨迹
	gotoxy(35, 2);
	BackGround(7, 0);
	gotoxy(xy[0] * 2, xy[1]);//这里蛇头就往前移动了
	BackGround(0, 3);
	printf("  ");
 
 //如果吃了果实//
	if (bk[xy[0]][xy[1]] == 2) {
		look[2]++;
		look[1]++;
		gotoxy(35, 0);
		BackGround(7, 0);
		while (bk[pp][qq] != 0) {
			pp = rand() % 15 + 1;
			qq = rand() % 15 + 1;
		}
		bk[pp][qq] = 2;
		gotoxy(pp * 2, qq);
		BackGround(0, 2);
		printf("  ");
	}
 
 //如果撞了墙或者自己//
	if (bk[xy[0]][xy[1]] == 1 || bk[xy[0]][xy[1]] == 3) {
		look[3] = 1;
		gotoxy(6, 6);
		BackGround(7, 0);	}
 
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
