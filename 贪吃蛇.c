#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

typedef struct SnakeNode
{
    int x;
    int y;
    struct SnakeNode *next;
} SnakeNode;

SnakeNode *head = NULL;
int foodX, foodY;
int dir = 2;   // 1上 2右 3下 4左
int score = 0;
#define WIDTH 30
#define HEIGHT 20

// 创建节点
SnakeNode* createNode(int x, int y)
{
    SnakeNode *p = (SnakeNode*)malloc(sizeof(SnakeNode));
    p->x = x;
    p->y = y;
    p->next = NULL;
    return p;
}

// 初始化蛇，3节身体
void initSnake()
{
    head = createNode(10, 5);
    head->next = createNode(9, 5);
    head->next->next = createNode(8, 5);
}

// 随机生成食物
void createFood()
{
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
}

// 绘制画面
void draw()
{
    system("cls");
    // 上边框
    for(int i = 0; i < WIDTH+2; i++) printf("#");
    printf("\n");

    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            if(x == 0) printf("#");

            int flag = 0;
            SnakeNode *p = head;
            while(p)
            {
                if(p->x == x && p->y == y)
                {
                    printf("O");
                    flag = 1;
                    break;
                }
                p = p->next;
            }
            if(!flag)
            {
                if(x == foodX && y == foodY)
                    printf("F");
                else
                    printf(" ");
            }
            if(x == WIDTH-1) printf("#");
        }
        printf("\n");
    }
    // 下边框
    for(int i = 0; i < WIDTH+2; i++) printf("#");
    printf("\n得分：%d\n", score);
}

// 蛇移动
void move()
{
    int nx = head->x;
    int ny = head->y;
    // 计算新蛇头坐标
    if(dir == 1) ny--;
    if(dir == 2) nx++;
    if(dir == 3) ny++;
    if(dir == 4) nx--;

    // 撞墙判定
    if(nx<0 || nx>=WIDTH || ny<0 || ny>=HEIGHT)
    {
        printf("游戏结束！撞墙\n");
        exit(0);
    }

    // 撞到自己判定
    SnakeNode *p = head;
    while(p)
    {
        if(p->x == nx && p->y == ny)
        {
            printf("游戏结束！撞到自己\n");
            exit(0);
        }
        p = p->next;
    }

    // 新蛇头插入链表头部
    SnakeNode *newHead = createNode(nx, ny);
    newHead->next = head;
    head = newHead;

    // 是否吃到食物
    if(nx == foodX && ny == foodY)
    {
        score += 10;
        createFood();
    }
    else
    {
        // 删除尾部节点
        p = head;
        while(p->next->next != NULL)
            p = p->next;
        free(p->next);
        p->next = NULL;
    }
}

// 按键控制方向
void control()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'w': if(dir != 3) dir = 1; break;
            case 'd': if(dir != 4) dir = 2; break;
            case 's': if(dir != 1) dir = 3; break;
            case 'a': if(dir != 2) dir = 4; break;
            case 'q': exit(0);
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    initSnake();
    createFood();
    while(1)
    {
        draw();
        control();
        move();
        Sleep(120);
    }
    return 0;
}