#ifndef _SEQUENTIAL_STACK_H
#define _SEQUENTIAL_STACK_H

/*
----------------顺序栈----------------
1.SStack *SequenceStack_Create(int size)    //创建空的顺序栈
2.void SequenceStack_push(SStack *Pmanege,data_t data)  //入栈
3.data_t SequenceStack_pop(SStack *Pmanege) //出栈
4.void show(SStack *Pmanege)                //遍历栈
*/

typedef int data_t;

typedef struct Sequence_Stack
{
    data_t *bottom; //记录顺序栈的栈底地址
    int top;    //栈顶
    int size;   //顺序表的容量
}SStack;

//创建空的顺序栈
SStack *SequenceStack_Create(int size);

//入栈
void SequenceStack_push(SStack *Pmanege,data_t data);

//出栈
data_t SequenceStack_pop(SStack *Pmanege);

//遍历栈
void show(SStack *Pmanege);


#endif // !_SEQUENTIAL_STACK_H