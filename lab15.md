# 智能蛇实验报告

## 任务要求：本次项目的任务是让蛇有一定的智能，能通过算法具有 “感知 - 决策 - 行动” 的能力。近一步，你可以做出华丽的字符界面，实现 人控蛇 与 智能蛇 抢食大战。

---

1. 蛇的身体以及地图的边界是不可接触的格子，相当于障碍物； 
2. 因为贪吃蛇移动是一个动态的过程，所以每走一步，要重新进行寻路； 
3. 吃完食物蛇的长度变长，蛇尾巴位置不变，因此食物跟尾巴之间要留有空隙； 
4. 如果一直跟着尾巴走，就永远不会没有路； 
5. 随机出现的食物位置可能会堵住蛇头部到尾巴的路径，使得头部没有办法找到尾巴，但只要食物与尾巴之间有空隙，吃掉食物是安全的，而且可以重新找到从头部到尾巴的路径。
--------------------- 

智能蛇算法伪代码：
// Hx,Hy: 头de 位置

// Fx,Fy：食物的位置

function whereGoNext(Hx,Hy,Fx,Fy) 

{

    // 用数组movable[3]={“a”,”d”,”w”,”s”} 记录可走的方向

    // 用数组distance[3]={0,0,0,0} 记录离食物的距离

    // 分别计算蛇头周边四个位置到食物的距离。H头的位置，F食物位置

    //     例如：假设输入”a” 则distance[0] = |Fx – (Hx-1)| + |Fy – Hy|

    //           如果 Hx-1，Hy 位置不是Blank，则 distance[0] = 9999

    // 选择distance中存最小距离的下标p，注意最小距离不能是9999

    // 返回 movable[p]

}

## 代码如下：

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<conio.h>

#include<math.h>

#include<windows.h>


#define SNAKE_MAX_LENGTH 20

#define SNAKE_HEAD 'H'

#define SNAKE_BODY 'X'

#define BLANK_CELL ' '

#define SNAKE_FOOD '$'

#define WALL_CELL '*'


//void snakeMove(int,int);

//void put_money(void);

int snakeX[SNAKE_MAX_LENGTH]={5,4,3,2,1};

int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};

int snakeLength=5;

char map[12][13]=

{
   
    "************",
   
    "*XXXXH  $  *",
   
    "*          *",
   
    "*$         *",
   
    "*          *",
   
    "*          *",
   
    "*         $*",
   
    "*          *",
   
    "*          *",
   
    "*   $      *",
   
    "*          *",
   
    "************"

};


void output()

{
   
    int i;
   
    for(i=0;i<12;i++)
   
    {
           
            printf("%s\n",map[i]);
   
    }

}

void gameover()

{

      printf("Game Over!!!");

}

char movable[4]={'W','A','S','D'};//可以走的方向

int distance[4]={0,0,0,0};//可走方向距离食物的距离

char whereGoNext(int Hx,int Hy,int Fx,int Fy)

{

    //判断A方向距离
   
    if(map[Hx-1][Hy]=='X')
   
          distance[0]=9999;//判断是否是身体
   
    else
   
    {
       
        distance[0]=abs(Fx-Hx+1)+abs(Fy-Hy);
   
    }


    //判断W方向有没有食物，食物的距离
   
    if(map[Hx][Hy-1]=='X')
   
    {
       
        distance[1]=9999;
   
    }
   
    else
   
    {
       
        distance[1]=abs(Fx-Hx)+abs(Fy-Hy+1);
   
    }

   
    //判断D方向有没有食物，食物的距离
   
    if(map[Hx+1][Hy]=='X')
   
    {
       
        distance[2]=9999;
    }
   
    else
   
    {
       
        distance[2]=abs(Fx-Hx-1)+abs(Fy-Hy);
   
    }


    //判断S方向有没有食物，食物的距离
   
    if(map[Hx][Hy+1]=='X')
   
    {
       
        distance[3]=9999;
    }
   
    else
   
    {
       
        distance[3]=abs(Fx-Hx)+abs(Fy-Hy-1);
   
    }

    //判断方向和输出
   
    int min=9999;
   
    int i;
   
    for(i=0;i<4;i++)
   
    {
       
        min=(min<distance[i])?min:distance[i];
   
    }
   
    if(min==9999)
       
        return 'Q';
   
    for(i=0;i<4;i++)
   
    {
       
        if(min==distance[i])
           
            break;
   
    }
   
    return movable[i];

}

int main()

{
   
    output();
   
    while(1)
   
    {
   
    int i,j;
   
    int Hx,Hy,Fx,Fy;
   
    for(i=1;i<11;i++)
   
    {
       
        for(j=1;j<11;j++)
       
        {
           
            if(map[i][j]=='H')
           
            {
               
               Hx=i;
               
               Hy=j;
               
               break;
           
            }
       
        }
   
    }

   
    //顺序查找，找到第一个食物
   
    int flag=0;
   
    for(i=1;i<11;i++)
   
    {
       
        if(flag==1)
           
            break;
       
        for(j=1;j<11;j++)
       
        {
           
            if(flag==1)
               
               break;
           
            if(map[i][j]=='$')
           
            {
               
               Fx=i;
               
               Fy=j;
               
               flag=1;
           
            }
       
        }
   
    }

       
       Sleep(1000);//linux下sleep()
       
        char ch;

       
        ch=whereGoNext(Hx,Hy,Fx,Fy);
       

        //如果没有食物就退出，否则陷入死循环
       
        int flag1=0;
       
        for(i=1;i<11;i++)
       
        {
       
        for(j=1;j<11;j++)
       
        {
           
            if(map[i][j]=='$')
           
            {
               
               flag1++;
           
            }
       
        }
       
        }
        if(flag1==0)
       
        {ch='Q';}
       
        if(ch!='A'&&ch!='S'&&ch!='W'&&ch!='D')
           
            break;
       
        map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]=' ';
       
        switch(ch)
       
        {
       
        case 'A':
           
            for(i=snakeLength-1;i>0;i--)
           
            {
               
                snakeX[i]=snakeX[i-1];
               
                snakeY[i]=snakeY[i-1];
           
            }
           
            snakeX[0]--;
           
            break;
       
        case 'D':
           
            for(i=snakeLength-1;i>0;i--)
           
            {
               
                snakeX[i]=snakeX[i-1];
               
                snakeY[i]=snakeY[i-1];
           
            }
           
            snakeX[0]++;
           
            break;
       
        case 'W':
           
            for(i=snakeLength-1;i>0;i--)
           
            {
               
                snakeX[i]=snakeX[i-1];
               
                snakeY[i]=snakeY[i-1];
           
            }
           
            snakeY[0]--;
           
            break;
       
        case 'S':
           
            for(i=snakeLength-1;i>0;i--)
           
            {
               
                snakeX[i]=snakeX[i-1];
               
                snakeY[i]=snakeY[i-1];
           
            }
           
            snakeY[0]++;
           
            break;
       
        }
       
        //判断有没有撞到障碍
       
        if(snakeX[0]<1||snakeX[0]>10||snakeY[0]<1||snakeY[0]>10)
           
            break;
       
        //吃食物长一节
       
        if(map[snakeY[0]][snakeX[0]]=='$')
       
        {
           
            snakeLength++;
           
            if(snakeX[snakeLength-2]==snakeX[snakeLength-3])
           
            {
               
                snakeX[snakeLength-1]=snakeX[snakeLength-2];
               
                snakeY[snakeLength-1]=2*snakeY[snakeLength-2]-snakeY[snakeLength-3];
            }
           
            else
           
            {
               
                snakeY[snakeLength-1]=snakeY[snakeLength-2];
               
                snakeX[snakeLength-1]=2*snakeX[snakeLength-2]-snakeX[snakeLength-3];

            }

        }
       
        for(i=1;i<snakeLength;i++)
       
        {
       
        map[snakeY[i]][snakeX[i]]='X';
       
        }
       
        //判断有没有撞到身体
       
        if(map[snakeY[0]][snakeX[0]]=='X')
           
            break;

        //判断食物，如果遇到食物就长一节身体

        map[snakeY[0]][snakeX[0]]='H';

        output();

    }
   
    gameover();
   
    return 0;
}
