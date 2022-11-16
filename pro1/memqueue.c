#include <stdio.h>
#include <ncurses.h>
#include "memqueue.h"

void init(queue *q)
{
    q->front = 0;
    q->rear = 0;
}
int isEmpty(queue q)
{
    if(q->front == q->rear)
        return 1;
    else 
        return 0;
}
int isFull(queue q)
{
    if(((q->rear+1) % 10) == q->front)
        return 1;
    else 
        return 0;
}
void push(queue q, int a)
{
    if(isFull(q))
    {
        printw("queue is full");
        exit(-1);
    }
    q->rear = ((q->rear+1)%10);
    q->queue[q->rear] = a;
}
int pop(queue q)
{
    if(isEmpty(q))
    {
        printw("queue is empty");
        exit(-1);
    }
    q->front = ((q->front+1)%10);
    return q->queue[q->front];
}