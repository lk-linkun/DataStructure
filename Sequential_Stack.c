#include <stdio.h>
#include <stdlib.h>
#include "Sequential_Stack.h"

//创建空的顺序栈
SStack *SequenceStack_Create(int size)
{
    SStack *Pmanege=malloc(sizeof(SStack));
    if(Pmanege==NULL)
    {
        printf("管理节点的创建失败了!\n");
        return NULL;
    }

    //创建顺序栈
    Pmanege->bottom=malloc(size*sizeof(data_t));
    if(Pmanege->bottom==NULL)
    {
        printf("创建顺序栈失败了！\n");
        return NULL;
    }
    
    Pmanege->size=size;
    Pmanege->top=-1;

    return Pmanege;
}

//入栈
void SequenceStack_push(SStack *Pmanege,data_t data)
{
    //判断栈里还有没有剩余空间
    if((Pmanege->top+1)==Pmanege->size)
    {
        printf("顺序栈里已经满了，无法入栈！\n");
        return;
    }

    Pmanege->top++;
    Pmanege->bottom[Pmanege->top]=data;
}

//出栈
data_t SequenceStack_pop(SStack *Pmanege)
{
    data_t temp;

    //判断栈是否为空
    if(Pmanege->top==-1)
    {
        printf("栈已经空了，无法出栈！\n");
        return 0;
    }

    //把要出栈的元素地址传回去
    temp=Pmanege->bottom[Pmanege->top];
    Pmanege->top--;
    return temp;

}

//遍历栈
void show(SStack *Pmanege)
{
    for(int i=0;i<=Pmanege->top;i++)
    {
        printf("%d ",Pmanege->bottom[i]);
    }
    printf("\n");
}
