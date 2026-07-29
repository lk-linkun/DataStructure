#ifndef _SINLINLIST_H_
#define _SINLINLIST_H_

/*
----------------单向普通链表----------------
1.Manege *headnode()                //创建一个空单向链表管理器
2.DataNode *newnode(data_t Data)    //新建数据节点
3.bool LinkedList_IsEmpty(Manege *Head)  //判断链表是否为空
4.void inserttail(Manege *Head,data_t Data) //尾插入法
5.void inserthead(Manege *Head,data_t Data) //头插入法
6.void show(Manege *Head)            //遍历链表中的元素
7.void delete_node(Manege *Head,data_t Data) //指定元素删除
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
Manege *headnode();

//创建新的节点
DataNode *newnode(data_t Data);

//判断单向链表中是否存在有效节点
bool LinkedList_IsEmpty(Manege *Head);

//尾插法
void inserttail(Manege *Head,data_t Data);

//头插法
void inserthead(Manege *Head,data_t Data);

//遍历链表
void show(Manege *Head);

//删除指定的节点
void delete_node(Manege *Head,data_t Data);


#endif