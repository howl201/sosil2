#include<iostream>
#include"DoubleLinkedList.hpp"
#include"Queue.hpp"

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

    dl.addBack(p1);
    dl.addBack(p2);
    dl.addBack(p3);
    dl.addBack(p4);

    Queue q = Queue(dl);
    int size = q.size();
    cout << "Queue1 print: ";
    for(int i=0; i<size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }   
    cout << endl;

    DoubleLinkedList dl2 = DoubleLinkedList();
    Queue q2 = Queue(dl2);
    q2.push(p1);
    q2.push(p2);
    q2.push(p3);
    q2.push(p4);
    int size2 = q2.size();
    cout << "Queue2 print: ";
    for(int i=0; i<size2; i++)
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    q.push(p1);
    q.push(p2);
    q2.push(p3);
    q2.push(p4);

    // q2.push(p4);
    // q2.push(p3);
    // q2.push(p2);
    // q2.push(p1);
    cout << "Queue1: ";
    size = q.size();
    for(int i=0; i<size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }   
    cout << endl;
    cout << "Queue2: ";
    size2 = q2.size();
    for(int i=0; i<size2; i++)
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    cout << "Queue swap" << endl;
    
    q.push(p1);
    q.push(p2);
    q2.push(p3);
    q2.push(p4);

    q.swap(q2);
    size = q.size();
    cout << "Queue1: ";
    for(int i=0; i<size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    } 
    cout << endl;
    size2 = q2.size();
    cout << "Queue2: ";
    for(int i=0; i<size2; i++)
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    return 0;
}