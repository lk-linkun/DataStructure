#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SinCirLinList.h"

//管理节点初始化
Manege *CircularLinkedList_create()
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
DataNode *CirculatNewnode(data_t data)
{
    DataNode *Newnode=malloc(sizeof(DataNode));
    if(Newnode==NULL)
    {
        printf("创建新的节点失败了\n");
        return NULL;
    }
    Newnode->data=data;
    Newnode->next=NULL;

    return Newnode;
}

//判断该单向循环链表中有没有有效节点
bool Circulat_IsEmpty(Manege *head)
{
    return head->head==NULL;    //没有有效节点
}

//尾部插入新的节点
void insertTailNewnode(Manege *head,data_t data)
{
    DataNode *newnode=CirculatNewnode(data);    //先建立新的节点

    //判断有没有有效节点
    if(Circulat_IsEmpty(head))  //无有效节点的情况下
    {
        head->head=newnode;
        head->tail=newnode;
        newnode->next=newnode;
    }
    else{
        head->tail->next=newnode;
        head->tail=newnode;
        newnode->next=head->head;
    }

    head->num++;

}

//头部插入新的节点
void insertHeadNewnode(Manege *head,data_t data)
{
    DataNode *newnode=CirculatNewnode(data);    //先建立新的节点
    //判断有没有有效节点
    if(Circulat_IsEmpty(head))  //无有效节点的情况下
    {
        head->head=newnode;
        head->tail=newnode;
        newnode->next=newnode;
    }
    else{
        newnode->next=head->head;
        head->head=newnode;
        head->tail->next=newnode;
    }

    head->num++;
}

//遍历单向循环链表
void show(Manege *head)
{
    DataNode *p=head->head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
        if(p==head->head)
        {
            break;
        }
    }
    printf("\n");
}

//删除指定的节点
void DeleteNode(Manege *Head,data_t data)
{
    DataNode *p=Head->head; //用来保存首地址
    DataNode *temp=NULL;    //标记要删除节点的前驱地址
    //遍历链表找到要删除的前驱下标
    while(p)
    {
        if(p->data==data)
        {
            break;
        }
        temp=p;
        p=p->next;

        //判断该单循环链表里有没有要删除的元素
        if(p==Head->head)
        {
            printf("该单向循环链表里没有你要删除的元素！\n");
            return;
        }
    }

    //如果要删除的元素在首元素
    if(p==Head->head)
    {
        Head->head=p->next;
        Head->tail->next=p->next;
        p->next=NULL;
        free(p);
    }

    //如果要删除的元素在尾元素
    else if(p==Head->tail)
    {
        Head->tail=temp;
        temp->next=Head->head;
        p->next=NULL;
        free(p);
    }

    // 如果要删除的元素在中间
    else{
        temp->next=p->next;
        p->next=NULL;
        free(p);
    }

    Head->num--;
}