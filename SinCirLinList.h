#ifndef _SINCIRLINLIST_H_
#define _SINCIRLINLIST_H_

/*
----------------单向循环链表----------------
1.Manege *CircularLinkedList_create()      //创建一个空的单向循环链表
2.DataNode *CirculatNewnode(data_t data)   //新建数据节点
3.bool Circulat_IsEmpty(Manege *head)      //判断链表是否为空
4.void insertTailNewnode(Manege *head,data_t data)  //尾插入法
5.void insertHeadNewnode(Manege *head,data_t data)  //头插入法
6.void show(Manege *head)                  //遍历链表中的元素
7.void DeleteNode(Manege *Head,data_t data)//指定元素删除
*/

typedef int data_t;

//数据节点
typedef struct DataNode{

    data_t data;    //存放的数据
    struct DataNode *next;  //指向下一个节点的地址
}DataNode;

//管理节点
typedef struct Manege{

    int num;    //有多少个数据
    DataNode *head; //指向首
    DataNode *tail; //指向尾
}Manege;

//管理节点初始化
Manege *CircularLinkedList_create();

//创建新的节点
DataNode *CirculatNewnode(data_t data);

//判断该单向循环链表中有没有有效节点
bool Circulat_IsEmpty(Manege *head);

//尾部插入新的节点
void insertTailNewnode(Manege *head,data_t data);

//头部插入新的节点
void insertHeadNewnode(Manege *head,data_t data);

//遍历单向循环链表
void show(Manege *head);

//删除指定的节点
void DeleteNode(Manege *Head,data_t data);


#endif