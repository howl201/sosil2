#include"DoubleLinkedList.hpp"
#include"Queue.hpp"
#include<iostream>
Queue::Queue(DoubleLinkedList& a)
{
    dl = &a;
    qhead = &dl->getFront();
    qtail = &dl->getBack();
    this->count = a.size();
}
Queue::Queue(Queue &a)
{
    this->dl = a.dl;
    this->qhead = a.qhead;
    this->qtail = a.qtail;
    this->count = a.count;
}
bool Queue::isEmpty()
{
    return count == 0;
}
int Queue::size()
{
    return count;
}
int Queue::front()
{
    if(count == 0)
    {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    else
    {
        return qhead->data;
    }
}
int Queue::back()
{
    if(count == 0)
    {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    else
    {
        return qtail->data;
    }
}
void Queue::push(Node* a)
{
    dl->addBack(a);
    count++;
    qhead = &dl->getFront();
}
void Queue::pop()
{
    if(count == 0)
    {
        std::cout << "This Queue is empty" << std::endl;
        return; 
    }
    dl->removeFront();
    qhead = &dl->getFront();
    count--;
}
void Queue::swap(Queue &a)
{
    DoubleLinkedList* tmp = dl;
    dl = a.getdl();
    a.setdl(tmp);

    qhead = &dl->getFront();
    qtail = &dl->getBack();
    count = a.size();
}
void Queue::setdl(DoubleLinkedList *dl)
{
    this->dl = dl;
    
    qhead = &dl->getFront();
    qtail = &dl->getBack();
    count = dl->size();
}
DoubleLinkedList* Queue::getdl()
{
    return dl;
}
Queue::~Queue()
{

}