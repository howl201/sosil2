#ifndef __MEMQUEUE_H__
#define __MEMQUEUE_H__
struct Queue
{
    int front;
    int rear;
    int q[10];
} queue;
typedef queue queue;
void init();
void push(queue q, int a);
int pop(queue q);
int isEmpty();
int isFull();
#endif