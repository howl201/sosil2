#include<iostream>
#include"DoubleLinkedList.hpp"
using namespace std;
int main()
{
    DoubleLinkedList dl = DoubleLinkedList();
    Node n1;
    n1.data = 1;
    Node* p1 = &n1;
    Node n2;
    n2.data = 2;
    Node* p2 = &n2;
    Node n3;
    n3.data = 3;
    Node* p3 = &n3;
    Node n4;
    n4.data = 4;
    Node* p4 = &n4;

    dl.addFront(p1);
    dl.addFront(p2);
    dl.addFront(p3);
    dl.addFront(p4);

    cout << "addFront: ";
    for(int i=0; i<4; i++)
    {
        printf("%d ", dl.getFront().data);
        dl.removeFront();
    }
    cout << endl;

    dl.addBack(p1);
    dl.addBack(p2);
    dl.addBack(p3);
    dl.addBack(p4);
    cout << "addTail: ";
    for(int i=0; i<4; i++)
    {
        printf("%d ", dl.getBack().data);
        dl.removeBack();
    }
    cout << endl;

    dl.addFront(p1);
    dl.addFront(p2);
    dl.addFront(p3);
    dl.addFront(p4);
    cout << "add middle (0) at (2): ";
    Node add;
    add.data = 0;
    Node* padd = &add;
    dl.Add(padd, 2);    
    for(int i=0; i<5; i++)
    {
        printf("%d ", dl.getFront().data);
        dl.removeFront();
    }
    cout << endl;
    return 0;
}