#ifndef _LINKED_STACK_H
#define _LINKED_STACK_H

/*
----------------链式栈----------------
1.manege *LinkedStack_Create()              //初始化链式栈管理节点，创建空链式栈
2.node *LinkedStack_Newnode(data_t data)    //新建栈数据节点
3.void LinkedStack_Push(manege *Pmanege,data_t data) //入栈
4.data_t LinkedList_Pop(manege *Pmanege)    //出栈
5.void show(manege *Pmanege)                //遍历链式栈
*/

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
manege *LinkedStack_Create();

//创建新的数据节点
node *LinkedStack_Newnode(data_t data);

//入栈
void LinkedStack_Push(manege *Pmanege,data_t data);

//出栈
data_t LinkedList_Pop(manege *Pmanege);

//遍历
void show(manege *Pmanege);


#endif // !_LINKED_STACK_H