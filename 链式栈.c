#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node
{
    data_t data;    //数据
    struct node *next;  //指向下一个地址
}node;

typedef struct manege
{
    int num;    //记录有多少个节点
    node *top;  //栈顶地址
}manege;

//管理节点的初始化
manege *LinkedStack_Create()
{
    manege *Pmanege=malloc(sizeof(manege));
    if(Pmanege==NULL)
    {
        printf("管理节点的初始化失败了！\n");
        return NULL;
    }
    Pmanege->num=0;
    Pmanege->top=NULL;

    return Pmanege;
}

//创建新的数据节点
node *LinkedStack_Newnode(data_t data)
{
    node *Newnode=malloc(sizeof(node));
    if(Newnode==NULL)
    {
        printf("创建新的数据节点失败了！\n");
        return NULL;
    }
    Newnode->data=data;
    Newnode->next=NULL;

    return Newnode;
}

//入栈
void LinkedStack_Push(manege *Pmanege,data_t data)
{
    //建立新的节点
    node *newnode=LinkedStack_Newnode(data);

    //判断该链式栈有没有有效的节点
    if(Pmanege->top==NULL)  //没有有效节点的情况下
    {
        Pmanege->top=newnode;
    }
    else
    {
        newnode->next=Pmanege->top;
        Pmanege->top=newnode;
    }
    Pmanege->num++;
}

//出栈
data_t LinkedList_Pop(manege *Pmanege)
{
    data_t temp;
    node *p=Pmanege->top;

    //判断还有有效节点没
    if(Pmanege->top==NULL)
    {
        printf("没有有效节点了，无法正常出栈！\n");
        return 0;
    }

    //头删
    else
    {
        temp=p->data;
        Pmanege->top=p->next;
        p->next=NULL;
        free(p);
    }
    Pmanege->num--;

    return temp;
}

//遍历
void show(manege *Pmanege)
{
    for(node *p=Pmanege->top;p!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");
}

int main()
{
    data_t temp;
    manege *Pmanege=LinkedStack_Create();
    LinkedStack_Push(Pmanege,10);
    LinkedStack_Push(Pmanege,20);
    LinkedStack_Push(Pmanege,30);
    LinkedStack_Push(Pmanege,40);
    LinkedStack_Push(Pmanege,50);
    LinkedStack_Push(Pmanege,60);
    LinkedStack_Push(Pmanege,70);
    show(Pmanege);
    temp=LinkedList_Pop(Pmanege);
    show(Pmanege);
}