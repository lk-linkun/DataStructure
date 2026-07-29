#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DCirLinkList.h"

//管理节点的初始化
Manege *DoubleCircularLinkedList_Create()
{
    Manege *Pmanege=malloc(sizeof(Manege));
    if(Pmanege==NULL)
    {
        printf("管理节初始化失败了！\n");
        return NULL;
    }
    Pmanege->head=NULL;
    Pmanege->tail=NULL;
    Pmanege->num=0;

    return Pmanege;
}

//创建新的节点
node *DoubleCircularLinkedList_Newnode(data_t data)
{
    node *Newnode=malloc(sizeof(node));
    if(Newnode==NULL)
    {
        printf("创建新的节点失败了\n");
        return NULL;
    }
    Newnode->data=data;
    Newnode->next=Newnode;
    Newnode->prev=Newnode;

    return Newnode;
}

//判断该双向循环链表里是否有有效的节点
bool DoubleCircularLinkedList_IsEmpty(Manege *Head)
{
    return Head->head==NULL;
}

//尾部插入新的节点
void DoubleCircularLinkedList_insertTail(Manege *Head,data_t data)
{
    node *newnode=DoubleCircularLinkedList_Newnode(data);

    //判断有没有有效节点
    if(DoubleCircularLinkedList_IsEmpty(Head))  //没有有效节点的情况下
    {
        Head->head=newnode;
        Head->tail=newnode;
    }
    else
    {
        Head->tail->next=newnode;
        newnode->prev=Head->tail;
        newnode->next=Head->head;
        Head->head->prev=newnode;
        Head->tail=newnode;
    }

    Head->num++;
}

//头部插入新的节点
void DoubleCircularLinkedList_insertHead(Manege *Head,data_t data)
{
    node *newnode=DoubleCircularLinkedList_Newnode(data);

    //判断有没有有效节点
    if(DoubleCircularLinkedList_IsEmpty(Head))  //没有有效节点的情况下
    {
        Head->head=newnode;
        Head->tail=newnode;
    }
    else
    {
        newnode->next=Head->head;
        Head->head->prev=newnode;
        newnode->prev=Head->tail;
        Head->tail->next=newnode;
        Head->head=newnode;
    }

    Head->num++;
}

//遍历双向循环链表
void show(Manege *Head)
{
    node *p=Head->head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
        if(p==Head->head)
        {
            break;
        }
    }
    printf("\n");
}

//删除指定元素的节点
void DeleteNode(Manege *Head,data_t data)
{
    node *p=Head->head;
    while(p)
    {
        if(p->data==data)
        {
            break;
        }
        p=p->next;
        if(p==Head->head)
        {
            printf("没有你要删除的元素！\n");
            return;
        }
    }

    //情况1：链表只剩下这最后一个节点
    if(Head->num == 1)
    {
        free(p);
        Head->head = NULL;
        Head->tail = NULL;
        Head->num--;
        return;
    }

    //如果要删除的元素是首元素
    if(p==Head->head)
    {
        p->next->prev=Head->tail;
        Head->tail->next=p->next;
        Head->head=p->next;
    }
    //如果要删除的元素是尾元素
    else if(p==Head->tail)
    {
        Head->head->prev=p->prev;
        p->prev->next=Head->head;
        Head->tail=p->prev;
    }
    //要删除的元素在中间
    else
    {
        p->prev->next=p->next;
        p->next->prev=p->prev;
    }

    p->next=NULL;
    p->prev=NULL;
    free(p);
    Head->num--;
}
