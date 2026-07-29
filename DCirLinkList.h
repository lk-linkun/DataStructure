#ifndef _DCIRLINKLIST_H_
#define _DCIRLINKLIST_H_

/*
----------------双向循环链表----------------
1.Manege *DoubleCircularLinkedList_Create()        //创建一个空双向循环链表
2.node *DoubleCircularLinkedList_Newnode(data_t data) //新建数据节点
3.bool DoubleCircularLinkedList_IsEmpty(Manege *Head) //判断链表是否为空
4.void DoubleCircularLinkedList_insertTail(Manege *Head,data_t data) //尾插入法
5.void DoubleCircularLinkedList_insertHead(Manege *Head,data_t data) //头插入法
6.void show(Manege *Head)                          //遍历链表中的元素
7.void DeleteNode(Manege *Head,data_t data)        //指定元素删除
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
Manege *DoubleCircularLinkedList_Create();

//创建新的节点
node *DoubleCircularLinkedList_Newnode(data_t data);

//判断该双向循环链表里是否有有效的节点
bool DoubleCircularLinkedList_IsEmpty(Manege *Head);

//尾部插入新的节点
void DoubleCircularLinkedList_insertTail(Manege *Head,data_t data);

//头部插入新的节点
void DoubleCircularLinkedList_insertHead(Manege *Head,data_t data);

//遍历双向循环链表
void show(Manege *Head);

//删除指定元素的节点
void DeleteNode(Manege *Head,data_t data);


#endif