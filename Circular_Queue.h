#ifndef _CIRCULAR_QUEUE_H
#define _CIRCULAR_QUEUE_H

/*
----------------循环队列----------------
1.manege *CircularQueue_Create(int size)        //创建空循环队列
2.void CircularQueue_Enqueue(manege *Pmanege,data_t data)  //入队
3.data_t CircularQueue_Dequeue(manege *Pmanege)  //出队
4.void show(manege *Pmanege)                    //遍历循环队列
*/

typedef int data_t;

typedef struct QueueInfo
{
    data_t *head;   //队内堆内存的首地址
    int front;  //队首下标
    int rear;   //队尾下标
    int maxnum; //循环队列的容量
}manege;

//创建空队列
manege *CircularQueue_Create(int size);

//入队
void CircularQueue_Enqueue(manege *Pmanege,data_t data);

//出队
data_t CircularQueue_Dequeue(manege *Pmanege);

//遍历
void show(manege *Pmanege);


#endif // !_CIRCULAR_QUEUE_H