#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SinLinList.h"

//管理节点初始化
Manege *headnode()
{
    Manege *Head=malloc(sizeof(Manege));
    if(Head==NULL)
    {
        printf("管理结点失败了\n");
        return NULL;
    }
     
    //对管理节点的各个成员进行初始化
    Head->num=0;
    Head->head=NULL;
    Head->tail=NULL;

    return Head;
}

//创建新的节点
DataNode *newnode(data_t Data)
{
    DataNode *new=malloc(sizeof(DataNode));
    if(new==NULL)
    {
        printf("创建新的节点失败了\n");
        return NULL;
    }

    //对新的节点进行初始化
    new->data=Data;
    new->next=NULL;

    return new;
}

//判断单向链表中是否存在有效节点
bool LinkedList_IsEmpty(Manege *Head)
{
    return Head->head==NULL;
}

//尾插法
void inserttail(Manege *Head,data_t Data)
{
    //创建一个新结点的地址
    DataNode *Newnode=newnode(Data);

    //判断单链表里是否有节点
    if(LinkedList_IsEmpty(Head))
    {
        //无节点
        Head->head=Newnode;
        Head->tail=Newnode;
    }
    else{
        Head->tail->next=Newnode;
        Head->tail=Newnode;
    }

    //管理节点里的数据要更新
    Head->num++;
}

//头插法
void inserthead(Manege *Head,data_t Data)
{
    //创建一个新结点的地址
    DataNode *Newnode=newnode(Data);

    //判断单链表里是否有节点
    if(LinkedList_IsEmpty(Head))
    {
        //无节点
        Head->head=Newnode;
        Head->tail=Newnode;
    }
    else{
        Newnode->next=Head->head;
        Head->head=Newnode;
    }

    //管理节点里的数据要更新
    Head->num++;
}

//遍历链表
void show(Manege *Head)
{
    //判断是否为空链表
    if(LinkedList_IsEmpty(Head))
    {
        printf("该链表为空链表\n");
        return;
    }

    for(DataNode *p=Head->head;p!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");
}

//删除指定的节点
void delete_node(Manege *Head,data_t Data)
{
    DataNode *p= NULL;  //保存单链表的首地址
    DataNode *temp=NULL;    //记录要删除节点的前驱地址
    //先遍历这个单链表,找到在哪个位置
    for(p=Head->head;p!=NULL;p=p->next)
    {

        if(p->data==Data)
        {
            break;
        }
        temp=p;
    }

    //判断该单链表里有没有对应删除的元素
    if(p==NULL)
    {
        printf("没有找到要删除的元素,无法删除\n");
        return;
    }

    //如果是在首元素
    if(temp==NULL)
    {
        Head->head=p->next;
        p->next=NULL;
        free(p);
    }

    //如果是在尾元素
    else if(p==Head->tail)
    {
        Head->tail=temp;
        temp->next=NULL;
        free(p);
    }

    //如果是在中间的元素
    else{
        temp->next=p->next;
        p->next=NULL;
        free(p);
    }
}