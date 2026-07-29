#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int data_t;

typedef struct QueueInfo
{
    data_t *head;   //队内堆内存的首地址
    int front;  //队首下标
    int rear;   //队尾下标
    int maxnum; //循环队列的容量
}manege;

//创建空队列
manege *CircularQueue_Create(int size)
{
    manege *Pmanege=malloc(sizeof(manege));
    if(Pmanege==NULL)
    {
        printf("管理节点的创建失败了！\n");
        return NULL;
    }
    Pmanege->head=malloc(size*sizeof(data_t));
    if(Pmanege->head==NULL)
    {
        printf("队列空间创建失败了！\n");
        return NULL;
    }
    Pmanege->maxnum=size;
    Pmanege->front=0;
    Pmanege->rear=0;

    return Pmanege;
}

//入队
void CircularQueue_Enqueue(manege *Pmanege,data_t data)
{
    //判断他是否已经满了
    if((Pmanege->rear+1)%(Pmanege->maxnum) == Pmanege->front)
    {
        printf("该循环队列已满！\n");
        return;
    }
    Pmanege->head[Pmanege->rear]=data;
    Pmanege->rear=(Pmanege->rear+1)%Pmanege->maxnum;
}

//出队
data_t CircularQueue_Dequeue(manege *Pmanege)
{
    data_t temp;    //用来接收返回值

    //先判断该循环队列是否为空
    if(Pmanege->front==Pmanege->rear)
    {
        printf("该循环队列已经空了，无法出队！\n");
        return -1;
    }
    temp=Pmanege->head[Pmanege->front];
    Pmanege->front=(Pmanege->front+1)%Pmanege->maxnum;

    return temp;
}    

//遍历
void show(manege *Pmanege)
{
    // 新增：防止传入空指针
    if(Pmanege == NULL)
    {
        printf("队列指针无效！\n");
        return;
    }
    // 新增：队空提示
    if(Pmanege->front == Pmanege->rear)
    {
        printf("队列为空，没有数据！\n");
        return;
    }

    int cur=Pmanege->front;
    while(cur!=Pmanege->rear)
    {
        printf("%d ",Pmanege->head[cur]);
        cur=(cur+1)%Pmanege->maxnum;
    }
    printf("\n");
}

int main()
{
    manege *Pmanege=CircularQueue_Create(8);
    CircularQueue_Enqueue(Pmanege,10);
    CircularQueue_Enqueue(Pmanege,20);
    CircularQueue_Enqueue(Pmanege,30);
    CircularQueue_Enqueue(Pmanege,40);
    CircularQueue_Enqueue(Pmanege,60);
    CircularQueue_Enqueue(Pmanege,70);
    CircularQueue_Enqueue(Pmanege,80);
    show(Pmanege);
    CircularQueue_Dequeue(Pmanege);
    show(Pmanege);
    CircularQueue_Dequeue(Pmanege);
    show(Pmanege);
}