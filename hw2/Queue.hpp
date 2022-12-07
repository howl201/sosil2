#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__
#include "DoubleLinkedList.hpp"
class Queue
{
private:
    DoubleLinkedList* dl;
    Node* qhead;
    Node* qtail;
    int count;
public:
    Queue(DoubleLinkedList& a);
    Queue(Queue &a);
    bool isEmpty();
    int size();
    int front();
    int back();
    void push(Node* a);
    void pop();
    void swap(Queue &a);
    void setdl(DoubleLinkedList *a);
    DoubleLinkedList* getdl();
    ~Queue();
};
#endif