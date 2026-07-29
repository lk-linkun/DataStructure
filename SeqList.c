#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SeqList.h"

SeqList *list_1(int cap)    //创建一个顺序表并初始化
{
    SeqList *list=malloc(sizeof(SeqList));
    if(list!=NULL)
    {
        list->data=malloc(sizeof(Datatype_t)*cap);
        if((list->data)==NULL)
        {
            free(list);
            return NULL;
        }
        list->last=-1;
        list->capacity=cap;
    }
    return list;
}

int list_2(SeqList *list)    //判断顺序表是否已满
{
    if((list->last)+1>=list->capacity)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

SeqList *insertNext(SeqList *list,Datatype_t dat_a)   //尾插入法
{
    if(list_2(list)==0)
    {
        printf("顺序表已满,无法插入!\n");
        return NULL;
    }
    list->last++;
    list->data[list->last]=dat_a;
    return list;
}

SeqList *insertTail(SeqList *list,Datatype_t dat_a)   //头插入法
{
    if(list_2(list)==0)
    {
        printf("顺序表已满,无法插入!\n");
        return NULL;
    }
    for(int i=list->last;i>=0;i--)
    {
        list->data[i+1]=list->data[i];
    }

    list->data[0]=dat_a;
    list->last++;
    return list;
}

bool seqlist_IsEmpty(SeqList *list)  //判断顺序表是否为空
{
    return list->last==-1;
}

bool sealist_DeleteNext(SeqList *list)  //尾部删除
{
    if(seqlist_IsEmpty(list))
    {
        printf("顺序表已空!\n");
        return false;
    }
    list->last--;
    return true;
}

bool sealist_Delete(SeqList *list,Datatype_t data_element)  //指定删除某元素
{
    if(seqlist_IsEmpty(list))
    {
        printf("顺序表已空!\n");
        return false;
    }

    int temp=-1;    //记录所要删除元素的下标
    for(int i=0;i<=list->last;i++)  //循环遍历找到所要删除元素的下标为多少
    {
        if(list->data[i]==data_element)
        {
            temp=i;
            break;
        }
    }

    if(temp==-1)    //判断所找的元素在不在顺序表
    {
        printf("您所要删除的元素不在当前顺序表里!\n");
        return false;
    }

    for(int i=temp;i<list->last;i++)
    {
        list->data[i]=list->data[i+1];
    }
    list->last--;
    return true;
}

void show(SeqList *list) //遍历顺序表的元素
{
    for(int i=0;i<=list->last;i++)
    {
        printf("%d  ",list->data[i]);
    }
    printf("\n");
}