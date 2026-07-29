#ifndef _SEQLIST_H_
#define _SEQLIST_H_

/*
--------------------顺序表---------------------
1.SeqList *list_1(int cap)                                         //创建一个空顺序表
2.int list_2(SeqList *list)                                        //判断顺序表是否满了
3.SeqList *insertNext(SeqList *list,int dat_a)                     //尾插入法
4.SeqList *insertTail(SeqList *list,int dat_a)                     //头插入法
5.bool seqlist_IsEmpty(SeqList *list)                              //判断顺序表是否为空
6.bool sealist_DeleteNext(SeqList *list)                           //尾部删除法
7.bool sealist_Delete(SeqList *list,Datatype_t data_element)       //指定某元素删除
8.void show(SeqList *list)                                         //遍历顺序表中的元素
*/

typedef int Datatype_t;

typedef struct{

    int capacity;   //顺序表的容量
    int last;   //顺序表的下标
    Datatype_t *data;  //顺序表的首地址

}SeqList;

SeqList *list_1(int cap);    //创建一个顺序表并初始化

int list_2(SeqList *list);    //判断顺序表是否已满

SeqList *insertNext(SeqList *list,Datatype_t dat_a);   //尾插入法

SeqList *insertTail(SeqList *list,Datatype_t dat_a);   //头插入法

bool seqlist_IsEmpty(SeqList *list);  //判断顺序表是否为空

bool sealist_DeleteNext(SeqList *list);  //尾部删除

bool sealist_Delete(SeqList *list,Datatype_t data_element);  //指定删除某元素

void show(SeqList *list); //遍历顺序表的元素


#endif