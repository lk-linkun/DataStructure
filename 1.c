#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct Snakenode
{
    int x;  //一节蛇身x坐标
    int y;  //一节蛇身y坐标
    struct Snakenode *next; //指向下一节蛇身
}Snakenode;

Snakenode *head=NULL;   //永远指向蛇头
int foodx,foody;    //食物坐标
int dir=2;  //方向，1上 2右 3下 4左
int score=0;
#define WIDTH 30    //地图高
#define HEIGHT 20   //地图宽

//创建节点
Snakenode *createnode(int x,int y)
{
    Snakenode *p=(Snakenode*)malloc(sizeof(Snakenode));
    p->x=x;
    p->y=y;
    p->next=NULL;
    return p;
}

//初始化蛇
void initsnake()
{
    head=createnode(10,5);
    head->next=createnode(9,5);
    head->next->next=createnode(8,5);
}

//随机食物
void createfood()
{
    foodx=rand()%WIDTH;
    foody=rand()%HEIGHT;
}

//绘制界面
void draw()
{
    //清空控制台
    system("cls");

    for(int i=0;i<WIDTH+2;i++)
    {
        printf("#");
    }
    printf("\n");

    for(int y=0;y<HEIGHT;y++)
    {
        //每行开头打印左侧竖边框#
        printf("#");
        for(int x=0;x<WIDTH;x++)
        {
            int flag=0; //标记，默认当前格子（不是蛇）

            for(Snakenode *p=head;p!=NULL;p=p->next)
            {
                if(p->x==x && p->y==y)
                {
                    printf("o");    //打印蛇身
                    flag=1; //修改标记，这里有蛇
                    break;  //找到就不用继续遍历剩下蛇身
                }
            }
            
            if(flag==0)
            {
                if(x ==foodx && y==foody)
                {
                    printf("F");    //打印食物
                }
                else
                {
                    printf(" ");    //空地打印空格
                }
            }
        }
        printf("#");
        printf("\n");
    }

    
}

int main()
{
    draw();
}