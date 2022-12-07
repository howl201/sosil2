#ifndef __DOUBLELINKEDLIST_HPP__
#define __DOUBLELINKEDLIST_HPP__
struct Node
{
    Node* next;
    Node* prev;
    int data;
};
class DoubleLinkedList
{
private:
    Node* Head;
    Node* Tail;
    int count;
public:
    DoubleLinkedList();
    bool isEmpty();
    void addFront(Node* a);
    void addBack(Node* a);
    void Add(Node* a, int num);
    void removeFront();
    void removeBack();
    Node& getFront();
    Node& getBack();
    int size();
};
#endif