#include<iostream>
#include "DoubleLinkedList.hpp"
DoubleLinkedList::DoubleLinkedList()
{
    Head = NULL;
    Tail = NULL;
    count = 0;
}
bool DoubleLinkedList::isEmpty()
{
    return count == 0;
}
void DoubleLinkedList::addFront(Node* a)
{
    if(count == 0)
    {
        Head = a;
        Tail = a;
        a->next = NULL;
        a->prev = NULL;
    }
    else
    {
        Head->prev = a;
        a->next = Head;
        Head = a;
        a->prev = NULL;
    }
    count++;
}
void DoubleLinkedList::addBack(Node* a)
{
    if(count == 0)
    {
        Head = a;
        Tail = a;
        a->next = NULL;
        a->prev = NULL;
    }
    else
    {
        Tail->next = a;
        a->prev = Tail;
        Tail = a;
        a->next = NULL;
    }
    count++;
}
void DoubleLinkedList::Add(Node* a, int num)
{
    if(num > this->count)
    {
        printf("count error\n");
        return;
    }
    else
    {
        if(num == 0)
        {
            addFront(a);
        }
        else if(num == count)
        {
            addBack(a);
        }
        else
        {
            Node* target = Head;
            for(int i=0; i<num; i++)
            {
                target = target->next;
            }
            target->prev->next = a;
            a->prev = target->prev;
            target->prev = a;
            a->next = target;
        }
        count++;
    }
}
void DoubleLinkedList::removeFront()
{
    if(count == 0)
    {
        printf("count already empty");
        return;
    }
    else if(count == 1)
    {
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        Head->prev = NULL;
    }
    count--;
}
void DoubleLinkedList::removeBack()
{
    if(count == 0)
    {
        printf("count already empty");
        return;
    }
    else if(count == 1)
    {
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        Tail->next = NULL;
    }
    count--;
}
Node& DoubleLinkedList::getFront()
{
    return *Head;
}
Node& DoubleLinkedList::getBack()
{
    return *Tail;
}
int DoubleLinkedList::size()
{
    return count;
}