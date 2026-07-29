#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

/*
----------------双向链表----------------
1.Manege *DoubleLinkedList_create()        //创建一个空双向链表
2.node *DoubleLinkedList_NewNode(data_t data)  //新建数据节点
3.bool DoubleLinkedList_IsEmpty(Manege *head)  //判断链表是否为空
4.void DoubleLinkedList_insertTail(Manege *Head,data_t data)  //尾插入法
5.void DoubleLinkedList_insertHead(Manege *Head,data_t data)  //头插入法
6.void show(Manege *Head)                  //遍历链表中的元素
7.void DeleteNode(Manege *Head,data_t data)//指定元素删除
*/

typedef int data_t;

typedef struct node
{
    data_t data;    //存放的数据
    struct node *prev;  //指向前驱地址
    struct node *next;  //指向后继地址
}node;

typedef struct Manege
{
    int num;    //节点的数量
    struct node *head;  //首节点地址
    struct node *tail;  //尾节点地址
}Manege;

//管理节点的初始化
Manege *DoubleLinkedList_create();

//创建新的数据节点
node *DoubleLinkedList_NewNode(data_t data);

//判断该双向链表中有没有有效节点
bool DoubleLinkedList_IsEmpty(Manege *head);

//尾部插入新的节点
void DoubleLinkedList_insertTail(Manege *Head,data_t data);

//头部插入新的节点
void DoubleLinkedList_insertHead(Manege *Head,data_t data);

//遍历该双向链表的元素
void show(Manege *Head);

//删除指定的节点
void DeleteNode(Manege *Head,data_t data);


#endif