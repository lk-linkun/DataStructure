#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DLinkList.h"

//管理节点的初始化
Manege *DoubleLinkedList_create()
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

//创建新的数据节点
node *DoubleLinkedList_NewNode(data_t data)
{
    node *Newnode=malloc(sizeof(node));
    if(Newnode==NULL)
    {
        printf("创建新的节点失败了\n");
        return NULL;
    }
    Newnode->data=data;
    Newnode->next=NULL;
    Newnode->prev=NULL;

    return Newnode;
}

//判断该双向链表中有没有有效节点
bool DoubleLinkedList_IsEmpty(Manege *head)
{
    return head->head==NULL;    //没有有效节点
}

//尾部插入新的节点
void DoubleLinkedList_insertTail(Manege *Head,data_t data)
{
    node *newnode=DoubleLinkedList_NewNode(data);   //建立新的节点
    
    //判断有没有有效节点
    if(DoubleLinkedList_IsEmpty(Head))  //无有效节点的情况
    {
        Head->head=newnode;
        Head->tail=newnode;
    }
    else
    {
        Head->tail->next=newnode;
        newnode->prev=Head->tail;
        Head->tail=newnode;
    }

    Head->num++;
}

//头部插入新的节点
void DoubleLinkedList_insertHead(Manege *Head,data_t data)
{
    node *newnode=DoubleLinkedList_NewNode(data);   //建立新的节点
    
    //判断有没有有效节点
    if(DoubleLinkedList_IsEmpty(Head))  //无有效节点的情况
    {
        Head->head=newnode;
        Head->tail=newnode;
    }
    else
    {
        newnode->next=Head->head;
        Head->head->prev=newnode;
        Head->head=newnode;
    }

    Head->num++;
}

//遍历该双向链表的元素
void show(Manege *Head)
{
    node *p=Head->head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//删除指定的节点
void DeleteNode(Manege *Head,data_t data)
{
    node *p=Head->head; //用来保存首地址
    node *temp=NULL;    //标记要删除节点的前驱地址
    //遍历链表找到要删除的前驱下标
    while(p)
    {
        if(p->data==data)
        {
            break;
        }
        temp=p;
        p=p->next;
    }
    //判断该双向链表里有没有要删除的元素
    if(p==NULL)
    {
        printf("该单向循环链表里没有你要删除的元素！\n");
        return;
    }

    //如果要删除的元素在首元素
    if(p==Head->head)
    {
        Head->head=p->next;
        Head->head->prev=NULL;
        p->next=NULL;
        free(p);
    }

    //如果要删除的元素在尾元素
    else if(p==Head->tail)
    {
        Head->tail=temp;
        temp->next=NULL;
        p->prev=NULL;
        free(p);
    }

    //如果要删除的元素在中间
    else
    {
        temp->next=p->next;
        p->next->prev=temp;
        p->next=NULL;
        p->prev=NULL;
        free(p);
    }
    
}
